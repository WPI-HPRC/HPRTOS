#pragma once

/** Vanguard Sensor Data */
typedef struct {
    float accel_x; // [g]
    float accel_y; // [g]
    float accel_z; // [g]
} adxl375_data_t;

typedef struct {
    float accel_x; // [g]
    float accel_y; // [g]
    float accel_z; // [g]
    float gyro_x;  // [dps]
    float gyro_y;  // [dps]
    float gyro_z;  // [dps]
} asm_data_t;

typedef struct {
    float accel_x; // [g]
    float accel_y; // [g]
    float accel_z; // [g]
    float mag_x;  // [Gauss]
    float mag_y;  // [Gauss]
    float mag_z;  // [Gauss]
} lsm_data_t;

typedef struct {
    // IMU Readings
    float accel_x; // [g]
    float accel_y; // [g]
    float accel_z; // [g]
    float gyro_x;  // [rad/s]
    float gyro_y;  // [rad/s]
    float gyro_z;  // [rad/s]
} imu_data_t;

typedef struct {
    float mag_x;
    float mag_y;
    float mag_z;
} mag_data_t;

typedef struct {
    // GPS Readings
    float gps_e_x;
    float gps_e_y;
    float gps_e_z;
    float gps_v_ned_x;
    float gps_v_ned_y;
    float gps_v_ned_z;
    uint8_t gps_numSats;
} gps_data_t;

typedef struct {
    float pressure; // [hPa]
    float altitude; // [m]
    uint16_t temperature; // [C]
} lps_data_t;