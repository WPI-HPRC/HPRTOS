#pragma once

constexpr static uint8_t ASM330_ADDR = 0x6B; // I2C Address

constexpr static uint8_t PIN_CTRL = 0x02;

constexpr static uint8_t FIFO_CTRL1 = 0x07;
constexpr static uint8_t FIFO_CTRL2 = 0x08;
constexpr static uint8_t FIFO_CTRL3 = 0x09;
constexpr static uint8_t FIFO_CTRL4 = 0x0A;

constexpr static uint8_t COUNTER_BDR_REG1 = 0x0B;
constexpr static uint8_t COUNTER_BDR_REG2 = 0x0C;

constexpr static uint8_t INT1_CTRL = 0x0D;
constexpr static uint8_t INT2_CTRL = 0x0E;

constexpr static uint8_t WHO_AM_I = 0x0F;

constexpr static uint8_t CTRL1_XL = 0x10;
constexpr static uint8_t CTRL2_G  = 0x11;
constexpr static uint8_t CTRL3_C  = 0x12;
constexpr static uint8_t CTRL4_C  = 0x13;
constexpr static uint8_t CTRL5_C  = 0x14;
constexpr static uint8_t CTRL6_C  = 0x15;
constexpr static uint8_t CTRL7_C  = 0x16;
constexpr static uint8_t CTRL8_XL = 0x17;
constexpr static uint8_t CTRL9_XL = 0x18;

constexpr static uint8_t ALL_INT_SRC = 0x1B;
constexpr static uint8_t D6D_SRC     = 0x1D;

constexpr static uint8_t STATUS_REG = 0x1E;

constexpr static uint8_t OUT_TEMP_L = 0x20;
constexpr static uint8_t OUT_TEMP_H = 0x21;

constexpr static uint8_t OUTX_L_G = 0x22;
constexpr static uint8_t OUTX_H_G = 0x23;

constexpr static uint8_t OUTY_L_G = 0x24;
constexpr static uint8_t OUTY_H_G = 0x25;

constexpr static uint8_t OUTZ_L_G = 0x26;
constexpr static uint8_t OUTZ_H_G = 0x27;

constexpr static uint8_t OUTX_L_A = 0x28;
constexpr static uint8_t OUTX_H_A = 0x29;

constexpr static uint8_t OUTY_L_A = 0x2A;
constexpr static uint8_t OUTY_H_A = 0x2B;

constexpr static uint8_t OUTZ_L_A = 0x2C;
constexpr static uint8_t OUTZ_H_A = 0x2D;

constexpr static uint8_t TIMESTAMP0_REG = 0x40;
constexpr static uint8_t TIMESTAMP1_REG = 0x41;
constexpr static uint8_t TIMESTAMP2_REG = 0x42;
constexpr static uint8_t TIMESTAMP3_REG = 0x43;

constexpr static uint8_t INT_CFG0 = 0x56;
constexpr static uint8_t INT_CFG1 = 0x58;

constexpr static uint8_t THS_6D = 0x59;
constexpr static uint8_t WAKE_UP_THS = 0x5B;
constexpr static uint8_t WAKE_UP_DUR = 0x5C;

constexpr static uint8_t FREE_FALL = 0x5D;

constexpr static uint8_t MD1_CFG = 0x5E;
constexpr static uint8_t MD2_CFG = 0x5F;

constexpr static uint8_t INTERNAL_FREQ_FINE = 0x63;

constexpr static uint8_t X_OFS_USR = 0x73;
constexpr static uint8_t Y_OFS_USR = 0x74;
constexpr static uint8_t Z_OFS_USR = 0x75;

constexpr static uint8_t FIFO_DATA_OUT_TAG = 0x78;
constexpr static uint8_t FIFO_DATA_OUT_X_L = 0x79;
constexpr static uint8_t FIFO_DATA_OUT_X_H = 0x7A;
constexpr static uint8_t FIFO_DATA_OUT_Y_L = 0x7B;
constexpr static uint8_t FIFO_DATA_OUT_Y_H = 0x7C;
constexpr static uint8_t FIFO_DATA_OUT_Z_L = 0x7D;
constexpr static uint8_t FIFO_DATA_OUT_Z_H = 0x7E;