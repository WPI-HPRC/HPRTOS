#pragma once

constexpr static uint8_t LSM303_ADDR_A = 0x19; // I2C Address
constexpr static uint8_t LSM303_ADDR_M = 0x1E;

constexpr static uint8_t CTRL_REG1_A = 0x20;
constexpr static uint8_t CTRL_REG2_A = 0x21;
constexpr static uint8_t CTRL_REG3_A = 0x22;
constexpr static uint8_t CTRL_REG4_A = 0x23;
constexpr static uint8_t CTRL_REG5_A = 0x24;
constexpr static uint8_t CTRL_REG6_A = 0x25;

constexpr static uint8_t REFERENCE_A = 0x26;
constexpr static uint8_t STATUS_REG_A = 0x27;
constexpr static uint8_t OUT_X_L_A = 0x28;
constexpr static uint8_t OUT_X_H_A = 0x29;

constexpr static uint8_t OUT_Y_L_A = 0x2A;
constexpr static uint8_t OUT_Y_H_A = 0x2B;

constexpr static uint8_t OUT_Z_L_A = 0x2C;
constexpr static uint8_t OUT_Z_H_A = 0x2D;

constexpr static uint8_t FIFO_CTRL_REG_A = 0x2E;
constexpr static uint8_t FIFO_SRC_A      = 0x2F;

constexpr static uint8_t INT1_CFG_A = 0x30;
constexpr static uint8_t INT1_SRC_A = 0x31;
constexpr static uint8_t INT1_THS_A = 0x32;
constexpr static uint8_t INT1_DURATION_A = 0x33;

constexpr static uint8_t INT2_CFG_A = 0x34;
constexpr static uint8_t INT2_SRC_A = 0x35;
constexpr static uint8_t INT2_THS_A = 0x36;
constexpr static uint8_t INT2_DURATION_A = 0x37;

constexpr static uint8_t CLICK_CFG_A = 0x38;
constexpr static uint8_t CLICK_SRC_A = 0x39;
constexpr static uint8_t CLICK_THS_A = 0x3A;

constexpr static uint8_t TIME_LIMIT_A = 0x3B;
constexpr static uint8_t TIME_LATENCY_A = 0x3C;
constexpr static uint8_t TIME_WINDOW_A = 0x3D;

constexpr static uint8_t CRA_REG_M = 0x00;
constexpr static uint8_t CRB_REG_M = 0x01;

constexpr static uint8_t MR_REG_M = 0x02;

constexpr static uint8_t OUT_X_H_M = 0x03;
constexpr static uint8_t OUT_X_L_M = 0x04;

constexpr static uint8_t OUT_Z_H_M = 0x05;
constexpr static uint8_t OUT_Z_L_M = 0x06;

constexpr static uint8_t OUT_Y_H_M = 0x07;
constexpr static uint8_t OUT_Y_L_M = 0x08;

constexpr static uint8_t SR_REG_M = 0x09;
constexpr static uint8_t IRA_REG_M = 0x0A;
constexpr static uint8_t IRB_REG_M = 0x0B;
constexpr static uint8_t IRC_REG_M = 0x0C;

constexpr static uint8_t TEMP_OUT_H_M = 0x31;
constexpr static uint8_t TEMP_OUT_L_M = 0x32;
