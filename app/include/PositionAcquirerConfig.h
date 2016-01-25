/*
 * =============================================================================
 *
 *       Filename:  PositionAcquirerConfig.h
 *
 *    Description:  PositionAcquirerConfig
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


#ifndef POSITIONACQUIRERCONFIG_H

#define POSITIONACQUIRERCONFIG_H

#include "ConfigSegment.h"
#include "ComponentConfig.h"

class PositionAcquirerConfig : public ComponentConfig
{
    public:
        PositionAcquirerConfig(ConfigSegment* pConfigSegment);
        ~PositionAcquirerConfig();

        std::string getDevice() const;
};


#endif /* end of include guard: POSITIONACQUIRERCONFIG_H */
