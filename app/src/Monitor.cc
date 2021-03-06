/*
 * =============================================================================
 *
 *       Filename:  Monitor.cc
 *
 *    Description:  Monitor base abstract class
 *
 *        Version:  1.0
 *        Created:  12/12/15 20:12:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan 
 *   Organization:  None
 *
 * =============================================================================
 */

#include "Logger.h"
#include "Monitor.h"

Monitor::Monitor()
{
    Logger::debug("Monitor::ctor");

}

Monitor::~Monitor()
{
    Logger::debug("Monitor::dtor");

}

void Monitor::onNotifyStatus(int statusId) const
{
    Logger::info("Monitor::onNotifyStatus: " );

    //Do some extra work maybe
    onNotifyMonitorEvent(statusId);
}
