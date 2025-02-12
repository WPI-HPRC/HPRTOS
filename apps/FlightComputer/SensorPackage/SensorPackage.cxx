#include <nuttx/config.h>
#include <nuttx/init.h>
#include <cstdio>
#include <mqueue.h>
#include <sys/types.h>
#include <fcntl.h>
#include <cstdlib>
#include <unistd.h>
#include "../FlightLib/SensorData.h"
#include "../FlightLib/FlightConfig.h"

#include "MAX10S/MAX10S.h"
#include "ASM330/ASM330.h"
#include "LSM303/LSM303.h"

#include "SensorPackage.h"

static int i2cBus = 0;

static int initSensorBus() {
    int ret = 0;

    i2cBus = open("/dev/i2c1", O_WRONLY);

    if(i2cBus < 0) {
        printf("[Sensor Package] Error: Failed to initialize i2c...\n");

        ret = 0;
    } else {
        printf("[Sensor Package]: Initialized i2c!\n");
        ret = 1;
    }

    return ret;
}

//static int adxlTask(int argc, char *argv[]) {
//    ADXL375 adxl = ADXL375();
//
//    adxl.init(i2cBus);
//
//    // Message queue setup
//    struct mq_attr attr = {
//            .mq_maxmsg = 1,
//            .mq_msgsize = sizeof(adxl375_data_t),
//            .mq_flags = 0
//    };
//
//    mqd_t mqd = mq_open("/ADXL375_queue", O_CREAT | O_WRONLY, 0644, &attr);
//    if (mqd == (mqd_t)-1) {
//        printf("[ADXL375]: Error: Failed to create message queue.\n");
//        return EXIT_FAILURE;
//    }
//
//    // Main loop
//    adxl375_data_t adxlData;
//    struct timespec sleep_time = {
//            .tv_sec = 0,
//            .tv_nsec = (1000000000 / 400) // Example polling rate: 100 Hz
//    };
//
//    while (true) {
//        // Read accelerometer data
////        read(&adxlData.accel_x, &adxlData.accel_y, &adxlData.accel_z);
//
//        // Send data to the message queue
//        if (mq_send(mqd, (const char *)&adxlData, sizeof(adxlData), 0) == -1) {
//            printf("[ADXL375]: Error: Failed to send data to the queue.\n");
//        }
//
//        // Sleep for the polling interval
//        nanosleep(&sleep_time, nullptr);
//    }
//
//    // Clean up (unreachable in this example)
//    mq_close(mqd);
//    return EXIT_SUCCESS;
//}


static int gpsTask(int argc, char *argv[]) {
    printf("[GPS] Spawning GPS process...\n");

    mq_attr attr = {
            .mq_maxmsg = 1,
            .mq_msgsize = sizeof(gps_data_t),
            .mq_flags = 0
    };

    mqd_t mqd = mq_open("/gpsQueue", O_CREAT | O_WRONLY, 0644, &attr);
    if(mqd == (mqd_t)-1) {
        printf("[GPS] Error creating GPS queue...\n");
        return EXIT_FAILURE;
    }

    MAX10S gps = MAX10S();

    gps.init(i2cBus);

    gps_data_t gpsData;

    struct timespec sleep_time = {
            .tv_sec = 0,
            .tv_nsec = (1000000000 / 400)
    };

    while(1) {
        gpsData = {
                .gps_e_x = 1.0,
                .gps_e_y = 1.0,
                .gps_e_z = 1.0,
                .gps_v_ned_x = 1.0,
                .gps_v_ned_y = 1.0,
                .gps_v_ned_z = 1.0,
                .gps_numSats = 31
        };

        uint8_t nmeaMsg[128];

        gps.getNMEA(nmeaMsg);

        gps.parseMessage((char *) nmeaMsg, &gpsData);

        printf("%s\n", nmeaMsg);

//        mq_send(mqd, (const char*)&gpsData, sizeof(gpsData), 0);
        nanosleep(&sleep_time, nullptr);
    }

    mq_close(mqd);
    mq_unlink("/gpsQueue");

    return EXIT_SUCCESS;
}

static int lsmTask(int argc, char *argv[]) {
    printf("[IMU_1] Spawning IMU_1 process...\n");

    mq_attr attr = {
            .mq_maxmsg = 1,
            .mq_msgsize = sizeof(gps_data_t),
            .mq_flags = 0
    };

    mqd_t mqd = mq_open("/lsmQueue", O_CREAT | O_WRONLY, 0644, &attr);
    if(mqd == (mqd_t)-1) {
        printf("[IMU_1] Error creating IMU_1 queue...\n");
        return EXIT_FAILURE;
    }

    LSM303 lsm303 = LSM303();

    lsm303.init(i2cBus);

//    gps_data_t gpsData;
    asm_data_t lsmData;

    struct timespec sleep_time = {
            .tv_sec = 0,
            .tv_nsec = (1000000000 / 400)
    };

    while(1) {
        lsmData = {
                .accel_x = 0.0,
                .accel_y = 0.0,
                .accel_z = 0.0,
                .gyro_x = 0.0,
                .gyro_y = 0.0,
                .gyro_z = 0.0
        };

//        mq_send(mqd, (const char*)&gpsData, sizeof(gpsData), 0);
        nanosleep(&sleep_time, nullptr);
    }

    mq_close(mqd);
    mq_unlink("/lsmQueue");

    return EXIT_SUCCESS;
}

extern "C" int FC_SensorPackage_main(int argc, char *argv[]) {
	printf("Starting Flight Sensor Package...\n");

    int ret = initSensorBus();

    char i2cBusStr[8]; // Enough to hold the I2C bus number as a string
    snprintf(i2cBusStr, sizeof(i2cBusStr), "%d", i2cBus);
    char *threadArgv[] = {i2cBusStr, nullptr};

    printf("%s", (char*) threadArgv);

    ret &= task_create("gpsTask",
                       CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_PRIORITY,
                       CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_STACKSIZE,
                       gpsTask,
                       nullptr);

    ret &= task_create("lsmTask",
                       CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_PRIORITY,
                       CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_STACKSIZE,
                       lsmTask,
                       nullptr);

    if(ret < 0) {
        int errcode = errno;

        printf("[State Machine] ERROR: Failed to start State Machine task: %d\n", errcode);

        return EXIT_FAILURE;
    }

//    ret &= task_create("adxlTask",
//                      CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_PRIORITY,
//                      CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_STACKSIZE,
//                       ADXL375::readTask,
//                       threadArgv);

//    if(ret <= 0) {
//        const int errcode = errno;
//
//        printf("[Sensor Package] ERROR: Failed to start State Machine task: %d\n", errcode);
//
//        return EXIT_FAILURE;
//    }

    /*int ret = task_create("SensorPackageTask",
                          CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_PRIORITY,
                          CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_STACKSIZE,
                          sensorPackageTask,
                          nullptr);

    if(ret < 0) {
        int errcode = errno;

        printf("[State Machine] ERROR: Failed to start State Machine task: %d\n", errcode);

        return EXIT_FAILURE;
    }*/

    return EXIT_SUCCESS;
}