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

RootConfig::RootConfig(ConfigElement* pConfigElement) :
    ComponentConfig(pConfigElement)
{
    //TODO Is it necessary to validate ConfigElement?! e.g. whether it is map?
}

RootConfig::~RootConfig()
{

}

template <typename T>
T RootConfig::getConfig()
{
    ConfigElement* pConfigElement =
        mpConfigElement->getElement(Config::getElementTag<T>());

    if(!pConfigElement) {
        // Cannot load the configuration element!
        // TODO Log something!
        exit(-1);   //TODO do something based on guideline
    }

    return T(pConfigElement);
}

template ClientManagerConfig RootConfig::getConfig();
template ClientsConfig RootConfig::getConfig();
