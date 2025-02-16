#include "LPS22.h"

LPS22::LPS22() = default;

bool LPS22::init(int i2cBus) {
    this->fd = i2cBus;

    uint8_t dev_id = 0x00;

    busRead(LPS22_WHOAMI, &dev_id, 1);

    if(dev_id == LPS22_WHO_ID) {
        printf("[LPS22] Successfully Initialized!\n");
    } else {
        printf("[LPS22] Error: Failed to initialize...\n");

        return false;
    }

    uint8_t powerupData;

    busRead(CTRL_REG1, &powerupData, 1);

    /* ---+ Configure Sensor +--- */

    // Configure Register 1
    uint8_t ODR_CFG = static_cast<uint8_t>(_odr);
    uint8_t EN_LPF = 0b0;
    uint8_t LPFP_CF = 0b0;
    uint8_t BDU = 0b0;
    uint8_t SIM = 0b0;

    uint8_t ctrl_reg_1 = (ODR_CFG << 6) | (EN_LPF << 3) | (LPFP_CF << 2) | (BDU << 1) | SIM;

    busWrite(CTRL_REG1, ctrl_reg_1);

    return true;
}

void LPS22::setODR(LPS22_ODR odr) {
    _odr = odr;
}


int16_t LPS22::busWrite(uint8_t reg, uint8_t val) {
    int16_t ex;

    uint8_t txBuffer[2];

    txBuffer[0] = reg;
    txBuffer[1] = val;

    struct i2c_msg_s i2cMsg {
        .frequency = 400000,
        .addr = LPS22_ADDR,
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
        printf("[LPS22] Error: Failed to set register -> %d\n", ex);
    }

    return ex;
}

int16_t LPS22::busRead(uint8_t reg, uint8_t *val, int8_t len) {
    int16_t ex;

    struct i2c_msg_s i2cMsg[2] = {
            {
                .frequency = 400000,
                .addr = LPS22_ADDR,
                .flags = 0,
                .buffer = &reg,
                .length = 1
            },
            {
                .frequency = 400000,
                .addr = LPS22_ADDR,
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
        printf("[LPS22] Read Error: %d\n", ex);
    }

    return ex;
}

float LPS22::getPressure() {

    uint8_t dataRead = 0x00;

    int32_t pData = 0;

    // Check status register to see if pressure data is available
    busRead(PRESSURE_H_REG, &dataRead, 1);
    pData = dataRead << 16; // MSB

    busRead(PRESSURE_L_REG, &dataRead, 1);
    pData |= dataRead << 8; //LSB

    busRead(PRESSURE_OUT_XL, &dataRead, 1);
    pData |= dataRead;

    _pressure = (float) pData / 4096.0f;

    return _pressure;
}

uint16_t LPS22::getTemperature() {

    uint8_t dataRead = 0x00;

    uint16_t tData = 0;

    busRead(TEMP_OUT_H, &dataRead, 1);

    tData = dataRead << 16; // MSB

    busRead(TEMP_OUT_L, &dataRead, 1);

    tData |= dataRead << 8; // LSB

    _temperature = tData / 480;

    return _temperature;
}

float LPS22::getAltitude() {

    getPressure(); // Update Pressure Reading

    float pressure_Pa = _pressure * 100; // [hPa] -> [Pa]

    // Compute altitude
    return hb + (Tb / Lb) * (pow((pressure_Pa / pb), (-R * Lb / (g_0 * M))) - 1);
}
