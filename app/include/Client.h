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
//#include "ClientConfig.h"
#include "Monitor.h"
#include "Commander.h"
#include "PositionHandler.h"

class ClientConfig; // Cannot include Client.h and ClientConfig.h recursively.

class Client : public ClientControl,
    public Monitor, public Commander, public PositionHandler
{
    public:
        enum Type {
            UndefinedType,  // No type is defined in config
            UnknownType,    // The defined type is unknown
            Console,
            PushButton
        };

        enum Role {
            UnknownRole,    // The defined role is unknown
            Commander,
            Monitor,
            PositionHandler
        };

        virtual ~Client() = 0;

    protected:
        Client(const ClientConfig& config);

        // Implement Monitor
        virtual void onNotifyMonitorEvent(int eventId) const;

        // Implement PositionHandler
        virtual void onNotifyPositionEvent(int position) const;
};

#endif
