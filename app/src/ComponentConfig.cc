/*
 * =============================================================================
 *
 *       Filename:  ComponentConfig.cc
 *
 *    Description:  Component config base abstract class
 *
 *        Version:  1.0
 *        Created:  05/01/16 23:04:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#include "Logger.h"
#include "ComponentConfig.h"

ComponentConfig::ComponentConfig(ConfigSegment* pConfigSegment) : 
    mpConfigSegment(pConfigSegment)
{
    Logger::debug("ComponentConfig:ctor");
}

ComponentConfig::~ComponentConfig()
{
    Logger::debug("ComponentConfig:dtor");

    delete mpConfigSegment;
}

ComponentConfig::ComponentConfig(const ComponentConfig& rhs) :
    mpConfigSegment(rhs.mpConfigSegment->clone())
{
    Logger::debug("ComponentConfig:copy ctor");
}

ComponentConfig& ComponentConfig::operator=(const ComponentConfig& rhs)
{
    Logger::debug("ComponentConfig:copy assignment operator");

    if(this != &rhs) {
        ConfigSegment* pTempConfigSegment = rhs.mpConfigSegment->clone();

        // The above statement might crash or throw, so delete should be done
        // after that.
        delete mpConfigSegment;
        mpConfigSegment = pTempConfigSegment;
    }
    return *this;
}
bool ComponentConfig::isConfigured() const
{
    return mpConfigSegment == NULL ? false : true;
}
