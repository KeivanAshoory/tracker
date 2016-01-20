/*
 * =============================================================================
 *
 *       Filename:  ClientsConfig.cc
 *
 *    Description:  ClientsConfig
 *
 *        Version:  1.0
 *        Created:  27/12/15 20:39:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#include <vector>
#include "Logger.h"
#include "ClientsConfig.h"

ClientsConfig::ClientsConfig(ConfigSegment* pConfigSegment) : 
    ComponentConfig(pConfigSegment)
{
    Logger::debug("ClientsConfig::ctor");

}

ClientsConfig::~ClientsConfig()
{
    Logger::debug("ClientsConfig::dtor");

}

std::vector<ClientConfig> ClientsConfig::getClientConfigs() const
{
    // It returns empty vector in case that there is no sequence of segments.
    std::vector<ConfigSegment*> configSegments =
        mpConfigSegment->getSegmentArray();

    std::vector<ClientConfig> clientConfigs;

    for(std::vector<ConfigSegment*>::iterator it = configSegments.begin();
            it != configSegments.end(); ++it) {
        clientConfigs.push_back(ClientConfig(*it));
    }
    
    return clientConfigs;
}
