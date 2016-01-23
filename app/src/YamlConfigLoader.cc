/*
 * =============================================================================
 *
 *       Filename:  YamlConfigLoader.cc
 *
 *    Description:  Yaml configuration loader abstract class
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

#include "Logger.h"
#include "YamlConfigSegment.h"
#include "YamlConfigLoader.h"

YamlConfigLoader::YamlConfigLoader()
{
    Logger::debug("YamlConfigLoader::ctor");

}

YamlConfigLoader::~YamlConfigLoader()
{
    Logger::debug("YamlConfigLoader::dtor");

}

ConfigSegment* YamlConfigLoader::loadConfig(void) const
{
    YAML::Node rootNode = loadRootNode();

    if(rootNode.IsNull()) {
        // TODO Log it!
        return NULL;
    }

    return new YamlConfigSegment(rootNode);
}
