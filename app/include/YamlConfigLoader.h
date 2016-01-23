/*
 * =============================================================================
 *
 *       Filename:  YamlConfigLoader.h
 *
 *    Description:  Yaml configuration loader abstract class
 *
 *        Version:  1.0
 *        Created:  28/12/15 12:04:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef YAMLCONFIGLOADER_H

#define YAMLCONFIGLOADER_H

#include <yaml-cpp/yaml.h>
#include "ConfigLoader.h"

class YamlConfigLoader : public ConfigLoader
{
    public:
        YamlConfigLoader();
        ~YamlConfigLoader();

        // Implement ConfigLoader
        ConfigSegment* loadConfig(void) const;

    private:
        virtual YAML::Node loadRootNode(void) const = 0;
};

#endif /* end of include guard: YAMLCONFIGLOADER_H */
