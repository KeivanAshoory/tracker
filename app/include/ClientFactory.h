/*
 * =============================================================================
 *
 *       Filename:  ClientFactory.h
 *
 *    Description:  Client factory
 *
 *        Version:  1.0
 *        Created:  14/12/15 21:41:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef CLIENT_FACTORY_H
#define CLIENT_FACTORY_H

#include <string>
#include "Client.h"

class ClientFactory
{
    public:
        static Client* create(const ClientConfig& clientConfig);
};

#endif
