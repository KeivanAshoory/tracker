/*
 * =============================================================================
 *
 *       Filename:  ConsoleClient.h
 *
 *    Description:  Console Client
 *
 *        Version:  1.0
 *        Created:  14/12/15 21:39:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef CONSOLE_CLIENT_H
#define CONSOLE_CLIENT_H

#include "ClientConfig.h"
#include "Client.h"

class ConsoleClient : public Client
{
    public:
        ConsoleClient(const ClientConfig& config);
        ~ConsoleClient();

    protected:
        // Override Client
        void onNotifyMonitorEvent(int eventId) const;
        void onNotifyPositionEvent(int position) const;
};

#endif
