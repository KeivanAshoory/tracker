/*
 * =============================================================================
 *
 *       Filename:  Application.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/12/15 19:07:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef APPLICATION_H
#define APPLICATION_H

#include "GeneralCommander.h"
#include "GeneralMonitor.h"
#include "GeneralPositionHandler.h"
#include "ClientManager.h"
#include "PositionAcquirer.h"

class Application
{
    public:
        ~Application();

        static Application* getInstance();

        void onStart(void);
        void onTerminate(void);

        bool isStarted(void);

        void tempOnTick();
        void configTest(void);
        void configTest2(void);
    protected:
        Application();

    private:
        // Disable copy constructor assignment operator constructor
        Application(const Application& other);
        Application& operator=(const Application&);

        static Application* mInstance;

        GeneralCommander* mpGeneralCommander;
        GeneralMonitor* mpGeneralMonitor;
        GeneralPositionHandler* mpGeneralPositionHandler;
        ClientManager* mpClientManager;
        PositionAcquirer* mpPositionAcquirer;

        bool mIsStarted;
};

#endif
