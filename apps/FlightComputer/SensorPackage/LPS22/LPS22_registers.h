#pragma once



constexpr static uint8_t LPS22_ADDR = 0x5d;
constexpr static uint8_t LPS22_WHOAMI = 0x0f;
constexpr static uint8_t LPS22_WHO_ID = 0xB3;

constexpr static uint8_t LPS22_INTERRUPT_CFG = 0x0B;

// Pressure Threshold
constexpr static uint8_t THS_P_L = 0x0C;
constexpr static uint8_t THS_P_H = 0x0D;

// Control Registers
constexpr static uint8_t CTRL_REG1 = 0x10;
constexpr static uint8_t CTRL_REG2 = 0x11;
constexpr static uint8_t CTRL_REG3 = 0x12;

// Reference Pressure
constexpr static uint8_t REF_P_L = 0x15;
constexpr static uint8_t REF_P_H = 0x16;

// Status
constexpr static uint8_t STATUS = 0x27;

// Pressure Out
constexpr static uint8_t PRESSURE_OUT_XL = 0x28;
constexpr static uint8_t PRESSURE_L_REG = 0x29;
constexpr static uint8_t PRESSURE_H_REG = 0x2A;

// Temperature out
constexpr static uint8_t TEMP_OUT_L = 0x2B;
constexpr static uint8_t TEMP_OUT_H = 0x2C;