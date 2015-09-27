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
#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <VK162.h>

using namespace std;

volatile static sig_atomic_t isQuitRequested = 0;

void sigIntHandler(int signal) {
    isQuitRequested = signal;
}

int main() {
    signal(SIGINT, sigIntHandler);

    cout << "tracker started." << endl;

    VK162 gps;
    gps.setSerialDevice("/dev/ttySAC1");
    if(!gps.openSerial(VK162::Asynchronous)) {
        cout << "Failed to open serial port!" << endl;
        return -1;
    } 

    cout << "Serial port opened successfully." << endl;

    while(isQuitRequested != SIGINT) {
        usleep(100000);
        if(gps.isDataAvailable()) {
            if(gps.readSerial()) {
                //cout << "Received something!" << endl;
            }
        }
    }

    cout << "tracker stopped!" << endl; 

    return 0;
}

