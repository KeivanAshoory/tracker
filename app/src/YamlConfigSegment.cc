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

#include "Logger.h"
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
    YAML::Node node = mYamlNode[segmentTag];
//    if(!node.IsNull()) {
    if(node) {
        // a segment must be a sequence or map. It cannot be scalar. It is not a
        // perfect check, but we cope at this time!
        if(node.IsSequence() || node.IsMap()) {
            return true;
        }
    }

    return false;
}

bool YamlConfigSegment::hasProperty(const std::string& propertyTag) const
{
    if(mYamlNode[propertyTag]) {
        // a property can be scalar, map or sequence
        return true;
    } else {
        return false;
    }
}

bool YamlConfigSegment::hasSegmentArray() const
{
    if(mYamlNode.IsSequence()) {
        // well, it could be a sequence of properties not segments, but we 
        // ignore it at this stage!
        return true;
    } else {
        return false;
    }
}

ConfigSegment* YamlConfigSegment::getSegment(
        const std::string& segmentTag) const
{
    if(hasSegment(segmentTag)) {
        return new YamlConfigSegment(mYamlNode[segmentTag]);
    } else {
        return NULL;
    }
}

std::vector<ConfigSegment*> YamlConfigSegment::getSegmentArray() const
{
    std::vector<ConfigSegment*> configSegments;
    if(hasSegmentArray()) {
        for(YAML::const_iterator
                it = mYamlNode.begin(); it != mYamlNode.end(); ++it) {
            configSegments.push_back(
                    new YamlConfigSegment(*it));
        }
    }

    return configSegments;
}

void YamlConfigSegment::getProperty(
        const std::string& propertyTag, std::string& value) const
{
    value = mYamlNode[propertyTag].as<std::string>();
}

void YamlConfigSegment::getProperty(
        const std::string& propertyTag, int& value) const
{
    value = mYamlNode[propertyTag].as<int>();
}

void YamlConfigSegment::getProperty(
        const std::string& propertyTag, double& value) const
{
    value = mYamlNode[propertyTag].as<double>();
}

void YamlConfigSegment::getProperty(
        const std::string& propertyTag, bool& value) const
{
    value = mYamlNode[propertyTag].as<bool>();
}

void YamlConfigSegment::getProperty(
        const std::string& propertyTag, std::vector<std::string>& value) const
{
    value = mYamlNode[propertyTag].as<std::vector<std::string> >();
}

void YamlConfigSegment::getProperty(
        const std::string& propertyTag, std::vector<int>& value) const
{
    value = mYamlNode[propertyTag].as<std::vector<int> >();
}

void YamlConfigSegment::getProperty(
        const std::string& propertyTag, std::vector<double>& value) const
{
    value = mYamlNode[propertyTag].as<std::vector<double> >();
}

void YamlConfigSegment::getProperty(
        const std::string& propertyTag, std::vector<bool>& value) const
{
    value = mYamlNode[propertyTag].as<std::vector<bool> >();
}

