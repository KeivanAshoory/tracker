/*
 * =============================================================================
 *
 *       Filename:  ClientManagerConfig.cc
 *
 *    Description:  ClientManagerConfig
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

#include "Logger.h"
#include "ClientManagerConfig.h"
#include "Config.h"

ClientManagerConfig::ClientManagerConfig(ConfigSegment* pConfigSegment) : 
    ComponentConfig(pConfigSegment)
{
    Logger::debug("ClientManagerConfig::ctor");

}

ClientManagerConfig::~ClientManagerConfig()
{
    Logger::debug("ClientManagerConfig::dtor");

}

std::size_t ClientManagerConfig::getMaximumClientNumber() const
{
    return mpConfigSegment->getProperty<int>(
            Config::PROPERTY_TAG_CLIENT_MANAGER_MAX_CLIENT_NUMBER, 1);
}
