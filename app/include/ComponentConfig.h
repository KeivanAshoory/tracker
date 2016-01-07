/*
 * =============================================================================
 *
 *       Filename:  ComponentConfig.h
 *
 *    Description:  Component config base abstract class
 *
 *        Version:  1.0
 *        Created:  05/01/16 23:02:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef COMPONENTCONFIG_H

#define COMPONENTCONFIG_H

#include <string>
#include "ConfigNode.h"

class ComponentConfig
{
    public:
        virtual ~ComponentConfig() = 0;

    protected:
        //TODO copy ctor is most likely needed!
        ComponentConfig(ConfigNode* pConfigNode);

        ConfigNode* mpConfigNode;
};

#endif /* end of include guard: COMPONENTCONFIG_H */

