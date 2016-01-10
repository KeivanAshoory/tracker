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
#include <yaml-cpp/yaml.h>
#include "YamlConfigSegment.h"
#include "YamlConfigLoader.h"

YamlConfigLoader::YamlConfigLoader()
{

}

YamlConfigLoader::~YamlConfigLoader()
{

}

ConfigSegment* YamlConfigLoader::loadConfig(void) const
{
    //TODO remember to handle exception
    YAML::Node rootYamlNode = YAML::LoadFile("config.yaml");

    if(rootYamlNode.IsNull()) {
        // TODO Log it!
        return NULL;
    }

    return new YamlConfigSegment(rootYamlNode);
}
