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
#include "LSM303_configs.h"


class LSM303 {
public:
    LSM303();

    bool init(int i2cBus);

    void packData(lsm_data_t *lsm_data);

    void setAccelODR(LSM303_ODR_A odr);

    void setAccelMode(LSM303_MODE_A mode);

    void setAccelRange(LSM303_RANGE_A range);

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

    int readAccelerometer(int16_t &x, int16_t &y, int16_t &z);

    int readMagnetometer();

    // Sensor Configurations
    LSM303_ODR_A _odr_a;
    LSM303_MODE_A _mode_a;
    LSM303_RANGE_A _range_a;

    // Shift and LSB

    void getLsbShift(uint8_t &shift, float &lsb);

};