#include "LSM303.h"

LSM303::LSM303() = default;

bool LSM303::init(int i2cBus) {
    printf("[LSM303] Starting sensor...\n");

    // Initialize local fd with i2c driver address
    this->fd = i2cBus;

    // Identify ASM330 Accelerometer
    uint8_t dev_id = 0x00;

    busRead(0x0F, &dev_id, 1, 'a');
    if(dev_id != 0x33) {
        printf("[LSM303] Error: Accelerometer not found...\n");
    } else {
        printf("[LSM303] Accelerometer detected!\n");
    }

    busRead(0x0F, &dev_id, 1, 'm');
    if(dev_id != 0x3D) {
        printf("[LSM303] Error: Magnetometer not found...\n");
    } else {
        printf("[LSM303] Magnetometer Detected!\n");
    }

    /* ---+ Configure Sensor +--- */

    // Disable interrupts
//    busWrite(ADXL_INT_ENABLE, 0);

    return true;

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