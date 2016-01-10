/*
 * =============================================================================
 *
 *       Filename:  RootConfig.h
 *
 *    Description:  Root configuration
 *
 *        Version:  1.0
 *        Created:  27/12/15 21:02:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef ROOTCONFIG_H

#define ROOTCONFIG_H

#include <vector>
#include "ClientConfig.h"
#include "ConfigSegment.h"
#include "ComponentConfig.h"

class RootConfig : private ComponentConfig
{
    public:
        RootConfig(ConfigSegment* pConfigSegment);
        ~RootConfig();

        template <typename T> 
            T getConfig();

};

#endif /* end of include guard: ROOTCONFIG_H */
