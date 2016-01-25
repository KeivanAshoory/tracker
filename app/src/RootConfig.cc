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

#include <stdlib.h>
#include "Logger.h"
#include "Config.h"
#include "ClientManagerConfig.h"
#include "ApplicationConfig.h"
#include "GeneralCommanderConfig.h"
#include "GeneralMonitorConfig.h"
#include "GeneralPositionHandlerConfig.h"
#include "PositionAcquirerConfig.h"
#include "ClientsConfig.h"
#include "RootConfig.h"

RootConfig::RootConfig(ConfigSegment* pConfigSegment) :
    ComponentConfig(pConfigSegment)
{
    Logger::debug("RootConfig::ctor");
    //TODO Is it necessary to validate ConfigSegment?! e.g. whether it is map?
}

RootConfig::~RootConfig()
{
    Logger::debug("RootConfig::dtor");

}

std::string RootConfig::getConfigVersion() const
{
    return mpConfigSegment->getProperty<std::string>(
            Config::PROPERTY_TAG_CONFIG_VERSION, "");
}
        
template <typename T>
T RootConfig::getConfig() const
{
    ConfigSegment* pConfigSegment =
        mpConfigSegment->getSegment(Config::getSegmentTag<T>());

    if(!pConfigSegment) {
        // Cannot load the configuration segment! Maybe there is no such segment
        // TODO Log something!
        Logger::info("Cannot load requested config segment!");
    }

    return T(pConfigSegment);
}

template ApplicationConfig RootConfig::getConfig() const;
template ClientManagerConfig RootConfig::getConfig() const;
template ClientsConfig RootConfig::getConfig() const;
template GeneralCommanderConfig RootConfig::getConfig() const;
template GeneralMonitorConfig RootConfig::getConfig() const;
template GeneralPositionHandlerConfig RootConfig::getConfig() const;
template PositionAcquirerConfig RootConfig::getConfig() const;
