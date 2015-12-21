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

#include "GeneralMonitor.h"

GeneralMonitor::GeneralMonitor()
{

}

GeneralMonitor::~GeneralMonitor()
{

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
    for(std::list<const StatusListener*>::const_iterator
            it = mListeners.begin(); it != mListeners.end(); ++it) {
        (*it)->onNotifyStatus(statusId);
    }
}

