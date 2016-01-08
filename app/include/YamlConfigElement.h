/*
 * =============================================================================
 *
 *       Filename:  YamlConfigElement.h
 *
 *    Description:  Yaml configuration element concrete class
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

#ifndef YAMLCONFIGELEMENT_H

#define YAMLCONFIGELEMENT_H

#include <yaml-cpp/yaml.h>
#include "ConfigElement.h"

class YamlConfigElement : public ConfigElement
{
    public:
        YamlConfigElement(YAML::Node yamlNode);
        ~YamlConfigElement();

        bool hasElement(const std::string& elementTag) const;
        ConfigElement* getElement(const std::string& elementTag) const;

    private:
        YAML::Node mYamlNode;

};

#endif /* end of include guard: YAMLCONFIGELEMENT_H */
