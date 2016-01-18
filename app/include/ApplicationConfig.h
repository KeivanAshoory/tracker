/*
 * =============================================================================
 *
 *       Filename:  ApplicationConfig.h
 *
 *    Description:  ApplicationConfig
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

#ifndef APPLICATIONCONFIG_H
#define APPLICATIONCONFIG_H

#include <string>
#include <vector>
#include "ConfigSegment.h"
#include "ComponentConfig.h"

class ApplicationConfig : public ComponentConfig
{
    public:
        ApplicationConfig(ConfigSegment* pConfigSegment);
        ~ApplicationConfig();

        std::string getName() const;
        std::string getVersion() const;
};

#endif /* end of include guard: APPLICATIONCONFIG_H */
