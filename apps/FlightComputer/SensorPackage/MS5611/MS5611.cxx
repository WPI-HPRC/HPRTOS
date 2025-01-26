#include "MS5611.h"

MS5611::MS5611() = default;

bool MS5611::init(int i2cBus)
{
    this->fd = i2cBus;

    // Reset Sensor
    if(sendCommand(0x1E) < 0)
    {
        return false;
    }

    usleep(10000); // Allow sensor to reset

    getCalibration();

    // Set OSR Resolution
    sendCommand(D1_OSR);
    sendCommand(D2_OSR);

    return true;
}

int16_t MS5611::busWrite(uint8_t reg, uint8_t val) {
    int16_t ex;

    uint8_t txBuffer[2];

    txBuffer[0] = reg;
    txBuffer[1] = val;

    struct i2c_msg_s i2cMsg {
        .frequency = 400000,
        .addr = MS5611_ADDR,
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
        printf("[MS5611] Error: Failed to set register -> %d\n", ex);
    }

    return ex;
}

int16_t MS5611::busRead(uint8_t reg, uint8_t *val, int8_t len) {
    int16_t ex;

    struct i2c_msg_s i2cMsg[2] = {
        {
            .frequency = 400000,
            .addr = MS5611_ADDR,
            .flags = 0,
            .buffer = &reg,
            .length = 1
        },
        {
            .frequency = 400000,
            .addr = MS5611_ADDR,
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
        printf("[MS5611] Read Error: %d\n", ex);
    }

    return ex;
}

int16_t MS5611::sendCommand(uint8_t command) {
    int16_t ex;

    struct i2c_msg_s i2cMsg {
        .frequency = 400000,
        .addr = MS5611_ADDR,
        .flags = 0,
        .buffer = &command,
        .length = 1
    };

    struct i2c_transfer_s i2cTransfer {
        .msgv = &i2cMsg,
        .msgc = 1
    };

    ex = ioctl(fd, I2CIOC_TRANSFER, (unsigned long)(uintptr_t) &i2cTransfer);

    if(ex < 0) {
        printf("[MS5611] Error: Failed to send command -> %d\n", ex);
    }

    return ex;
}

void MS5611::getCalibration()
{
    uint8_t dataRead[2];

    busRead(PROM1, dataRead, 2);
    C1 = (dataRead[0] << 8) | dataRead[1];

    busRead(PROM2, dataRead, 2);
    C2 = (dataRead[0] << 8) | dataRead[1];

    busRead(PROM3, dataRead, 2);
    C3 = (dataRead[0] << 8) | dataRead[1];

    busRead(PROM4, dataRead, 2);
    C4 = (dataRead[0] << 8) | dataRead[1];

    busRead(PROM5, dataRead, 2);
    C5 = (dataRead[0] << 8) | dataRead[1];

    busRead(PROM6, dataRead, 2);
    C6 = (dataRead[0] << 8) | dataRead[1];
}

float MS5611::getPressure()
{
    uint32_t D1 = 0;
    uint32_t D2 = 0;
    uint8_t dataRead[3];

    // Start D1 (pressure) conversion with OSR 256
    sendCommand(D1_OSR);
    usleep(600); // 600 us delay for sensor processing rate
    busRead(0x00, dataRead, 3);
    D1 = (dataRead[0] << 16) | (dataRead[1] << 8) | dataRead[2];

    // Start D2 (temperature) conversion with OSR 256
    sendCommand(D2_OSR);
    usleep(600); // 600 us delay for sensor processing rate
    busRead(0x00, dataRead, 3);
    D2 = (dataRead[0] << 16) | (dataRead[1] << 8) | dataRead[2];

    // Calculate temperature difference from the reference value
    int32_t dT = D2 - ((int32_t)C5 * 256);
    // Calculate actual temperature
    int32_t TEMP = 2000 + ((int32_t)dT * C6) / 8388608;

    // Calculate offset and sensitivity
    int32_t OFF = ((int32_t)C2 * 65536) + (((int32_t)C4 * dT) / 128);
    int32_t SENS = ((int32_t)C1 * 32768) + (((int32_t)C3 * dT) / 256);

    // Second-order temperature compensation if temperature is below 20 degrees Celsius
    if (TEMP < 2000) {
        int32_t T2 = (dT * dT) / 2147483648U;
        int32_t OFF2 = 5 * ((TEMP - 2000) * (TEMP - 2000)) / 2;
        int32_t SENS2 = 5 * ((TEMP - 2000) * (TEMP - 2000)) / 4;
        if (TEMP < -1500) {
            OFF2 += 7 * ((TEMP + 1500) * (TEMP + 1500));
            SENS2 += 11 * ((TEMP + 1500) * (TEMP + 1500)) / 2;
        }
        TEMP -= T2;
        OFF -= OFF2;
        SENS -= SENS2;
    }

    // Calculate actual pressure
    int32_t P = (((D1 * SENS) / 2097152) - OFF) / 32768;
    _pressure = P / 100.0f;

    return _pressure;
}

uint16_t MS5611::getTemperature()
{
    return _temperature;
}



float MS5611::getAltitude()
{
    return 44330.0 * (1.0 - pow(_pressure / P0, 0.1903));
}
