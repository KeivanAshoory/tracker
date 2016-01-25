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

#ifndef VK162_H
#define VK162_H

#include <termios.h>
#include <Nmea0183.h>

class VK162 : Nmea0183
{
    //TODO This class is not designed in proper way and must be redesigned!
     public:
        enum SyncMode {
            Synchronous,
            Asynchronous
        };

        VK162(std::string deviceName);
        ~VK162();

        std::string getSerialDevice();

        bool openSerial(SyncMode syncMode);
        bool closeSerial();
        bool isSerialOpen() const;

        bool isDataAvailable() const;
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

#endif
