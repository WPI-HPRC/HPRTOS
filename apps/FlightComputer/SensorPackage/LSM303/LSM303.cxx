#include "LSM303.h"

LSM303::LSM303() = default;

bool LSM303::init(int i2cBus) {
    // Initialize local fd with i2c driver address
    this->fd = i2cBus;

    // Identify ASM330 Accelerometer
    uint8_t dev_id = 0x00;

    busRead(0x0F, &dev_id, 1, 'a');
    if (dev_id != 0x33) {
        printf("[LSM303] Error: Accelerometer not found...\n");
    } else {
        printf("[LSM303] Accelerometer detected!\n");
    }

    busRead(0x4F, &dev_id, 1, 'm');
    if (dev_id != 0x40) {
        printf("[LSM303] Error: Magnetometer not found...\n");
    } else {
        printf("[LSM303] Magnetometer Detected!\n");
    }

    /* ---+ Configure Sensor +--- */
    /*TODO: ADD SENSOR CONFIG AND NOT HARD CODED VALS*/

    /* === Accelerometer Configuration === */
    uint8_t ODR_CFG = static_cast<uint8_t>(_odr_a);  // ODR (Output Data Rate)
    uint8_t LOW_PWR_MD = static_cast<uint8_t>(_mode_a) >> 1 & 0x01;  // Power Mode Bit
    uint8_t axisEnable = 0b111;  // Enable X, Y, Z axes

    // Shift configuration into place for CTRL_REG1
    uint8_t ctrl_reg_1 = (ODR_CFG << 4) | (LOW_PWR_MD << 3) | axisEnable;

    busWrite(CTRL_REG1_A, ctrl_reg_1, 'a');

    // Set CTRL2 Register - High pass filter configurations
    uint8_t HPF_CFG = 0b00; // High Pass Filter - Normal Mode
    uint8_t HPCF_CFG = 0b00; // High Pass filter - Cutoff Frequency
    uint8_t FILTBYP_CFG = 0b0000; // Filter Bypass

    uint8_t ctrl_reg_2 = (HPF_CFG << 6) | (HPCF_CFG << 4) | FILTBYP_CFG;

    busWrite(CTRL_REG2_A, ctrl_reg_2, 'a');

    // Set CTRL3 Register - Disable Interrupts
    uint8_t ctrl_reg_3 = 0b00000000;

    busWrite(CTRL_REG3_A, ctrl_reg_3, 'a');

    // Set CTRL4 Register - Full Scale Selection and other configurations
    uint8_t BDU = 0b0;  // Block Data Update - Continuous Update
    uint8_t BLE = 0b0;  // Little Endian - LSB First
    uint8_t FS = static_cast<uint8_t>(_range_a); // Full Scale Range: 2G, 4G, 8G, or 16G
    uint8_t HR = static_cast<uint8_t>(_mode_a) & 0x01; // High Rate Mode
    uint8_t ST = 0b00;  // Self Test - Disable
    uint8_t SPI_ENABLE = 0b0; // Disable SPI

    uint8_t ctrl_reg_4 = (BDU << 7) | (BLE << 6) | (FS << 4) | (HR << 3) | (ST << 1) | SPI_ENABLE;

    busWrite(CTRL_REG4_A, ctrl_reg_4, 'a');

    // Read back registers to verify setup
    uint8_t reg1Read = 0x00;
    uint8_t reg2Read = 0x00;
    uint8_t reg3Read = 0x00;
    uint8_t reg4Read = 0x00;

    busRead(CTRL_REG1_A, &reg1Read, 1, 'a');
    busRead(CTRL_REG2_A, &reg2Read, 1, 'a');
    busRead(CTRL_REG3_A, &reg3Read, 1, 'a');
    busRead(CTRL_REG4_A, &reg4Read, 1, 'a');

    if (reg1Read == ctrl_reg_1 && reg2Read == ctrl_reg_2 && reg3Read == ctrl_reg_3 && reg4Read == ctrl_reg_4) {
        printf("[LSM303] Sensor Setup Success!\n");
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}


/**
 * @name busWrite
 * @param reg - Target Register
 * @param val - Value to write
 * @return
 */
int LSM303::busWrite(uint8_t reg, uint8_t val, char sensorSelect) {
    int ex;

    uint8_t LSM303_ADDR = LSM303_ADDR_A;
    switch (sensorSelect) {
        case('a'): {
            LSM303_ADDR = LSM303_ADDR_A;
        }

        case('m'): {
            LSM303_ADDR = LSM303_ADDR_M;
        }
        default:
            LSM303_ADDR = LSM303_ADDR_A;
    }

    // Allocate memory of tx buffer
    uint8_t txBuffer[2];

    // Fill tx buffer with register and value to send
    txBuffer[0] = reg;
    txBuffer[1] = val;

    // Configure I2C message
    struct i2c_msg_s i2cMsg {
            .frequency = lsm_i2c_freq,
            .addr = LSM303_ADDR,
            .flags = 0,
            .buffer = txBuffer,
            .length = 2
    };

    // Prepare I2C transfer
    struct i2c_transfer_s i2cTransfer {
            .msgv = &i2cMsg,
            .msgc = 1
    };

    // Transfer I2C message to driver and return response code
    ex = ioctl(fd, I2CIOC_TRANSFER, (unsigned long)(uintptr_t) &i2cTransfer);

    // Error if transfer failed
    if(ex < 0) {
        printf("[LSM303] Error: Failed to set register -> %d\n", ex);
    }

    return ex;
}

int LSM303::busRead(uint8_t reg, uint8_t *val, int8_t len, char sensorSelect) {
    int ex;

    uint8_t LSM303_ADDR = 0x00;
    switch (sensorSelect) {
        case('a'): {
            LSM303_ADDR = LSM303_ADDR_A;
            break;
        }
        case('m'): {
            LSM303_ADDR = LSM303_ADDR_M;
            break;
        }
        default:
            LSM303_ADDR = LSM303_ADDR_A;
    }

    // Prepare to configure I2C driver into read mode on selected register
    struct i2c_msg_s i2cMsg[2] = {
            {
                    .frequency = lsm_i2c_freq,
                    .addr = LSM303_ADDR,
                    .flags = 0,
                    .buffer = &reg,
                    .length = 1
            },
            {
                    .frequency = lsm_i2c_freq,
                    .addr = LSM303_ADDR,
                    .flags = I2C_M_READ,
                    .buffer = val,
                    .length = len
            }
    };

    struct i2c_transfer_s i2cTransfer {
            .msgv = i2cMsg,
            .msgc = 2
    };

    ex = ioctl(fd, I2CIOC_TRANSFER, (unsigned long)(uintptr_t) &i2cTransfer);

    if(ex < 0) {
        printf("[LSM303] Read Error: %d\n", ex);
    }

    return ex;
}

int LSM303::readAccelerometer(int16_t &x, int16_t &y, int16_t &z) {

    // Read buffer for X-Y-Z Acceleration
    uint8_t rawData[6];

    // Read 6 bytes in one transaction
    busRead(OUT_X_L_A | 0x80, rawData, 6, 'a');

    // Combine high and low bits LSB
    x = (int16_t) ((rawData[1] << 8) | rawData[0]); // X-Axis
    y = (int16_t) ((rawData[3] << 8) | rawData[2]); // Y-Axis
    z = (int16_t) ((rawData[5] << 8) | rawData[4]); // Z-Axis

    return EXIT_SUCCESS;
}

void LSM303::packData(lsm_data_t *lsm_data) {

    int16_t accelX, accelY, accelZ;

    readAccelerometer(accelX, accelY, accelZ);

    uint8_t shift_a = 0;
    float scaleFactor_a = 0.0f;

    getLsbShift(shift_a, scaleFactor_a);

    // Convert to G's
    lsm_data->accel_x = (accelX >> shift_a) * scaleFactor_a;
    lsm_data->accel_y = (accelY >> shift_a) * scaleFactor_a;
    lsm_data->accel_z = (accelZ >> shift_a) * scaleFactor_a;

    // Convert to Gauss
    lsm_data->mag_x = 0.0f;
    lsm_data->mag_y = 0.0f;
    lsm_data->mag_z = 0.0f;
}

void LSM303::setAccelODR(LSM303_ODR_A odr) {
    _odr_a = odr;
}

void LSM303::setAccelMode(LSM303_MODE_A mode) {
    _mode_a = mode;
}

void LSM303::setAccelRange(LSM303_RANGE_A range) {
    _range_a = range;
}

void LSM303::getLsbShift(uint8_t &shift, float &lsb) {

    switch(_mode_a) {

        case(LSM303_MODE_A::MODE_HIGH_RES): {
            shift = 4;

            switch(_range_a) {
                case(LSM303_RANGE_A::RANGE_2G): {
                    lsb = 0.98f;
                    break;
                }

                case(LSM303_RANGE_A::RANGE_4G): {
                    lsb = 1.95f;
                    break;
                }

                case(LSM303_RANGE_A::RANGE_8G): {
                    lsb = 3.9f;
                    break;
                }

                case(LSM303_RANGE_A::RANGE_16G): {
                    lsb = 11.72f;
                    break;
                }
            }
            break;
        }

        case(LSM303_MODE_A::NORMAL) : {
            shift = 6;
            switch(_range_a) {
                case(LSM303_RANGE_A::RANGE_2G): {
                    lsb = 3.9f;
                    break;
                }
                case(LSM303_RANGE_A::RANGE_4G): {
                    lsb = 7.82f;
                    break;
                }
                case(LSM303_RANGE_A::RANGE_8G): {
                    lsb = 15.63f;
                    break;
                }
                case(LSM303_RANGE_A::RANGE_16G): {
                    lsb = 46.9f;
                    break;
                }
            }

            break;
        }

        case(LSM303_MODE_A::MODE_LOW_PWR): {
            shift = 8;

            switch(_range_a) {
                case(LSM303_RANGE_A::RANGE_2G): {
                    lsb = 15.63f;
                    break;
                }
                case(LSM303_RANGE_A::RANGE_4G): {
                    lsb = 31.26f;
                    break;
                }
                case(LSM303_RANGE_A::RANGE_8G): {
                    lsb = 62.52f;
                    break;
                }
                case(LSM303_RANGE_A::RANGE_16G): {
                    lsb = 187.58;
                    break;
                }
            }
            break;
        }

    }
}
