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
#include "ClientsConfig.h"
#include "ClientManagerConfig.h"
#include "GeneralPositionHandler.h"

class ClientManager
{
    public:
        ClientManager(const ClientManagerConfig& config);
        ~ClientManager();

        void setGeneralCommander(GeneralCommander* pGeneral);
        void setGeneralMonitor(GeneralMonitor* pGeneral);
        void setGeneralPositionHandler(GeneralPositionHandler* pGeneral);

        void createClients(const ClientsConfig& clientsConfig);

    private:
        GeneralCommander* mpGeneralCommander;
        GeneralMonitor* mpGeneralMonitor;
        GeneralPositionHandler* mpGeneralPositionHandler;

        std::list<Client*> mpClients;

        static Client* createClient(const ClientConfig& clientConfig);

        ClientManager(const ClientManager& rhs);
        ClientManager& operator=(const ClientManager& rhs);

};

#endif
