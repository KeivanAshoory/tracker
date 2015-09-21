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

class Nmea0183 {
    private:
        enum ReceiverState {
            WaitForStartOfMessage,
            ReceivingMessage,
            ReceivingCRCByte0,
            ReceivingCRCByte1,
            ReceivingEndOfMessageByte0,
            ReceivingEndOfMessageByte1 
        };
        static const char START_OF_MESSAGE = '$';
        static const char START_OF_CRC = '*';
        static const char END_OF_MESSAGE_BYTE0 = '\r';
        static const char END_OF_MESSAGE_BYTE1 = '\n';

    public:
        Nmea0183();
        ~Nmea0183();

    protected:
        void resetReceiver();
        void onDataReceive(char *buffer, int count);

    private:
        ReceiverState mReceiverState;
        std::string mFields;
        char mCRC[2];

        void onNmeaMessageReceive();
        void onXMessageReceive();

        bool validateCRC();
};
