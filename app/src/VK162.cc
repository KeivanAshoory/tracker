/*
 * =============================================================================
 *
 *       Filename:  VK162.cc
 *
 *    Description:  GPS driver
 *
 *        Version:  1.0
 *        Created:  03/09/15 20:34:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  none
 *
 * =============================================================================
 */

#include <fcntl.h>
#include <termios.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <cstring>
#include <iostream>
#include "Logger.h"
#include "VK162.h"

using namespace std;

bool VK162::sIsDataAvailable = false;   //TODO sig_atomic_t??

VK162::VK162()
{
    Logger::info("VK162::constructor");
    mIsSerialOpen = false;
    VK162::sIsDataAvailable = false;
    mSerialDeviceName = "";
}

VK162::~VK162()
{
    Logger::info("VK162::destructor");
    if(mIsSerialOpen) {
        if(!closeSerial()) {
            //unable to close the port
            //TODO: what next?
        }
    }
}

bool VK162::openSerial(VK162::SyncMode syncMode)
{
    if(mIsSerialOpen) {
        //TODO: do something!
        Logger::error("Serial port is already open!");
        return false;
    }

    if(mSerialDeviceName.empty()) {
        //TODO: do something!
        Logger::error("Device name is empty!");
        return false;
    }

    switch(syncMode) {
        case Asynchronous:
            mFileDescriptor = open(mSerialDeviceName.c_str(),
                    O_RDWR | O_NOCTTY | O_NONBLOCK);
            if(mFileDescriptor >= 0) {
                //succeeded to open the port
                //install the signal handler
                struct sigaction saio;
                saio.sa_handler = &VK162::signalHandler;
                sigemptyset(&saio.sa_mask);     //saio.sa_mask = 0;
                saio.sa_flags = 0;
                saio.sa_restorer = NULL;
                sigaction(SIGIO, &saio, NULL);

                //allow the process to receive SIGIO
                if(fcntl(mFileDescriptor, F_SETOWN, getpid()) < 0) {
                    //TODO:
                    Logger::error("Failed to set the owner of file descriptor!");
                    return false;
                }

                //makes the file descriptor asynchronous
                if(fcntl(mFileDescriptor, F_SETFL, FASYNC) < 0) {
                    //TODO
                    Logger::error("Failed to make file descriptor asynchronous!");
                    return false;
                }

                //save the current setting of the serial port
                if(tcgetattr(mFileDescriptor, &mOldPortSetting) < 0) {
                    //TODO
                    Logger::error("Failed to get serial port setting!");
                    return false;
                }

                //set new port settings
                termios newPortSetting;
                memset(&newPortSetting, 0, sizeof(newPortSetting));
                //enable the receiver, ignore modem control lines, set 8-bit
                newPortSetting.c_cflag = CREAD | CLOCAL | CS8;
                //set baudrate to default, set bit number to 8
                newPortSetting.c_cflag = B9600 | CS8;
                //MIN=0 and TIME=0: read() returns immedediately with available
                //...data or without
                newPortSetting.c_cc[VMIN] = 0;
                newPortSetting.c_cc[VTIME] = 0;

                //flush the port input buffer
                if(tcflush(mFileDescriptor, TCIFLUSH) < 0) {
                    //TODO
                    Logger::error("Failed to flush serial port!");
                    return false;
                }

                //write new setting to the port
                if(tcsetattr(mFileDescriptor, TCSANOW, &newPortSetting) < 0) {
                    //TODO
                    Logger::error("Failed to set attribute of the file descriptor!");
                    return false;
                }

                mIsSerialOpen = true;
                VK162::sIsDataAvailable = false;
                resetReceiver();
                return true;
            } else {
                //failed to open the serial /ort
                //TODO:
                Logger::error("Failed to open the serial port!");
                return false;
            }

            break;
        case Synchronous:
            //TODO
            return false;
            break;
        default:
            //TODO:
            return false;
            break;
    }

}

bool VK162::closeSerial()
{
    if(!mIsSerialOpen) {
        //TODO: do something!
        return false;
    }

    //TODO: do we need to simehow dettach the signal handler?!

    //restore old setting
    tcsetattr(mFileDescriptor, TCSANOW, &mOldPortSetting);

    //close the serial port
    close(mFileDescriptor);

    mIsSerialOpen = false;
    VK162::sIsDataAvailable = false;
    return true;
}

bool VK162::readSerial()
{
    if(!mIsSerialOpen) {
        //TODO: do something!
        return false;
    }

    char readBuffer[MAXIMUM_READ_BYTE_NUMBER];
    int readCount = 0;

    while((readCount = read(mFileDescriptor,
                    readBuffer, MAXIMUM_READ_BYTE_NUMBER)) != 0) {
        //read some bytes, process them
        onDataReceive(readBuffer, readCount);
    }

    //no data available anymore
    VK162::sIsDataAvailable = false;
    //TODO you may need to make return value more useful,
    //It can be number of total read bytes
    return true;
}

void VK162::setSerialDevice(std::string device)
{
    mSerialDeviceName = device;
}

std::string VK162::getSerialDevice()
{
    return mSerialDeviceName;
}

bool VK162::isSerialOpen()
{
    return mIsSerialOpen;
}

bool VK162::isDataAvailable()
{
    //TODO convert to inline function?
    //TODO the variable is static, and the method is not!!
    return VK162::sIsDataAvailable;
}

void VK162::signalHandler(int status)
{
    //Logger::debug("SIGIO received.");
    sIsDataAvailable = true;
}
