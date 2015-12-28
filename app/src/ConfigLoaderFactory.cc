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
#include "YamlConfigLoader.h"
#include "XmlConfigLoader.h"
#include "ConfigLoaderFactory.h"

using namespace std;

ConfigLoader* ConfigLoaderFactory::create(ConfigLoderType loaderType)
{
    switch(loaderType) {
        case YAML_CONFIG_LOADER:
            return new YamlConfigLoader();
        case XML_CONFIG_LOADER:
            return new XmlConfigLoader();
        default:
            return NULL;
    }
}
