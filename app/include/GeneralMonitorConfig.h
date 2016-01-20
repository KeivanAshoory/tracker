/*
 * =============================================================================
 *
 *       Filename:  GeneralMonitorConfig.h
 *
 *    Description:  GeneralMonitorConfig
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


#ifndef GENERALMONITORCONFIG_H

#define GENERALMONITORCONFIG_H


#include "ConfigSegment.h"
#include "ComponentConfig.h"

class GeneralMonitorConfig : public ComponentConfig
{
    public:
        GeneralMonitorConfig(ConfigSegment* pConfigSegment);
        ~GeneralMonitorConfig();

};

#endif /* end of include guard: GENERALMONITORCONFIG_H */
