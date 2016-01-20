/*
 * =============================================================================
 *
 *       Filename:  GeneralCommanderConfig.h
 *
 *    Description:  GeneralCommanderConfig
 *
 *        Version:  1.0
 *        Created:  27/12/15 19:14:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */


#ifndef GENERALCOMMANDERCONFIG_H

#define GENERALCOMMANDERCONFIG_H


#include "ConfigSegment.h"
#include "ComponentConfig.h"

class GeneralCommanderConfig : public ComponentConfig
{
    public:
        GeneralCommanderConfig(ConfigSegment* pConfigSegment);
        ~GeneralCommanderConfig();

};

#endif /* end of include guard: GENERALCOMMANDERCONFIG_H */
