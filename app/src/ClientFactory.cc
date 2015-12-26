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
#include "ClientFactory.h"

using namespace std;

Client* ClientFactory::create(ClientType clientId)
{
    switch(clientId) {
        case CONSOLE_CLIENT:
            return new ConsoleClient;
        case PUSH_BUTTON_CLIENT:
            return new PushButtonClient;
            break;
        default:
            return NULL;

    }
    
}
