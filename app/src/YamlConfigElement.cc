/*
 * =============================================================================
 *
 *       Filename:  YamlConfigElement.cc
 *
 *    Description:  Yaml configuration element concrete class
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

#include "YamlConfigElement.h"

YamlConfigElement::YamlConfigElement(YAML::Node yamlNode) : mYamlNode(yamlNode)
{
    assert(!yamlNode.IsNull());
}

YamlConfigElement::~YamlConfigElement()
{

}

bool YamlConfigElement::hasElement(const std::string& elementTag) const
{
    return false;
}

ConfigElement* YamlConfigElement::getElement(const std::string& elementTag) const
{
    return NULL;
}
