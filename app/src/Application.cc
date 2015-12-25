/*
 * =============================================================================
 *
 *       Filename:  Application.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/12/15 19:07:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#include <cassert>
#include <new>
#include "Logger.h"
#include "Application.h"

Application* Application::mInstance = 0;

Application::Application() :
    mpGeneralCommander(NULL), mpGeneralMonitor(NULL),
    mpGeneralPositionHandler(NULL), mpClientManager(NULL),
    mIsStarted(false)
{

}

Application::~Application()
{
    onTerminate();
}

Application* Application::getInstance()
{
    if(!mInstance) {
        mInstance = new Application;
    }
    return mInstance;
}

bool Application::isStarted(void)
{
    return mIsStarted;
}

void Application::onStart(void)
{
    assert(!mIsStarted); // Only once!

    // 1) Read configuration
    // 2) Create objects
    // 3) Connect Generals to Manager
    // 4) Ask Manager to create clients
    // 5) Start data acquiring

    // 1) Read configuration

    // 2) Create objects
    mpGeneralCommander = new GeneralCommander("c");
    mpGeneralMonitor = new GeneralMonitor("c");
    mpGeneralPositionHandler = new GeneralPositionHandler("c");
    mpClientManager = new ClientManager("c");

    if(mpGeneralCommander == NULL || mpGeneralMonitor == NULL ||
            mpGeneralPositionHandler == NULL || mpClientManager == NULL) {
        // TODO Log something
        onTerminate();
        return;
    }
    
    // 3) Connect Generals to Manager
    mpClientManager->setGeneralCommander(mpGeneralCommander);
    mpClientManager->setGeneralMonitor(mpGeneralMonitor);
    mpClientManager->setGeneralPositionHandler(mpGeneralPositionHandler);

    // 4) Ask Manager to create clients
    mpClientManager->createClients("c");

    // 5) Start data acquiring

    mIsStarted = true;
}

void Application::onTerminate(void)
{
    // Warning: Do not check mIsStarted before deleting allocated objects
    delete mpGeneralCommander;
    delete mpGeneralMonitor;
    delete mpGeneralPositionHandler;
    delete mpGeneralMonitor;

    //TODO: Do more work here!
    mIsStarted = false;
}
