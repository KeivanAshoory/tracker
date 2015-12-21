/*
 * =============================================================================
 *
 *       Filename:  Client.h
 *
 *    Description:  Client absract super class
 *
 *        Version:  1.0
 *        Created:  12/12/15 19:12:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef CLIENT_H
#define CLIENT_H

#include "ClientControl.h"
#include "Monitor.h"
#include "Commander.h"
#include "PositionHandler.h"

class Client : public ClientControl,
    public Monitor, public Commander, public PositionHandler
{
    public:
        virtual ~Client() = 0;
        virtual void onNotifyMonitorEvent(int eventId) const;
        virtual void onNotifyPositionEvent(int position) const;

    protected:
        Client();
};

#endif
