/*
 * =============================================================================
 *
 *       Filename:  ConfigLoaderFactory.cc
 *
 *    Description:  Configuration loader factory
 *
 *        Version:  1.0
 *        Created:  28/12/15 12:48:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =============================================================================
 */

#include <stddef.h>
#include "YamlFileConfigLoader.h"
#include "XmlConfigLoader.h"
#include "ConfigLoaderFactory.h"

using namespace std;

ConfigLoader* ConfigLoaderFactory::create(ConfigLoderType loaderType,
        const std::string& configFile)
{
    //TODO argument configFile does not look like a good idea! Separate methods
    //looks better.
    if(configFile.empty()) {
        return NULL;
    }

    switch(loaderType) {
        case YamlFileLoader:
            return new YamlFileConfigLoader(configFile);
        case XmlLoader:
            return new XmlConfigLoader();
        default:
            return NULL;
    }
}
