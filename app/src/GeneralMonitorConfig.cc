/*
 * =============================================================================
 *
 *       Filename:  GeneralMonitorConfig.cc
 *
 *    Description:  GeneralMonitorConfig
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
#include "GeneralMonitorConfig.h"
#include "Config.h"

GeneralMonitorConfig::GeneralMonitorConfig(ConfigSegment* pConfigSegment) : 
    ComponentConfig(pConfigSegment)
{
    Logger::debug("GeneralMonitorConfig::ctor");

}

GeneralMonitorConfig::~GeneralMonitorConfig()
{
    Logger::debug("GeneralMonitorConfig::dtor");

}
