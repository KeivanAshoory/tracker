/*
 * =============================================================================
 *
 *       Filename:  StatusReporter.cc
 *
 *    Description:  StatusReporter base abstract class
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
#include "StatusReporter.h"

StatusReporter::StatusReporter()
{
    Logger::debug("StatusReporter::ctor");

}

StatusReporter::~StatusReporter()
{
    Logger::debug("StatusReporter::dtor");

}

void StatusReporter::registerStatusReportListener (const StatusReportListener* listener)
{
    mListeners.push_back(listener);
}

void StatusReporter::unregisterStatusReportListener(const StatusReportListener* listener)
{
    mListeners.remove(listener);
}

void StatusReporter::notifyStatusReport(int statusId) const
{
    for(std::list<const StatusReportListener*>::const_iterator
            it = mListeners.begin(); it != mListeners.end(); ++it) {
        (*it)->onNotifyStatusReport(statusId);
    }
}

