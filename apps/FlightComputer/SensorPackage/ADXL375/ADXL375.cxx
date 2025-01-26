#include "ADXL375.h"

ADXL375::ADXL375() = default;

bool ADXL375::init(int i2cBus) {
    printf("[ADXL375] Starting sensor...\n");

    // Initialize local fd with i2c driver address
    this->fd = i2cBus;

    // Identify ADXL375 Sensor
    uint8_t dev_id = 0x00;

    busRead(ADXL_ADDR, &dev_id, 1);

    if(dev_id != ADXL_ADDR) {
        printf("[ADXL375] Error: Failed to initialize...\n");

        return false;
    }

    /* ---+ Configure Sensor +--- */

    // Disable interrupts
    busWrite(ADXL_INT_ENABLE, 0);

    return true;

}

/**
 * @name busWrite
 * @param reg - Target Register
 * @param val - Value to write
 * @return
 */
int ADXL375::busWrite(uint8_t reg, uint8_t val) {

    int ex;

    // Allocate memory of tx buffer
    uint8_t txBuffer[2];

    // Fill tx buffer with register and value to send
    txBuffer[0] = reg;
    txBuffer[1] = val;

    // Configure I2C message
    struct i2c_msg_s i2cMsg {
        .frequency = adxl_i2c_freq,
        .addr = ADXL_ADDR,
        .flags = 0,
        .buffer = txBuffer,
        .length = 2
    };

    // Prepare I2C transfer
    struct i2c_transfer_s i2cTransfer {
        .msgv = &i2cMsg,
        .msgc = 1
    };

    // Transfer I2C message to driver and return response code
    ex = ioctl(fd, I2CIOC_TRANSFER, (unsigned long)(uintptr_t) &i2cTransfer);

    // Error if transfer failed
    if(ex < 0) {
        printf("[ADXL375] Error: Failed to set register -> %d\n", ex);
    }

    return ex;
}

int ADXL375::busRead(uint8_t reg, uint8_t *val, int8_t len) {

    int ex;

    // Prepare to configure I2C driver into read mode on selected register
    struct i2c_msg_s i2cMsg[2] = {
            {
                .frequency = adxl_i2c_freq,
                .addr = ADXL_ADDR,
                .flags = 0,
                .buffer = &reg,
                .length = 1
            },
            {
                .frequency = adxl_i2c_freq,
                .addr = ADXL_ADDR,
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
        printf("[ADXL375] Read Error: %d\n", ex);
    }

    return ex;
}

int ADXL375::setOffsets(adxl_offset_t offset) {

    int ex = 0;

    // Set X Offset
    ex &= busWrite(ADXL_OFSX, offset.X);

    // Set Y Offset
    ex &= busWrite(ADXL_OFSY, offset.Y);

    // Set Z Offset
    ex &= busWrite(ADXL_OFSZ, offset.Z);

    return ex;
}

int ADXL375::readSensor() {
    uint8_t rawData[6];

    int ex;

    ex = busRead(ADXL_DATAX0, rawData, 6);

    _accelX = (int16_t)((rawData[1] << 8) | rawData[0]) * adxl_sensitivity_factor;

    _accelY = (int16_t)((rawData[3] << 8) | rawData[2]) * adxl_sensitivity_factor;

    _accelZ = (int16_t)((rawData[5] << 8) | rawData[4]) * adxl_sensitivity_factor;

    return ex;
}

void ADXL375::packData(adxl375_data_t *adxl_data) {

    adxl_data->accel_x = _accelX;
    adxl_data->accel_y = _accelY;
    adxl_data->accel_y = _accelZ;

}