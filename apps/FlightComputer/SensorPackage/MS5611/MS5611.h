#pragma once

#include <nuttx/config.h>

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sched.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <nuttx/i2c/i2c_master.h>
#include <string.h>
#include <math.h>

#include "MS5611_registers.h"

class MS5611 {

public:
    MS5611();

    bool init(int i2cBus);

    float getPressure();
    uint16_t getTemperature();
    float getAltitude();
private:

    int16_t busWrite(uint8_t reg, uint8_t val);
    int16_t busRead(uint8_t reg, uint8_t *val, int8_t len);
    int16_t sendCommand(uint8_t command);

    void getCalibration();

    void reset();

    float _pressure = 0.0;
    int16_t _temperature = 0;

    int fd = 0;

    constexpr static uint8_t MS5611_ADDR = 0x77;

    /* <-- Constants --> */
    constexpr static float P0 = 1013.25; // [hPa] Sea level Pressure

    /* <-- MS5611 Configuration Parameters --> */
    // 256 Bit OSR
    constexpr static uint8_t D1_OSR = 0x40;
    constexpr static uint8_t D2_OSR = 0x50;
    constexpr static int OSR_VAL = 256;

    uint16_t C1 = 0;
    uint16_t C2 = 0;
    uint16_t C3 = 0;
    uint16_t C4 = 0;
    uint16_t C5 = 0;
    uint16_t C6 = 0;

};