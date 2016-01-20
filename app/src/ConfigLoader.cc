/*
 * =============================================================================
 *
 *       Filename:  ConfigLoader.cc
 *
 *    Description:  Configuration loader base abstract class
 *
 *        Version:  1.0
 *        Created:  28/12/15 12:08:18
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
#include "ConfigLoader.h"

ConfigLoader::ConfigLoader()
{
    Logger::debug("ConfigLoader::ctor");

}

ConfigLoader::~ConfigLoader()
{
    Logger::debug("ConfigLoader::dtor");

}

ConfigSegment* ConfigLoader::getConfig(void) const
{
    // The Factory Method design pattern is used here. This method uses the 
    // pure vitual method LoadConfig to create an implementation of ConfigSegment;
    // e.g. YamlConfigSegment. A subclass of ConfigLoader will create a subclass of
    // ConfigSegment.

    ConfigSegment* pConfigSegment = loadConfig();
    return pConfigSegment;

}
