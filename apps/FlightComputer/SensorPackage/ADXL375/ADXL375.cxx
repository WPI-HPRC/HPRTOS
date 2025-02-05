#include "ADXL375.h"

ADXL375::ADXL375() = default;

bool ADXL375::init(int i2cBus) {
    printf("[ADXL375] Starting sensor...\n");

    // Initialize local fd with i2c driver address
    this->fd = i2cBus;

    // Identify ADXL375 Sensor
    uint8_t dev_id = 0x00;

    busRead(ADXL_ADDR, &dev_id, 1);

    if(dev_id != ADXL_ADDR) {
        printf("[ADXL375] Error: Failed to initialize...\n");

        return false;
    }

    /* ---+ Configure Sensor +--- */

    // Disable interrupts
    busWrite(ADXL_INT_ENABLE, 0);

    return true;

}

/**
 * @name busWrite
 * @param reg - Target Register
 * @param val - Value to write
 * @return
 */
int ADXL375::busWrite(uint8_t reg, uint8_t val) {

    int ex;

    // Allocate memory of tx buffer
    uint8_t txBuffer[2];

    // Fill tx buffer with register and value to send
    txBuffer[0] = reg;
    txBuffer[1] = val;

    // Configure I2C message
    struct i2c_msg_s i2cMsg {
        .frequency = 400000,
        .addr = ADXL_ADDR,
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
        printf("[ADXL375] Error: Failed to set register -> %d\n", ex);
    }

    return ex;
}

int ADXL375::busRead(uint8_t reg, uint8_t *val, int8_t len) {

    int ex;

    fd = open("/dev/i2c1", O_WRONLY);

    // Prepare to configure I2C driver into read mode on selected register
    struct i2c_msg_s i2cMsg[2] = {
            {
                .frequency = 400000,
                .addr = ADXL_ADDR,
                .flags = 0,
                .buffer = &reg,
                .length = 1
            },
            {
                .frequency = 400000,
                .addr = ADXL_ADDR,
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
        printf("[ADXL375] Read Error: %d\n", ex);
    }

    return ex;
}

int ADXL375::setOffsets(adxl_offset_t offset) {

    int ex = 0;

    // Set X Offset
    ex &= busWrite(ADXL_OFSX, offset.X);

    // Set Y Offset
    ex &= busWrite(ADXL_OFSY, offset.Y);

    // Set Z Offset
    ex &= busWrite(ADXL_OFSZ, offset.Z);

    return ex;
}

int ADXL375::readSensor() {
    uint8_t rawData[6];

    int ex;

    ex = busRead(ADXL_DATAX0, rawData, 6);

    _accelX = (int16_t)((rawData[1] << 8) | rawData[0]) * adxl_sensitivity_factor;

    _accelY = (int16_t)((rawData[3] << 8) | rawData[2]) * adxl_sensitivity_factor;

    _accelZ = (int16_t)((rawData[5] << 8) | rawData[4]) * adxl_sensitivity_factor;

    return ex;
}

void ADXL375::packData(adxl375_data_t *adxl_data) {

    adxl_data->accel_x = _accelX;
    adxl_data->accel_y = _accelY;
    adxl_data->accel_y = _accelZ;

}

int ADXL375::readTask(int argc, char **argv) {

    ADXL375 adxl = ADXL375();

    if (argc < 1 || argv == nullptr) {
        printf("[ADXL375]: Error: Missing I2C bus argument.\n");
        return EXIT_FAILURE;
    }

    // Extract the I2C bus from argv
    int i2cBus = atoi(argv[0]); // Assumes argv[0] contains the bus number as a string
    printf("[ADXL375]: Starting with I2C bus %d...\n", i2cBus);

    // Initialize the sensor
    if (adxl.init(1) != 0) {
        printf("[ADXL375]: Error: Failed to initialize the sensor.\n");
        return EXIT_FAILURE;
    }

    // Message queue setup
    struct mq_attr attr = {
            .mq_maxmsg = 1,
            .mq_msgsize = sizeof(adxl375_data_t),
            .mq_flags = 0
    };

    mqd_t mqd = mq_open("/ADXL375_queue", O_CREAT | O_WRONLY, 0644, &attr);
    if (mqd == (mqd_t)-1) {
        printf("[ADXL375]: Error: Failed to create message queue.\n");
        return EXIT_FAILURE;
    }

    struct timespec ts;

    // Main loop
    adxl375_data_t adxlData;
    struct timespec sleep_time = {
            .tv_sec = 0,
            .tv_nsec = (1000000000 / 400) // Example polling rate: 100 Hz
    };

    while (true) {
        // Read accelerometer data
//        read(&adxlData.accel_x, &adxlData.accel_y, &adxlData.accel_z);

        // Send data to the message queue
        if (mq_send(mqd, (const char *)&adxlData, sizeof(adxlData), 0) == -1) {
            printf("[ADXL375]: Error: Failed to send data to the queue.\n");
        }

        // Sleep for the polling interval
        nanosleep(&sleep_time, nullptr);
    }

    // Clean up (unreachable in this example)
    mq_close(mqd);
    return EXIT_SUCCESS;

}
