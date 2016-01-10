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
#include "Config.h"
#include "ClientManagerConfig.h"
#include "ClientsConfig.h"
#include "RootConfig.h"

RootConfig::RootConfig(ConfigSegment* pConfigSegment) :
    ComponentConfig(pConfigSegment)
{
    //TODO Is it necessary to validate ConfigSegment?! e.g. whether it is map?
}

RootConfig::~RootConfig()
{

}

template <typename T>
T RootConfig::getConfig()
{
    ConfigSegment* pConfigSegment =
        mpConfigSegment->getSegment(Config::getSegmentTag<T>());

    if(!pConfigSegment) {
        // Cannot load the configuration segment!
        // TODO Log something!
        exit(-1);   //TODO do something based on guideline
    }

    return T(pConfigSegment);
}

template ClientManagerConfig RootConfig::getConfig();
template ClientsConfig RootConfig::getConfig();
