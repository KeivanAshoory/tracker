/*
 * =============================================================================
 *
 *       Filename:  ClientConfig.cc
 *
 *    Description:  ClientConfig
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

#include "ClientConfig.h"

ClientConfig::ClientConfig(ConfigElement* pConfigElement) : 
    ComponentConfig(pConfigElement)
{

}

ClientConfig::~ClientConfig()
{

}

std::string ClientConfig::getClientType() const
{
    // in mapping find the node which is mapped to "Type"
    // 1) hasComponent("Type")
    // 2) isScalar("Type")
    // 3) getScalar/Component("Type") as map

    return "";
}

std::vector<std::string> ClientConfig::getRoles() const
{
    std::vector<std::string> aa;
    aa.push_back("s");
    return aa;
}
