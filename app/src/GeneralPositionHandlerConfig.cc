/*
 * =============================================================================
 *
 *       Filename:  GeneralPositionHandlerConfig.cc
 *
 *    Description:  GeneralPositionHandlerConfig
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
#include "GeneralPositionHandlerConfig.h"
#include "Config.h"

GeneralPositionHandlerConfig::GeneralPositionHandlerConfig(ConfigSegment* pConfigSegment) : 
    ComponentConfig(pConfigSegment)
{
    Logger::debug("GeneralPositionHandlerConfig::ctor");

}

GeneralPositionHandlerConfig::~GeneralPositionHandlerConfig()
{
    Logger::debug("GeneralPositionHandlerConfig::dtor");

}
