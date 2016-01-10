/*
 * =============================================================================
 *
 *       Filename:  YamlConfigSegment.h
 *
 *    Description:  Yaml configuration segment concrete class
 *
 *        Version:  1.0
 *        Created:  28/12/15 12:00:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef YAMLCONFIGSEGMENT_H

#define YAMLCONFIGSEGMENT_H

#include <yaml-cpp/yaml.h>
#include "ConfigSegment.h"

class YamlConfigSegment : public ConfigSegment
{
    public:
        YamlConfigSegment(YAML::Node yamlNode);
        ~YamlConfigSegment();

        bool hasSegment(const std::string& segmentTag) const;
        ConfigSegment* getSegment(const std::string& segmentTag) const;

    private:
        YAML::Node mYamlNode;

};

#endif /* end of include guard: YAMLCONFIGSEGMENT_H */
