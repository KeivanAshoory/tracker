/*
 * =============================================================================
 *
 *       Filename:  Client.cc
 *
 *    Description:  Client absract super class
 *
 *        Version:  1.0
 *        Created:  12/12/15 19:09:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#include <Client.h>

Client::Client()
{

}

Client::~Client()
{

}

void Client::onNotifyMonitorEvent(int eventId) const
{
    //This is the default implementation for clients that does not suport this
}

void Client::onNotifyPositionEvent(int position) const
{
    //This is the default implementation for clients that does not suport this
}
