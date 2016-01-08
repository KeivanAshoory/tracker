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
#include "YamlConfigElement.h"
#include "YamlConfigLoader.h"

YamlConfigLoader::YamlConfigLoader()
{

}

YamlConfigLoader::~YamlConfigLoader()
{

}

ConfigElement* YamlConfigLoader::loadConfig(void) const
{
    //TODO remember to handle exception
    YAML::Node rootYamlNode = YAML::LoadFile("config.yaml");

    if(rootYamlNode.IsNull()) {
        return NULL;
    }
    //TODO should be completed

   return new YamlConfigElement(rootYamlNode);
}
