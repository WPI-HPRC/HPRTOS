#pragma once

enum class LSM303_ODR_A : uint8_t {
    PWR_DWN = 0b0000,
    HZ_1    = 0b0001,
    HZ_10   = 0b0010,
    HZ_25   = 0b0011,
    HZ_50   = 0b0100,
    HZ_100  = 0b0101,
    HZ_200  = 0b0110,
    HZ_400  = 0b0111
};

enum class LSM303_MODE_A : uint8_t {
    NORMAL        = 0b00,
    MODE_HIGH_RES = 0b01,
    MODE_LOW_PWR  = 0b10
};

enum class LSM303_RANGE_A : uint8_t {
    RANGE_2G  = 0b00,
    RANGE_4G  = 0b01,
    RANGE_8G  = 0b10,
    RANGE_16G = 0b11
};