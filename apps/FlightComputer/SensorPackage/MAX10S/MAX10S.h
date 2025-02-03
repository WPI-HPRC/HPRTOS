#pragma once

#include <nuttx/config.h>

#include <cstdlib>
#include <cstdio>
#include <fcntl.h>
#include <sched.h>
#include <cerrno>
#include <sys/ioctl.h>
#include <nuttx/i2c/i2c_master.h>
#include <mqueue.h>

#include "../../FlightLib/SensorData.h"

#include "u-blox_config_keys.h"
#include "u-blox_registers.h"

#include <nshlib/nshlib.h>



#define I2C_TRANSACTION_SIZE 32


typedef enum
{
    SFE_UBLOX_STATUS_SUCCESS,
    SFE_UBLOX_STATUS_FAIL,
    SFE_UBLOX_STATUS_CRC_FAIL,
    SFE_UBLOX_STATUS_TIMEOUT,
    SFE_UBLOX_STATUS_COMMAND_NACK, // Indicates that the command was unrecognised, invalid or that the module is too busy to respond
    SFE_UBLOX_STATUS_OUT_OF_RANGE,
    SFE_UBLOX_STATUS_INVALID_ARG,
    SFE_UBLOX_STATUS_INVALID_OPERATION,
    SFE_UBLOX_STATUS_MEM_ERR,
    SFE_UBLOX_STATUS_HW_ERR,
    SFE_UBLOX_STATUS_DATA_SENT,     // This indicates that a 'set' was successful
    SFE_UBLOX_STATUS_DATA_RECEIVED, // This indicates that a 'get' (poll) was successful
    SFE_UBLOX_STATUS_I2C_COMM_FAILURE,
    SFE_UBLOX_STATUS_DATA_OVERWRITTEN // This is an error - the data was valid but has been or _is being_ overwritten by another packet
  } sfe_ublox_status_e;

typedef enum {
    SFE_UBLOX_PACKET_VALIDITY_NOT_VALID,
    SFE_UBLOX_PACKET_VALIDITY_VALID,
    SFE_UBLOX_PACKET_VALIDITY_NOT_DEFINED,
    SFE_UBLOX_PACKET_NOTACKNOWLEDGED // This indicates that we received a NACK
} sfe_ublox_packet_validity_e;

struct ubxPacket {
    uint8_t cls;
    uint8_t id;
    uint16_t len;          // Length of the payload. Does not include cls, id, or checksum bytes
    uint16_t counter;      // Keeps track of number of overall bytes received. Some responses are larger than 255 bytes.
    uint16_t startingSpot; // The counter value needed to go past before we begin recording into payload array
    uint8_t *payload;      // We will allocate RAM for the payload if/when needed.
    uint8_t checksumA;     // Given to us from module. Checked against the rolling calculated A/B checksums.
    uint8_t checksumB;
    sfe_ublox_packet_validity_e valid;           // Goes from NOT_DEFINED to VALID or NOT_VALID when checksum is checked
    sfe_ublox_packet_validity_e classAndIDmatch; // Goes from NOT_DEFINED to VALID or NOT_VALID when the Class and ID match the requestedClass and requestedID
};

class MAX10S {

public:
    MAX10S();

    int init(int i2cBus);

    int setConfigurationParameter(uint32_t configKey, uint8_t value);

    char* getNMEA();

    static int readTask(int argc, char **argv);

private:
    int16_t busWrite(uint8_t reg, uint8_t val);
    int16_t busRead(uint8_t reg, uint8_t *val, int8_t len);

    sfe_ublox_status_e sendCommand(ubxPacket *outgoingPacket, uint16_t maxWait);

    bool factoryDefault(uint16_t maxWait);

    int fd = 0;

    constexpr static uint8_t MAX10S_ADDR = 0x42;

    /* -- NMEA Constants -- */
    constexpr static uint8_t START_DELIM = '$';
    constexpr static uint8_t ENCAPSULATION_SENTENCE_START = '!';
};
