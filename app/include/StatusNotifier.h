/*
 * =============================================================================
 *
 *       Filename:  StatusNotifier.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/12/15 21:24:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef STATUS_NOTIFIER_H
#define STATUS_NOTIFIER_H

#include "StatusListener.h"

class StatusNotifier
{
    public:
        virtual ~StatusNotifier() {};
        virtual void registerStatusListener(
                const StatusListener* listener
                ) = 0;
        virtual void unregisterStatusListener(
                const StatusListener* listener
                ) = 0;
        virtual void notifyStatus(int StatusId) const = 0;
};

#endif
