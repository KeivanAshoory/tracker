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
#include "RootConfig.h"

RootConfig::RootConfig(ConfigNode* pConfigNode) :
    ComponentConfig(pConfigNode)
{
    //TODO Is it necessary to validate ConfigNode?! e.g. whether it is map?
}

RootConfig::~RootConfig()
{

}

template <typename T>
T RootConfig::getConfig()
{
    ConfigNode* pConfigElement =
        mpConfigNode->getElement(Config::getElementTag<T>());

    if(!pConfigElement) {
        // Cannot load the configuration element!
        // TODO Log something!
        exit(-1);   //TODO do something based on guideline
    }

    return T(pConfigElement);
}

template ClientManagerConfig RootConfig::getConfig();

