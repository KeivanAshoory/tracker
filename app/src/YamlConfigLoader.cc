/*
 * =============================================================================
 *
 *       Filename:  YamlConfigLoader.cc
 *
 *    Description:  Yaml configuration loader concrete class
 *
 *        Version:  1.0
 *        Created:  28/12/15 12:08:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#include <cassert>
#include "YamlConfigNode.h"
#include "YamlConfigLoader.h"

YamlConfigLoader::YamlConfigLoader()
{

}

YamlConfigLoader::~YamlConfigLoader()
{

}

ConfigNode* YamlConfigLoader::loadConfig(void) const
{
    ConfigNode* pConfigNode = new YamlConfigNode();
    assert(pConfigNode);
    return pConfigNode;
}
