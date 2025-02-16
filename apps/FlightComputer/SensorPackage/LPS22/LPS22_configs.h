#pragma once

enum class LPS22_ODR : uint8_t {
    ONE_SHOT = 0b000,
    HZ_1     = 0b001,
    HZ_10    = 0b010,
    HZ_25    = 0b011,
    HZ_50    = 0b100,
    HZ_75    = 0b101,
    HZ_100   = 0b110,
    HZ_200   = 0b111
};