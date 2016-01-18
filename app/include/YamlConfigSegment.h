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

#include <vector>
#include <yaml-cpp/yaml.h>
#include "ConfigSegment.h"

class YamlConfigSegment : public ConfigSegment
{
    public:
        YamlConfigSegment(YAML::Node yamlNode);
        ~YamlConfigSegment();
        YamlConfigSegment* clone() const;

        bool hasSegment(const std::string& segmentTag) const;
        bool hasProperty(const std::string& propertyTag) const;
        bool hasSegmentArray() const;

        ConfigSegment* getSegment(const std::string& segmentTag) const;
        std::vector<ConfigSegment*> getSegmentArray() const;
      
        void getProperty(const std::string& propertyTag,
                std::string& value) const;
        void getProperty(const std::string& propertyTag,
                int& value) const;
        void getProperty(const std::string& propertyTag,
                double& value) const;
        void getProperty(const std::string& propertyTag,
                bool& value) const;
        
        void getProperty(const std::string& propertyTag,
                std::vector<std::string>& value) const;
        void getProperty(const std::string& propertyTag,
                std::vector<int>& value) const;
        void getProperty(const std::string& propertyTag,
                std::vector<double>& value) const;
        void getProperty(const std::string& propertyTag,
                std::vector<bool>& value) const;

    private:
        YAML::Node mYamlNode; 
};

#endif /* end of include guard: YAMLCONFIGSEGMENT_H */
