#pragma once

constexpr static uint8_t ADXL_ADDR = 0x53; // I2C Address

constexpr static uint8_t ADXL_DEVID = 0x00; //R

constexpr static uint8_t ADXL_THRESH_SHOCK = 0x1D; //R/W

constexpr static uint8_t ADXL_OFSX = 0x1E; //R/W
constexpr static uint8_t ADXL_OFSY = 0x1F; //R/W
constexpr static uint8_t ADXL_OFSZ = 0x20; //R/W

constexpr static uint8_t ADXL_DUR = 0x21; //R/W
constexpr static uint8_t ADXL_LATENT = 0x22; // R/W
constexpr static uint8_t ADXL_WINDOW = 0x23; //R/W
constexpr static uint8_t ADXL_THRESH_ACT = 0x24; //R/W
constexpr static uint8_t ADXL_THRESH_INACT = 0x25; //R/W
constexpr static uint8_t ADXL_TIME_INACT = 0x26; //R/W

constexpr static uint8_t ADXL_ACT_INACT_CTL = 0x27; //R/W

constexpr static uint8_t ADXL_SHOCK_AXES = 0x2A; //R/W
constexpr static uint8_t ADXL_ACT_SHOCK_STATUS = 0x2B; //R

constexpr static uint8_t ADXL_BW_RATE = 0x2C; //R/W

constexpr static uint8_t ADXL_POWER_CTL = 0x2D; //R/W

constexpr static uint8_t ADXL_INT_ENABLE = 0x2E; //R/W
constexpr static uint8_t ADXL_INT_MAP = 0x2F; //R/W
constexpr static uint8_t ADXL_INT_SOURCE = 0x30; //R

constexpr static uint8_t ADXL_DATA_FORMAT = 0x31; //R/W
constexpr static uint8_t ADXL_DATAX0 = 0x32; //R
constexpr static uint8_t ADXL_DATAX1 = 0x33; //R
constexpr static uint8_t ADXL_DATAY0 = 0x34; //R
constexpr static uint8_t ADXL_DATAY1 = 0x35; //R
constexpr static uint8_t ADXL_DATAZ0 = 0x36; //R
constexpr static uint8_t ADXL_DATAZ1 = 0x37; //R
constexpr static uint8_t ADXL_FIFO_CTL = 0x38; //R/W
constexpr static uint8_t ADXL_FIFO_STATUS = 0x39; //R