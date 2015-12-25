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

#include "ClientManager.h"
#include "ClientFactory.h"

using namespace std;

ClientManager::ClientManager(const string& config):
    mpGeneralCommander(NULL), mpGeneralMonitor(NULL),
    mpGeneralPositionHandler(NULL)
{

}

ClientManager::~ClientManager()
{
    // TODO Check the logic: all of them are valid to delete?!
    for(std::list<Client*>::const_iterator
            it = mpClients.begin(); it != mpClients.end(); ++it) {
        delete (*it);
    }
}

void ClientManager::createClients(const string& clientsSpec)
{
    Client* client;

    client = createClient("Console");
    if(client == NULL) {
        //TODO
    }
    mpClients.push_back(client);
    client->registerCommandRequestListener(mpGeneralCommander);
    mpGeneralMonitor->registerStatusListener(client);
    mpGeneralPositionHandler->registerPositionListener(client);

    client = createClient("PushButton");
    if(client == NULL) {
        //TODO
    }
    mpClients.push_back(client);
    client->registerCommandRequestListener(mpGeneralCommander);
}

Client* ClientManager::createClient(const string& clientSpec)
{
    if(clientSpec == "Console") {
        Client* pClient = ClientFactory::create(ClientFactory::CONSOLE_CLIENT);
        return pClient;

    } else if(clientSpec == "PushButton") {
        Client* pClient = ClientFactory::create(ClientFactory::PUSH_BUTTON_CLIENT);
        return pClient;
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
