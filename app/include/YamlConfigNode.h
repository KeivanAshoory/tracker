/*
 * =============================================================================
 *
 *       Filename:  YamlConfigNode.h
 *
 *    Description:  Yaml configuration node concrete class
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

#ifndef YAMLCONFIGNODE_H

#define YAMLCONFIGNODE_H

#include "ConfigNode.h"

class YamlConfigNode : public ConfigNode
{
    public:
        YamlConfigNode();
        ~YamlConfigNode();

};

#endif /* end of include guard: YAMLCONFIGNODE_H */
