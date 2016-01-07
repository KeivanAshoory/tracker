/*
 * =============================================================================
 *
 *       Filename:  YamlConfigNode.cc
 *
 *    Description:  Yaml configuration node concrete class
 *
 *        Version:  1.0
 *        Created:  28/12/15 11:57:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#include "YamlConfigNode.h"

YamlConfigNode::YamlConfigNode(YAML::Node yamlNode) : mYamlNode(yamlNode)
{
    assert(!yamlNode.IsNull());
}

YamlConfigNode::~YamlConfigNode()
{

}

bool YamlConfigNode::hasElement(const std::string& elementTag) const
{
    return false;
}

ConfigNode* YamlConfigNode::getElement(const std::string& elementTag) const
{
    return NULL;
}
