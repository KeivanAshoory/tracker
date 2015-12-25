/*
 * =============================================================================
 *
 *       Filename:  ConsoleClient.cc
 *
 *    Description:  Console Cient
 *
 *        Version:  1.0
 *        Created:  15/12/15 21:39:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#include "Logger.h"
#include "ConsoleClient.h"

ConsoleClient::ConsoleClient()
{

}

ConsoleClient::~ConsoleClient()
{

}

void ConsoleClient::onNotifyMonitorEvent(int eventId) const
{
    Logger::info("ConsoleClient::onNotifyMonitorEvent: " + eventId);

    static int counter = 0;
    counter++;
    if(counter >= 5) {
        notifyCommandRequest(55);
    }
}

void ConsoleClient::onNotifyPositionEvent(int position) const
{
    Logger::info("ConsoleClient::onNotifyPositionEvent: " + position);
}
