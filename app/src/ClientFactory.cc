/*
 * =============================================================================
 *
 *       Filename:  ClientFactory.cc
 *
 *    Description:  Client factory
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

#include "ConsoleClient.h"
#include "PushButtonClient.h"
#include "Client.h"
#include "ClientFactory.h"

using namespace std;

Client* ClientFactory::create(Client::Type clientType)
{
    switch(clientType) {
        case Client::Console:
            return new ConsoleClient;
        case Client::PushButton:
            return new PushButtonClient;
            break;
        default:
            return NULL;

    }
    
}
