/*
 * =============================================================================
 *
 *       Filename:  ClientManager.h
 *
 *    Description:  Client manager
 *
 *        Version:  1.0
 *        Created:  16/12/15 21:10:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include <string>

class ClientManager
{
    //TODO I think it must be a singletone
    public:
        ClientManager();
        ~ClientManager();

        void createClients(std::string clientsSpec);

    protected:
        void createClient(std::string clientSpec);
};

#endif
