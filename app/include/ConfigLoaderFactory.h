/*
 * =============================================================================
 *
 *       Filename:  ConfigLoaderFactory.h
 *
 *    Description:  Configuration loader factory
 *
 *        Version:  1.0
 *        Created:  28/12/15 12:39:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef CONFIGLOADERFACTORY_H

#define CONFIGLOADERFACTORY_H

#include "ConfigLoader.h"

class ConfigLoaderFactory
{
    public:
        enum ConfigLoderType {
            YAML_CONFIG_LOADER,
            XML_CONFIG_LOADER
        };

        static ConfigLoader* create(ConfigLoderType loaderType);
        // We can define different factory methods like:
        // createYamlByFile
        // createYamlByStream
        // createYamlByLocalFile
        // createYamlByRemoteFile
};

#endif /* end of include guard: CONFIGLOADERFACTORY_H */
