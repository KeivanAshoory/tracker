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
#include "Client.h"
#include "GeneralCommander.h"
#include "GeneralMonitor.h"
#include "GeneralPositionHandler.h"

class ClientManager
{
    public:
        ClientManager(const std::string& config);
        ~ClientManager();

        void setGeneralCommander(GeneralCommander* pGeneral);
        void setGeneralMonitor(GeneralMonitor* pGeneral);
        void setGeneralPositionHandler(GeneralPositionHandler* pGeneral);

        void createClients(const std::string& clientsSpec);

    private:
        GeneralCommander* mpGeneralCommander;
        GeneralMonitor* mpGeneralMonitor;
        GeneralPositionHandler* mpGeneralPositionHandler;

        std::list<Client*> mpClients;

        static Client* createClient(const std::string& clientSpec);

        ClientManager(const ClientManager& other);
        ClientManager& operator=(const ClientManager& other);

};

#endif
