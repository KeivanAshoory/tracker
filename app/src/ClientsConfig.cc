/*
 * =============================================================================
 *
 *       Filename:  ClientsConfig.cc
 *
 *    Description:  ClientsConfig
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

#include "ClientsConfig.h"

ClientsConfig::ClientsConfig(ConfigSegment* pConfigSegment) : 
    ComponentConfig(pConfigSegment)
{
        // ***** BE CAREFULL OF MEMORY THAT YamlConfigSegment::getSegmentArray
        // if you create ComponentConfig from each member it is okay. UNLESS
        // NOT!!

}

ClientsConfig::~ClientsConfig()
{

}

std::string ClientsConfig::getXXX() const
{
    return "";
}
