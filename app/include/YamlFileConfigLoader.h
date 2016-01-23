/*
 * =============================================================================
 *
 *       Filename:  YamlFileConfigLoader.h
 *
 *    Description:  Yaml configuration file loader concrete class
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

#ifndef YAMLFILECONFIGLOADER_H

#define YAMLFILECONFIGLOADER_H

#include <yaml-cpp/yaml.h>
#include "YamlConfigLoader.h"

class YamlFileConfigLoader : public YamlConfigLoader
{
    public:
        YamlFileConfigLoader(const std::string& filePath);
        ~YamlFileConfigLoader();

        // Implement YamlConfigLoader
        virtual YAML::Node loadRootNode(void) const;

    private:
        std::string mYamlFilePath;

};

#endif /* end of include guard: YAMLFILECONFIGLOADER_H */
