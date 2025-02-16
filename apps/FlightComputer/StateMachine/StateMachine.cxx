#include <nuttx/config.h>
#include <nuttx/init.h>
#include "stdio.h"
#include <mqueue.h>
#include <sys/types.h>
#include <fcntl.h>
#include "stdlib.h"
#include <unistd.h>
// #include "../FlightLib/FlightConfig.h"
// #include "../FlightLib/SensorData.h"
#include "../FlightLib/SensorData.h"
#include "../FlightLib/FlightConfig.h"



static int stateMachineTask(int argc, char *argv[]) {

    /* -- Open Message Queues from other FC Processes -- */

    mqd_t lsmQueue = mq_open("/lsmQueue", O_RDONLY | O_NONBLOCK);
    if(lsmQueue == (mqd_t)-1) {
//        printf("[State Machine] Error: Unable to open LSM queue...\n");
//        return EXIT_FAILURE;
    }

    lsm_data_t lsmData{};

    // Open IMU queue
//    mqd_t imuQueue = mq_open("/imuQueue", O_RDONLY | O_NONBLOCK);
//    if(imuQueue == (mqd_t)-1) {
//        printf("[State Machine] Error: Unable to open IMU queue...\n");
//        return EXIT_FAILURE;
//    }
//
//    // Open mag queue
//    mqd_t magQueue = mq_open("/magQueue", O_RDONLY | O_NONBLOCK);
//    if(magQueue == (mqd_t)-1) {
//        printf("[State Machine] Error: Unable to open MAG queue...\n");
//        return EXIT_FAILURE;
//    }
//
//    // Open GPS queue
//    mqd_t gpsQueue = mq_open("/gpsQueue", O_RDONLY | O_NONBLOCK);
//    if(gpsQueue == (mqd_t)-1) {
//        printf("[State Machine] Error: Unable to open GPS queue...\n");
//        return EXIT_FAILURE;
//    }
//
//    // Open baro queue
//    mqd_t baroQueue = mq_open("/baroQueue", O_RDONLY | O_NONBLOCK);
//    if(baroQueue == (mqd_t)-1) {
//        printf("[State Machine] Error: Unable to open BARO queue...\n");
//        return EXIT_FAILURE;
//    }

    // Allocate memory for data storage
//    imu_data_t imuData{};
//    mag_data_t magData{};
//    gps_data_t gpsData{};
//    baro_data_t baroData{};
    struct timespec ts{};

    while(1) {

        // Grab high-precision time clock
        clock_gettime(CLOCK_MONOTONIC, &ts);

        uint32_t timestamp = (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);

        if(mq_receive(lsmQueue, (char *)&lsmData, sizeof(lsm_data_t), nullptr) == -1) {
            if(errno != EAGAIN) {
                printf("[State Machine] Error: Not receiving LSM303 data...\n");
            }
        }

        printf("%f, %f, %f", lsmData.accel_x, lsmData.accel_y, lsmData.accel_z);

//        if(mq_receive(imuQueue, (char *)&imuData, sizeof(imu_data_t), nullptr) == -1) {
//            if (errno != EAGAIN) {
//                printf("[State Machine] Error: Not receiving IMU data...\n");
//            }
//        }
//
//        if(mq_receive(magQueue, (char *)&magData, sizeof(mag_data_t), nullptr) == -1) {
//            if (errno != EAGAIN) {
//                printf("[State Machine] Error: Not receiving MAG data...\n");
//            }
//        }
//
//        if(mq_receive(gpsQueue, (char *)&gpsData, sizeof(gps_data_t), nullptr) == -1) {
//            if (errno != EAGAIN) {
//                printf("[State Machine] Error: Not receiving GPS data...\n");
//            }
//        }
//
//        if(mq_receive(baroQueue, (char *)&baroData, sizeof(baro_data_t), nullptr) == -1) {
//            if (errno != EAGAIN) {
//                printf("[State Machine] Error: Not receiving Baro data...\n");
//            }
//        }

        // Print CSV Formatted String
//        printf("%f, %f, %f, %f, %f, %f, %f, %li\n", imuData.accel_x, imuData.accel_y, imuData.accel_z, imuData.gyro_x, imuData.gyro_y, imuData.gyro_z, baroData.pressure, timestamp);

        // printf("Accel Z: %f\n", imuData.accel_z);
//        printf("Gyro Y: %f\n", imuData.gyro_y);
//        printf("Mag Z: %f\n", magData.mag_z);
//        printf("GPS Satellites: %i\n", gpsData.gps_numSats);
        // printf("Baro Pressure: %f\n", baroData.pressure);
        // printf("Baro Temp: %i\n", baroData.temperature);


        // Convert Hz to microseconds
        usleep(1e6 / stateMachine_loopRate);
    }

    printf("[Flight Computer] Task Terminated...\n");

    return EXIT_FAILURE;
}

extern "C" int FC_StateMachine_main(int argc, char *argv[]) {
	printf("Starting Flight Computer...\n");

    int ret = task_create("StateMachineTask",
                          CONFIG_FLIGHTCOMPUTER_STATEMACHINE_PRIORITY,
                          CONFIG_FLIGHTCOMPUTER_STATEMACHINE_STACKSIZE,
                          stateMachineTask,
                          nullptr);

    if(ret < 0) {
        int errcode = errno;

        printf("[State Machine] ERROR: Failed to start State Machine task: %d\n", errcode);

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}