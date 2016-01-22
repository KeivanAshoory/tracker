/*
 * =============================================================================
 *
 *       Filename:  ClientManager.cc
 *
 *    Description:  Client manager
 *
 *        Version:  1.0
 *        Created:  16/12/15 21:09:48
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
#include "ClientManager.h"
#include "ClientFactory.h"

using namespace std;

ClientManager::ClientManager(const ClientManagerConfig& config):
    mpGeneralCommander(NULL), mpGeneralMonitor(NULL),
    mpGeneralPositionHandler(NULL)
{
    Logger::debug("ClientManager::ctor");

}

ClientManager::~ClientManager()
{
    Logger::debug("ClientManager::dtor");
    // TODO Check the logic: all of them are valid to delete?!
    for(std::list<Client*>::const_iterator
            it = mpClients.begin(); it != mpClients.end(); ++it) {
        Logger::info("ClientManager::dtor: Deleting a client.");

        delete (*it);
    }
}

void ClientManager::createClients(const ClientsConfig& clientsConfig)
{
    std::vector<ClientConfig> clientConfigs = clientsConfig.getClientConfigs();

    for(std::vector<ClientConfig>::iterator
            clientConfigIter = clientConfigs.begin();
            clientConfigIter != clientConfigs.end();
            ++clientConfigIter) {
        // Create a client.
        Logger::info("ClientManager::createClients: Creating a client.");

        Client* pClient = ClientFactory::create(*clientConfigIter);
        if(pClient == NULL) {
            Logger::error("Failed to create client!");
            continue;
        }

        mpClients.push_back(pClient);

        // Make connections
        std::vector<Client::Role> clientRoles = clientConfigIter->getRoles();
        if(!clientRoles.empty()) {
            for(std::vector<Client::Role>::iterator
                    roleIter = clientRoles.begin();
                    roleIter != clientRoles.end();
                    ++roleIter) {
                switch(*roleIter) {
                    case Client::Commander:
                        pClient->registerCommandRequestListener(
                                mpGeneralCommander);
                        break;
                    case Client::Monitor:
                        mpGeneralMonitor->registerStatusListener(pClient);
                        break;
                    case Client::PositionHandler:
                        mpGeneralPositionHandler->registerPositionListener(
                                pClient);
                        break;
                    case Client::UnknownRole:
                        Logger::error("An unknown role is defined for client!");
                        break;
                    default:
                        Logger::error("ClientManager::createClients: \
                                An undefined role is detected! \
                                We must not be here!");
                        assert(true);
                        break;
                }
            }

        } else {
            Logger::error("No role is defined for client!");
        }
    }
}

void ClientManager::setGeneralCommander(GeneralCommander* pGeneral)
{
    mpGeneralCommander = pGeneral;
}

void ClientManager::setGeneralMonitor(GeneralMonitor* pGeneral)
{
    mpGeneralMonitor = pGeneral;
}

void ClientManager::setGeneralPositionHandler(GeneralPositionHandler* pGeneral)
{
    mpGeneralPositionHandler = pGeneral;
}
