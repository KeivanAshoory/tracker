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

#include <signal.h>
#include "Logger.h"
#include "Application.h"

volatile static sig_atomic_t isQuitRequested = 0;

void sigIntHandler(int signal)
{
    if(Logger::isInitialised()) {
        Logger::info("Caught signal SIGINT");
    }
    isQuitRequested = signal;
}

int main()
{
    signal(SIGINT, sigIntHandler);

    Logger::init(Logger::DESTINATION_SYSLOG,    //Use Linux syslog
            Logger::LEVEL_ERROR,    //Log level
            Logger::LEVEL_DEBUG,    //Console level
            "tracker",  //Log identifier
            "");    //Log file path

    Logger::info("tracker started.");

    Application* pApp = Application::getInstance();
    pApp->onStart();

    while(isQuitRequested != SIGINT) {
        usleep(100000);
        pApp->tempOnTick();
    }

    pApp->onTerminate();
    Logger::info("tracker stopped.");

    delete pApp;    //TODO Is that okay?! should we delete it in this way?
    return 0;
}
