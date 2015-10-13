/*
 * =============================================================================
 *
 *       Filename:  VK162.h
 *
 *    Description:  VK162 GPS Module
 *
 *        Version:  1.0
 *        Created:  08/09/15 22:48:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  none
 *
 * =============================================================================
 */

#include <termios.h>
#include <Nmea0183.h>

class VK162 : Nmea0183 {
     public:
        enum SyncMode {
            Synchronous,
            Asynchronous
        };

        VK162();
        ~VK162();

        void setSerialDevice(std::string deviceName);
        std::string getSerialDevice();

        bool openSerial(SyncMode syncMode);
        bool closeSerial();
        bool isSerialOpen();

        bool isDataAvailable();
        bool readSerial();

    private:
        static const int MAXIMUM_READ_BYTE_NUMBER = 255;

        int mFileDescriptor;
        bool mIsSerialOpen;
        std::string mSerialDeviceName;
        termios mOldPortSetting;

        static bool sIsDataAvailable;   //TODO sig_atomic_t ??
        static void signalHandler(int status);

};

