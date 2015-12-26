/*
 * =============================================================================
 *
 *       Filename:  GeneralMonitor.cc
 *
 *    Description:  GeneralMonitor
 *
 *        Version:  1.0
 *        Created:  12/12/15 20:12:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#include "Logger.h"
#include "GeneralMonitor.h"

using namespace std;

GeneralMonitor::GeneralMonitor(const string& config)
{
    Logger::info("GeneralMonitor::ctor");

}

GeneralMonitor::~GeneralMonitor()
{
    Logger::info("GeneralMonitor::dtor");

}

void GeneralMonitor::registerStatusListener (const StatusListener* listener)
{
    mListeners.push_back(listener);
}

void GeneralMonitor::unregisterStatusListener(const StatusListener* listener)
{
    mListeners.remove(listener);
}

void GeneralMonitor::notifyStatus(int statusId) const
{
    Logger::info("GeneralMonitor::notifyStatus: notify status " );

    for(std::list<const StatusListener*>::const_iterator
            it = mListeners.begin(); it != mListeners.end(); ++it) {
        (*it)->onNotifyStatus(statusId);
    }
}

void GeneralMonitor::onNotifyStatusReport(int statusId) const
{
    Logger::info("GeneralMonitor::onNotifyStatusReport: " );

    notifyStatus(statusId);
}
