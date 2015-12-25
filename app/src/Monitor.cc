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

#include "Monitor.h"

Monitor::Monitor()
{

}

Monitor::~Monitor()
{

}

void Monitor::onNotifyStatus(int statusId) const
{
    //Do some extra work maybe
    onNotifyMonitorEvent(statusId);
}