#pragma once

#include <nuttx/config.h>

#include <cstdlib>
#include <cstdio>
#include <fcntl.h>
#include <sched.h>
#include <cerrno>
#include <cmath>
#include <sys/ioctl.h>
#include <nuttx/i2c/i2c_master.h>
#include <cstring>

#include "LPS22_registers.h"
#include "LPS22_configs.h"
#include "../../FlightLib/FlightConstants.h"

class LPS22 {

public:
    LPS22();

    bool init(int i2cBus);

    void setODR(LPS22_ODR odr);

    float getPressure();

    float getAltitude();

    uint16_t getTemperature();
private:

    int16_t busWrite(uint8_t reg, uint8_t val);

    int16_t busRead(uint8_t reg, uint8_t *val, int8_t len);

    float _pressure = 0.0f;
    uint16_t _temperature = 0;

    float _altitude = 0.0f;

    LPS22_ODR _odr;

    int fd = 0;
};