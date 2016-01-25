/*
 * =============================================================================
 *
 *       Filename:  PositionAcquirerConfig.cc
 *
 *    Description:  PositionAcquirerConfig
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
#include "PositionAcquirerConfig.h"
#include "Config.h"

PositionAcquirerConfig::PositionAcquirerConfig(ConfigSegment* pConfigSegment) : 
    ComponentConfig(pConfigSegment)
{
    Logger::debug("PositionAcquirerConfig::ctor");

}

PositionAcquirerConfig::~PositionAcquirerConfig()
{
    Logger::debug("PositionAcquirerConfig::dtor");

}

std::string PositionAcquirerConfig::getDevice() const
{
    return mpConfigSegment->getProperty<std::string>(
            Config::PROPERTY_TAG_POSITION_ACQUIRER_DEVICE, "");
}
