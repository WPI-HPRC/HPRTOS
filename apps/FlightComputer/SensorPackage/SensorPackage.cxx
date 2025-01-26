#include <nuttx/config.h>
#include <nuttx/init.h>
#include "stdio.h"
#include <mqueue.h>
#include <sys/types.h>
#include <fcntl.h>
#include "stdlib.h"
#include <unistd.h>
#include "../FlightLib/SensorData.h"
#include "../FlightLib/FlightConfig.h"

#include "LPS25/LPS25.h"
#include "ICM42688/ICM42688.h"
#include "MS5611/MS5611.h"
#include "MAX10S/MAX10S.h"

#include "SensorPackage.h"

static int i2cBus = 0;

static int initSensorBus() {
    int ret = 0;

#ifdef CONFIG_FLIGHTCOMPUTER_STATEMACHINE_POLARIS
    i2cBus = open("/dev/i2c1", O_WRONLY);
#endif
#ifdef CONFIG_FLIGHTCOMPUTER_STATEMACHINE_STACK2024
    i2cBus = open("/dev/i2c0", O_WRONLY);
#endif
#ifdef CONFIG_FLIGHTCOMPUTER_STATEMACHINE_STMFC
    i2cBus = open("/dev/i2c1", O_WRONLY);
#endif

    if(i2cBus < 0) {
        printf("[State Machine] Error: Failed to initialize i2c...\n");

        ret = 0;
    } else {
        printf("[State Machine]: Initialized i2c!\n");
        ret = 1;
    }

    return ret;
}

static int imuTask(int argc, char *argv[]) {
    printf("[IMU] Spawning IMU process...\n");

    mq_attr attr = {
        .mq_maxmsg = 1,
        .mq_msgsize = sizeof(imu_data_t),
        .mq_flags = 0
    };

    mqd_t mqd = mq_open("/imuQueue", O_CREAT | O_WRONLY, 0644, &attr);
    if(mqd == (mqd_t)-1) {
        printf("[IMU] Error creating IMU queue...\n");
        return EXIT_FAILURE;
    }

    ICM42688 accel = ICM42688();

    accel.init(i2cBus);

    imu_data_t imuData{};

    while(1) {

        accel.getImuData(imuData);

        mq_send(mqd, (const char*)&imuData, sizeof(imuData), 0);

        usleep(1 / imu_looprate);
    }

    mq_close(mqd);
    mq_unlink("/imuQueue");

    return EXIT_SUCCESS;
}

static int magTask(int argc, char *argv[]) {
    printf("[MAG] Spawning magnetometer process...\n");

    mq_attr attr = {
        .mq_maxmsg = 1,
        .mq_msgsize = sizeof(mag_data_t),
        .mq_flags = 0
    };

    mqd_t mqd = mq_open("/magQueue", O_CREAT | O_WRONLY, 0644, &attr);
    if(mqd == (mqd_t)-1) {
        printf("[MAG] Error creating MAG queue...\n");
        return EXIT_FAILURE;
    }

    mag_data_t magData{};

    while(1) {
        magData = {
            .mag_x = 1.0,
            .mag_y = 2.0,
            .mag_z = 3.0
        };

        mq_send(mqd, (const char*)&magData, sizeof(magData), 0);

        usleep(1 / mag_looprate);
    }

    mq_close(mqd);
    mq_unlink("/magQueue");

    return EXIT_SUCCESS;
}

static int gpsTask(int argc, char *argv[]) {
    printf("[GPS] Spawning GPS process...\n");

    mq_attr attr = {
        .mq_maxmsg = 1,
        .mq_msgsize = sizeof(gps_data_t),
        .mq_flags = 0
    };

    mqd_t mqd = mq_open("/gpsQueue", O_CREAT | O_WRONLY, 0644, &attr);
    if(mqd == (mqd_t)-1) {
        printf("[IMU] Error creating MAG queue...\n");
        return EXIT_FAILURE;
    }

    MAX10S gps = MAX10S();

    gps.init(i2cBus);

    gps_data_t gpsData;

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

        gps.getNMEA();

        mq_send(mqd, (const char*)&gpsData, sizeof(gpsData), 0);

        usleep(1 / gps_looprate);
    }

    mq_close(mqd);
    mq_unlink("/gpsQueue");

    return EXIT_SUCCESS;
}

static int baroTask(int argc, char * argv[]) {
    printf("[BARO] Spawning BARO process...\n");

    mq_attr attr = {
        .mq_maxmsg = 1,
        .mq_msgsize = sizeof(baro_data_t),
        .mq_flags = 0
    };

    mqd_t mqd = mq_open("/baroQueue", O_CREAT | O_WRONLY, 0644, &attr);
    if(mqd == (mqd_t)-1) {
        printf("[BARO] Error creating barometer queue...\n");
        return EXIT_FAILURE;
    }

    baro_data_t baroData;

#ifdef CONFIG_FLIGHTCOMPUTER_STATEMACHINE_POLARIS
    MS5611 baro = MS5611();
    baro.init(i2cBus);
#endif
#ifdef CONFIG_FLIGHTCOMPUTER_STATEMACHINE_STACK2024
    LPS25 baro = LPS25();
    baro.init(i2cBus);
#endif
#ifdef CONFIG_FLIGHTCOMPUTER_STATEMACHINE_STMFC
    LPS25 baro = LPS25();
    baro.init(i2cBus);
#endif

    while(1) {


        baroData = {
                .pressure = 0,
                .temperature = 0
        };

//        baroData = {
//            .pressure = baro.getPressure(),
//            .temperature = baro.getTemperature()
//        };

        mq_send(mqd, (const char*)&baroData, sizeof(baroData), 0);

        usleep(1 / baro_looprate);
    }

    mq_close(mqd);
    mq_unlink("/baroQueue");

    return EXIT_SUCCESS;
}

extern "C" int FC_SensorPackage_main(int argc, char *argv[]) {
	printf("Starting Flight Sensor Package...\n");

    int ret = initSensorBus();

    ret = task_create("imuTask",
                          CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_PRIORITY,
                          CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_STACKSIZE,
                          imuTask,
                          nullptr
    );

    ret = task_create("magTask",
                          CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_PRIORITY,
                          CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_STACKSIZE,
                          magTask,
                          nullptr
    );

    ret = task_create("gpsTask",
                      CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_PRIORITY,
                      CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_STACKSIZE,
                      gpsTask,
                      nullptr
    );

    ret = task_create("baroTask",
                      CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_PRIORITY,
                      CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_STACKSIZE,
                      baroTask,
                      nullptr
    );

    if(ret <= 0) {
        const int errcode = errno;

        printf("[State Machine] ERROR: Failed to start State Machine task: %d\n", errcode);

        return EXIT_FAILURE;
    }

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