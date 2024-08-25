#include "ICM42688.h"

ICM42688::ICM42688() = default;

bool ICM42688::init(int i2cBus) {
    printf("[ICM42688] Starting sensor...\n");

    this->fd = i2cBus;

    uint8_t dev_id = 0x00;

    // Check whoAmI Register
    busRead(WHO_AM_I, &dev_id, 1);

    if(dev_id != 0x47)
    {
        printf("[ICM42688] Error: Failed to initialize...\n");
        return false;
    }

    enableSensor();
    setFilters();
    setODR();

    switchRegBank(0);

    printf("[ICM42688] Succesfully Initialized!!\n");

    return true;
}

int16_t ICM42688::busWrite(uint8_t reg, uint8_t val) {
    int16_t ex;

    uint8_t txBuffer[2];

    txBuffer[0] = reg;
    txBuffer[1] = val;

    struct i2c_msg_s i2cMsg {
            .frequency = 400000,
            .addr = ICM42688_ADDR,
            .flags = 0,
            .buffer = txBuffer,
            .length = 2
    };

    struct i2c_transfer_s i2cTransfer {
            .msgv = &i2cMsg,
            .msgc = 1
    };

    ex = ioctl(fd, I2CIOC_TRANSFER, (unsigned long)(uintptr_t) &i2cTransfer);

    if(ex < 0) {
        printf("[ICM42688] Error: Failed to set register -> %d\n", ex);
    }

    return ex;
}

int16_t ICM42688::busRead(uint8_t reg, uint8_t *val, int8_t len) {
    int16_t ex;

    struct i2c_msg_s i2cMsg[2] = {
            {
                    .frequency = 400000,
                    .addr = ICM42688_ADDR,
                    .flags = 0,
                    .buffer = &reg,
                    .length = 1
            },
            {
                    .frequency = 400000,
                    .addr = ICM42688_ADDR,
                    .flags = I2C_M_READ,
                    .buffer = val,
                    .length = len
            }
    };

    struct i2c_transfer_s i2cTransfer {
            .msgv = i2cMsg,
            .msgc = 2
    };

    ex = ioctl(fd, I2CIOC_TRANSFER, (unsigned long)(uintptr_t) &i2cTransfer);

    if(ex < 0) {
        printf("[ICM42688] Read Error: %d\n", ex);
    }

    return ex;
}

bool ICM42688::switchRegBank(uint8_t bank)
{

    busWrite(REG_BANK_SEL, bank);

    uint8_t dataRead;

    busRead(REG_BANK_SEL, &dataRead, 1);

    if(dataRead == bank)
    {
        return true;
    }

    return false;

}

void ICM42688::enableSensor()
{
    switchRegBank(0);
    busWrite(PWR_MGMT0, SENSOR_ENABLE);

    usleep(200); // Sleep 200us as per datasheet

}

void ICM42688::setFilters()
{
    uint8_t dataRead = 0;

    switchRegBank(2);
    busRead(ACCEL_CONFIG_STATIC2, &dataRead, 1);

    dataRead &= ~(0x3F << 1); // Clear 6:1 bits of the register
    dataRead |= (ACCEL_AAF_DELT << 1);
    dataRead |= 0x01;

    busWrite(ACCEL_CONFIG_STATIC2, dataRead);
    busWrite(ACCEL_CONFIG_STATIC3, ACCEL_AAF_DELTSQR);
    busWrite(ACCEL_CONFIG_STATIC4, (ACCEL_AAF_BITSHIFT << 4));

    dataRead = 0;
    switchRegBank(1);
    busRead(GYRO_CONFIG_STATIC2, &dataRead, 1);

    busWrite(GYRO_CONFIG_STATIC2, dataRead | 0x03);

    busRead(GYRO_CONFIG_STATIC3, &dataRead, 1);

    dataRead &= ~(0x3F);
    dataRead |= GYRO_AAF_DELT;

    busWrite(GYRO_CONFIG_STATIC3, dataRead);

    busWrite(GYRO_CONFIG_STATIC4, GYRO_AAF_DELTSQR);

    busWrite(GYRO_CONFIG_STATIC5, (GYRO_AAF_BITSHIFT << 4));

}

void ICM42688::setODR()
{

    switchRegBank(0);
    busWrite(ACCEL_CONFIG0, ACCEL_ODR | ACCEL_FS_SEL);

    busWrite(GYRO_CONFIG0, GYRO_ODR | GYRO_FS_SEL);
}

void ICM42688::getImuData(imu_data_t& imuData)
{
    uint8_t rawData[12];

    busRead(ACCEL_DATA_X1, rawData, 12);

    imuData.accel_x = static_cast<int16_t>((rawData[0] << 8) | rawData[1]) / accelRes;
    imuData.accel_y = static_cast<int16_t>((rawData[2] << 8) | rawData[3]) / accelRes;
    imuData.accel_z = static_cast<int16_t>((rawData[4] << 8) | rawData[5]) / accelRes;

    imuData.gyro_x = static_cast<int16_t>((rawData[6] << 8) | rawData[7]) / accelRes;
    imuData.gyro_y = static_cast<int16_t>((rawData[8] << 8) | rawData[9]) / accelRes;
    imuData.gyro_z = static_cast<int16_t>((rawData[10] << 8) | rawData[11]) / accelRes;
}

