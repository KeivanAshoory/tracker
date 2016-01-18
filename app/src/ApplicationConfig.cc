/*
 * =============================================================================
 *
 *       Filename:  ApplicationConfig.cc
 *
 *    Description:  ApplicationConfig
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

#include "ApplicationConfig.h"
#include "Config.h"

ApplicationConfig::ApplicationConfig(ConfigSegment* pConfigSegment) : 
    ComponentConfig(pConfigSegment)
{

}

ApplicationConfig::~ApplicationConfig()
{

}

std::string ApplicationConfig::getName() const
{
    return mpConfigSegment->getProperty<std::string>(
            Config::PROPERTY_TAG_APPLICATION_NAME, "");
}

std::string ApplicationConfig::getVersion() const
{
    return mpConfigSegment->getProperty<std::string>(
            Config::PROPERTY_TAG_APPLICATION_VERSION, "");
}
