/*
 * =============================================================================
 *
 *       Filename:  PositionReporter.cc
 *
 *    Description:  PositionReporter base abstract class
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

#include "PositionReporter.h"

PositionReporter::PositionReporter()
{

}

PositionReporter::~PositionReporter()
{

}

void PositionReporter::registerPositionReportListener (const PositionReportListener* listener)
{
    mListeners.push_back(listener);
}

void PositionReporter::unregisterPositionReportListener(const PositionReportListener* listener)
{
    mListeners.remove(listener);
}

void PositionReporter::notifyPositionReport(int positionId) const
{
    for(std::list<const PositionReportListener*>::const_iterator
            it = mListeners.begin(); it != mListeners.end(); ++it) {
        (*it)->onNotifyPositionReport(positionId);
    }
}

