/*
 * =============================================================================
 *
 *       Filename:  RootConfig.cc
 *
 *    Description:  Root configuration
 *
 *        Version:  1.0
 *        Created:  27/12/15 21:03:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#include "RootConfig.h"

RootConfig::RootConfig()
{

}

RootConfig::~RootConfig()
{

}

ClientManagerConfig RootConfig::getClientManagerConfig() const
{
    // in mapping find the node which is mapped to "ClientManager"
    // 1) hasComponent("ClientManager")
    // 2) isMap("ClientManager")
    // 3) getMap/Component("ClientManager") as map

}

std::vector<ClientConfig> RootConfig::getClientsConfig() const
{
    // in mapping find the node which is mapped to "Clients"
    // 1) hasComponent("Clients")
    // 2) isSequence("Clients")
    // 3) getSeq/Component("Clients") as seq

}
