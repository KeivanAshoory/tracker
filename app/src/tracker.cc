/*
 * =============================================================================
 *
 *       Filename:  tracker.cc
 *
 *    Description:  This is the main source code of the tracer application
 *
 *        Version:  1.0
 *        Created:  02/09/15 22:23:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  none
 *
 * =============================================================================
 */

#include <Logger.h>
#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <VK162.h>

using namespace std;

volatile static sig_atomic_t isQuitRequested = 0;

void sigIntHandler(int signal) {
    if(Logger::isInitialised()) {
        Logger::info("Caught signal SIGINT");
    }
    isQuitRequested = signal;
}

int main() {
    signal(SIGINT, sigIntHandler);

    Logger::init(Logger::DESTINATION_SYSLOG,    //Use Linux syslog
            Logger::LEVEL_ERROR,    //Log level
            Logger::LEVEL_DEBUG,    //Console level
            "tracker",  //Log identifier
            "");    //Log file path

    Logger::info("tracker started.");

    VK162 gps;
    gps.setSerialDevice("/dev/ttySAC1");
    if(!gps.openSerial(VK162::Asynchronous)) {
        Logger::fatal("Failed to open serial port!");
        return -1;
    }

    Logger::info("Serial port opened successfully.");

    while(isQuitRequested != SIGINT) {
        usleep(100000);
        if(gps.isDataAvailable()) {
            if(gps.readSerial()) {
            }
        }
    }

    Logger::info("tracker stopped.");

    return 0;
}

