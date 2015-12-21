/*
 * =============================================================================
 *
 *       Filename:  Monitor.h
 *
 *    Description:  Monitor base abstract class
 *
 *        Version:  1.0
 *        Created:  12/12/15 20:09:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef MONITOR_H
#define MONITOR_H

#include "StatusListener.h"

class Monitor : public StatusListener
{
    public:
        virtual ~Monitor() = 0;
        //Override observer method
        void onNotifyStatus(int StatusId) const;
        virtual void onNotifyMonitorEvent(int eventId) const = 0;

    protected:
        Monitor();
};

#endif
