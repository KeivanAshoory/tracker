/*
 * =============================================================================
 *
 *       Filename:  GeneralCommanderConfig.cc
 *
 *    Description:  GeneralCommanderConfig
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
#include "GeneralCommanderConfig.h"
#include "Config.h"

GeneralCommanderConfig::GeneralCommanderConfig(ConfigSegment* pConfigSegment) : 
    ComponentConfig(pConfigSegment)
{
    Logger::debug("GeneralCommanderConfig::ctor");

}

GeneralCommanderConfig::~GeneralCommanderConfig()
{
    Logger::debug("GeneralCommanderConfig::dtor");

}
