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

#include "ASM330_registers.h"

// Device Offsets
typedef struct {
    uint8_t X;
    uint8_t Y;
    uint8_t Z;
} adxl_offset_t;

struct adxl_odr {
    uint8_t HZ_3200 = 0b1111;
    uint8_t HZ_1600 = 0b1110;
    uint8_t HZ_800  = 0b1101;
    uint8_t HZ_400  = 0b1100;
    uint8_t HZ_200  = 0b1011;
    uint8_t HZ_100  = 0b1010;
    uint8_t HZ_50   = 0b1001;
    uint8_t HZ_25   = 0b1000;
};

class ASM330 {
public:
    ASM330();

    bool init(int i2cBus);

    void packData(asm_data_t *adxl_data);

    float asm_sensitivity_factor = 0.049; // [mg/LSB]

private:

    int busWrite(uint8_t reg, uint8_t val);

    int busRead(uint8_t reg, uint8_t *val, int8_t len);

    int fd = 0;

    // ASM330 I2C Frequency
    constexpr static int asm_i2c_freq = 400000; // [Hz] 400KHz

    // Configuration Parameters
//    int setOffsets(adxl_offset_t offset);
//    int setODR(uint8_t ODR);
//    int setAccelRange(uint8_t range);

    // Sensor Readings
    float _accelX = 0.0f;
    float _accelY = 0.0f;
    float _accelZ = 0.0f;

    float _gyroX = 0.0f;
    float _gyroY = 0.0f;
    float _gyroZ = 0.0f;

    int readSensor();
};