/*
 * =============================================================================
 *
 *       Filename:  ClientManagerConfig.h
 *
 *    Description:  ClientManagerConfig
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


#ifndef CLIENTMANAGERCONFIG_H

#define CLIENTMANAGERCONFIG_H


#include <string>
#include <vector>
#include "ConfigSegment.h"
#include "ComponentConfig.h"

class ClientManagerConfig : public ComponentConfig
{
    public:
        ClientManagerConfig(ConfigSegment* pConfigSegment);
        ~ClientManagerConfig();

        std::string getXXX() const;
};


#endif /* end of include guard: CLIENTMANAGERCONFIG_H */
