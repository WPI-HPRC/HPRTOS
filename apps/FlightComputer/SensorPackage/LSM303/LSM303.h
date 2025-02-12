#pragma once

#include <nuttx/config.h>
#include <nuttx/i2c/i2c_master.h>
#include <mqueue.h>

#include <cstdlib>
#include <cstdio>
#include <fcntl.h>
#include <sched.h>
#include <cerrno>
#include <sys/ioctl.h>
#include <cstring>

#include "../../FlightLib/SensorData.h"
#include "../../FlightLib/FlightConfig.h"

#include "LSM303_registers.h"

class LSM303 {
public:
    LSM303();

    bool init(int i2cBus);

private:
    int busWrite(uint8_t reg, uint8_t val, char sensorSelect);

    int busRead(uint8_t reg, uint8_t *val, int8_t len, char sensorSelect);

    int fd = 0;

    // LSM303 I2C Frequency
    constexpr static int lsm_i2c_freq = 400000; // [Hz] 400KHz

    // Sensor Reading
    float _accelX = 0.0f;
    float _accelY = 0.0f;
    float _accelZ = 0.0f;

    float _magX = 0.0f;
    float _magY = 0.0f;
    float _magZ = 0.0f;

    int readSensor();
};