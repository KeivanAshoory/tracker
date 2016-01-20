/*
 * =============================================================================
 *
 *       Filename:  GeneralPositionHandlerConfig.h
 *
 *    Description:  GeneralPositionHandlerConfig
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


#ifndef GENERALPOSITIONHANDLERCONFIG_H

#define GENERALPOSITIONHANDLERCONFIG_H


#include "ConfigSegment.h"
#include "ComponentConfig.h"

class GeneralPositionHandlerConfig : public ComponentConfig
{
    public:
        GeneralPositionHandlerConfig(ConfigSegment* pConfigSegment);
        ~GeneralPositionHandlerConfig();

};

#endif /* end of include guard: GENERALPOSITIONHANDLERCONFIG_H */
