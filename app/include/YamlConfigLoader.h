/*
 * =============================================================================
 *
 *       Filename:  YamlConfigLoader.h
 *
 *    Description:  Yaml configuration loader concrete class
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

#include "ConfigLoader.h"

class YamlConfigLoader : public ConfigLoader
{
    public:
        YamlConfigLoader();
        ~YamlConfigLoader();

        // Implement ConfigLoader
        ConfigSegment* loadConfig(void) const;
};

#endif /* end of include guard: YAMLCONFIGLOADER_H */
