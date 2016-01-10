/*
 * =============================================================================
 *
 *       Filename:  YamlConfigSegment.cc
 *
 *    Description:  Yaml configuration segment concrete class
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

#include "YamlConfigSegment.h"

YamlConfigSegment::YamlConfigSegment(YAML::Node yamlNode) : mYamlNode(yamlNode)
{
    assert(!yamlNode.IsNull());
}

YamlConfigSegment::~YamlConfigSegment()
{

}

bool YamlConfigSegment::hasSegment(const std::string& segmentTag) const
{
    return false;
}

ConfigSegment* YamlConfigSegment::getSegment(const std::string& segmentTag) const
{


    return NULL;
}
