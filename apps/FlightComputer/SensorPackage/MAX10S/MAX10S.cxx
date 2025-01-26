#include "MAX10S.h"

#include <sys/param.h>

#include <cstring>

MAX10S::MAX10S()
{

}

int MAX10S::init(int i2cBus)
{
    this->fd = i2cBus;

    printf("[MAX10S] Successfully Initialized!\n");

    return true;
}

int16_t MAX10S::busWrite(uint8_t reg, uint8_t val) {
    int16_t ex;

    uint8_t txBuffer[2];

    txBuffer[0] = reg;
    txBuffer[1] = val;

    struct i2c_msg_s i2cMsg {
            .frequency = 320000,
            .addr = MAX10S_ADDR,
            .flags = 0,
            .buffer = txBuffer,
            .length = 2
    };

    struct i2c_transfer_s i2cTransfer {
            .msgv = &i2cMsg,
            .msgc = 1
    };

    ex = ioctl(fd, I2CIOC_TRANSFER, (unsigned long)(uintptr_t) &i2cTransfer);

    if(ex < 0) {
        printf("[MAX10S] Error: Failed to set register -> %d\n", ex);
    }

    return ex;
}

int16_t MAX10S::busRead(uint8_t reg, uint8_t *val, int8_t len) {
    int16_t ex;

    struct i2c_msg_s i2cMsg[2] = {
            {
                    .frequency = 320000,
                    .addr = MAX10S_ADDR,
                    .flags = 0,
                    .buffer = &reg,
                    .length = 1
            },
            {
                    .frequency = 320000,
                    .addr = MAX10S_ADDR,
                    .flags = I2C_M_READ,
                    .buffer = val,
                    .length = len
            }
    };

    struct i2c_transfer_s i2cTransfer = {
            .msgv = i2cMsg,
            .msgc = 2
    };

    ex = ioctl(fd, I2CIOC_TRANSFER, (unsigned long)(uintptr_t) &i2cTransfer);

//    if(ex < 0) {
//        printf("[MAX10S] Read Error: %d\n", ex);
//    }

    return ex;
}

sfe_ublox_status_e MAX10S::sendCommand(ubxPacket* outgoingPacket, uint16_t maxWait)
{
    uint16_t bytesToSend = outgoingPacket->len + 8;
    uint16_t bytesSent = 0;
    uint16_t bytesLeftToSend = bytesToSend;
    uint16_t startSpot = 0;

    uint8_t buffer[I2C_TRANSACTION_SIZE];

    while(bytesLeftToSend > 0)
    {
        uint16_t len = bytesLeftToSend;
        if(len > I2C_TRANSACTION_SIZE)
        {
            len = I2C_TRANSACTION_SIZE;
        }

        bytesLeftToSend -= len;

        if(bytesLeftToSend == 1)
        {
            len -= 1;
            bytesLeftToSend += 1;
        }

        uint16_t bufferIdx = 0;

        if(bytesSent == 0)
        {
            buffer[bufferIdx++] = UBX_SYNCH_1;
            buffer[bufferIdx++] = UBX_SYNCH_2;
            buffer[bufferIdx++] = outgoingPacket->cls;
            buffer[bufferIdx++] = outgoingPacket->id;
            buffer[bufferIdx++] = outgoingPacket->len & 0xFF;
            buffer[bufferIdx++] = outgoingPacket->len >> 8;

            bytesSent += 6;

            uint16_t x = 0;
            for(; (x < outgoingPacket->len) && (bytesSent < len); x++)
            {
                buffer[bufferIdx++] = outgoingPacket->payload[startSpot + x];
                bytesSent++;
            }
            startSpot += x;

            if(bytesSent == (len - 2))
            {
                buffer[bufferIdx++] = outgoingPacket->checksumA;
                buffer[bufferIdx++] = outgoingPacket->checksumB;
                bytesSent += 2;
            }

        } else {
            uint16_t x = 0;

            for(; (x < len) && ((startSpot + x) < (outgoingPacket->len)); x++)
            {
                buffer[bufferIdx++] = outgoingPacket->payload[startSpot + x];
                bytesSent++;
            }
            startSpot += x;

            if((bytesSent == (bytesToSend - 2)) && (x == (len - 2)))
            {
                buffer[bufferIdx++] = outgoingPacket->checksumA;
                buffer[bufferIdx++] = outgoingPacket->checksumB;
                bytesSent += 2;
            }
        }

        struct i2c_msg_s i2cMsg {
                .frequency = 320000,
                .addr = MAX10S_ADDR,
                .flags = 0,
                .buffer = buffer,
                .length = bufferIdx
        };

        struct i2c_transfer_s i2cTransfer {
                .msgv = &i2cMsg,
                .msgc = 1
        };

        int ex = ioctl(fd, I2CIOC_TRANSFER, (unsigned long)(uintptr_t) &i2cTransfer);

        if (ex < 0) {
            printf("[UBLOX] Error: Failed to send I2C command -> %d\n", ex);
            return SFE_UBLOX_STATUS_I2C_COMM_FAILURE;
        }
    }

    return SFE_UBLOX_STATUS_SUCCESS;
}

char* MAX10S::getNMEA() {
    uint8_t buffer[128];
    int ret;
    int index = 0;

    bool messageComplete = false;

    while(!messageComplete) {
        ret = busRead(0xFF, &buffer[index], 1);

        if(buffer[index] == START_DELIM || buffer[index] == ENCAPSULATION_SENTENCE_START) {
            index = 0;
        }

        if(index < 128-1) {
            index++;
        } else {
            index = 0;
        }

        if(buffer[index-1] == '\n' && buffer[index-2] == '\r') {
            buffer[index] = '\0';
//            printf("%s", buffer);
            messageComplete = true;
        }

    }

    return reinterpret_cast<char *>(buffer);

}