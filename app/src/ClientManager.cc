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
        delete (*it);
    }
}

void ClientManager::createClients(const ClientsConfig& clientsConfig)
{
//    Client* client;
//
//    client = createClient("Console");
//    if(client == NULL) {
//        //TODO
//    }
//    mpClients.push_back(client);
//    client->registerCommandRequestListener(mpGeneralCommander);
//    mpGeneralMonitor->registerStatusListener(client);
//    mpGeneralPositionHandler->registerPositionListener(client);
//
//    client = createClient("PushButton");
//    if(client == NULL) {
//        //TODO
//    }
//    mpClients.push_back(client);
//    client->registerCommandRequestListener(mpGeneralCommander);
}

Client* ClientManager::createClient(const ClientConfig& clientConfig)
{
//    if(clientSpec == "Console") {
//        Client* pClient = ClientFactory::create(Client::Console);
//        return pClient;
//
//    } else if(clientSpec == "PushButton") {
//        Client* pClient = ClientFactory::create(Client::PushButton);
//        return pClient;
//    }

    Client* pClient = ClientFactory::create(Client::Console);
    return pClient;
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
