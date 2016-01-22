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

#include <cassert>
#include "Logger.h"
#include "ClientConfig.h"
#include "ConsoleClient.h"
#include "PushButtonClient.h"
#include "Client.h"
#include "ClientFactory.h"

Client* ClientFactory::create(const ClientConfig& clientConfig)
{
    switch(clientConfig.getType()) {
        case Client::Console:
            return new ConsoleClient(clientConfig);
        case Client::PushButton:
            return new PushButtonClient(clientConfig);
            break;
        case Client::UnknownType:
            Logger::error("An unknown type is defined for client!");
            return NULL;
        case Client::UndefinedType:
            Logger::error("No type is defined for client!");
            return NULL;
        default:
            Logger::error("ClientFactory::create: \
                    An undefined type is detected! We must not be here!");
            assert(true);
            return NULL;

    }
    
}
