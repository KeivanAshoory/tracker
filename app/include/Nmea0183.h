/*
 * =============================================================================
 *
 *       Filename:  Nmea0183.h
 *
 *    Description:  NEMA 0183
 *
 *        Version:  1.0
 *        Created:  10/09/15 19:35:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  none
 *
 * =============================================================================
 */

#ifndef NMEA0183_H
#define NMEA0183_H

#include <vector>

class Nmea0183
{
    public:
        Nmea0183();
        ~Nmea0183();

   protected:
        void resetReceiver();
        void onDataReceive(char *buffer, int count);

    private:
        enum ReceiverState {
            WaitForStartOfMessage,
            ReceivingFields,
            ReceivingCRCByte0,
            ReceivingCRCByte1,
            ReceivingEndOfMessageByte0,
            ReceivingEndOfMessageByte1
        };
        static const char START_OF_MESSAGE = '$';
        static const char START_OF_CRC = '*';
        static const char END_OF_MESSAGE_BYTE0 = '\r';
        static const char END_OF_MESSAGE_BYTE1 = '\n';

        ReceiverState mReceiverState;
        std::string mFields;
        char mCRC[2];

        void onNmeaMessageReceive();

        void onRMCReceive(std::vector<std::string> dataFields); //TODO reference &?
        void onVTGReceive(std::vector<std::string> dataFields);
        void onGSVReceive(std::vector<std::string> dataFields);
        void onGGAReceive(std::vector<std::string> dataFields);
        void onGLLReceive(std::vector<std::string> dataFields);

        void onGSAReceive(std::vector<std::string> dataFields);
        void onMSSReceive(std::vector<std::string> dataFields);
        void onZDAReceive(std::vector<std::string> dataFields);
        void onPSRF140Receive(std::vector<std::string> dataFields);
        void onPSRF150Receive(std::vector<std::string> dataFields);
        void onPSRF151Receive(std::vector<std::string> dataFields);
        void onPSRF152Receive(std::vector<std::string> dataFields);
        void onPSRF154Receive(std::vector<std::string> dataFields);
        void onPSRF155Receive(std::vector<std::string> dataFields);

        bool validateCRC();
        static std::vector<std::string> parseFields(std::string fields);
};

#endif
