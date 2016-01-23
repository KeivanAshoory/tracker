/*
 * =============================================================================
 *
 *       Filename:  YamlFileConfigLoader.cc
 *
 *    Description:  Yaml configuration file loader concrete class
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
#include "YamlFileConfigLoader.h"

YamlFileConfigLoader::YamlFileConfigLoader(const std::string& filePath) : 
    mYamlFilePath(filePath)
{
    Logger::debug("YamlFileConfigLoader::ctor");

}

YamlFileConfigLoader::~YamlFileConfigLoader()
{
    Logger::debug("YamlFileConfigLoader::dtor");

}

YAML::Node YamlFileConfigLoader::loadRootNode(void) const
{
    //TODO remember to handle exception, file may not exist!
    YAML::Node rootNode = YAML::LoadFile(mYamlFilePath);
    return rootNode;
}
