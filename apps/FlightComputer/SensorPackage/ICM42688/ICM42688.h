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

#include "../../FlightLib/SensorData.h"
#include "../../FlightLib/FlightConfig.h"

#include "ICM42688_registers.h"

class ICM42688 {
public:
    ICM42688();

    bool init(int i2cBus);

    void getImuData(imu_data_t &imuData);
private:

    int16_t busWrite(uint8_t reg, uint8_t val);

    int16_t busRead(uint8_t reg, uint8_t *val, int8_t len);

    bool switchRegBank(uint8_t bank);

    void enableSensor();

    void setFilters();

    void setODR();

    int fd = 0;

    // Floating Point Resolution Factors
    const float accelRes = 2048.0;
    const float gyroRes = 16.4;

    // Sensor Configuration
    const uint8_t ICM42688_ADDR = 0x68;

    // IMU Register sets - LOOK AT THE DATASHEET FOR MORE INFO
    const uint8_t SENSOR_ENABLE = 0x0F; // 0000 1111 = Enable all sensors

    const uint8_t ACCEL_ODR = 0x05; // 0000 0101 = 2 kHz
    const uint8_t ACCEL_FS_SEL = 0x00; // 0000 0000 = +/- 16g

    const uint8_t GYRO_ODR = 0x05; // 0000 0101 = 2 kHz
    const uint8_t GYRO_FS_SEL = 0x00; // 0000 0000 = +/- 2000 deg/s

    // ACCEL AAF: 3dB cutoff frequency: 126 Hz
    const uint8_t ACCEL_AAF_DELT = 3;
    const uint8_t ACCEL_AAF_DELTSQR = 9; // This limits the max DELTSQR value to 122 but that's fine for our purposes
    const uint8_t ACCEL_AAF_BITSHIFT = 12;

    // GYRO AAF 3dB cutoff frequency: 126 Hz
    const uint8_t GYRO_AAF_DELT = 3;
    const uint8_t GYRO_AAF_DELTSQR = 9; // This limits the max DELTSQR value to 122 but that's fine for our purposes
    const uint8_t GYRO_AAF_BITSHIFT = 12;

};