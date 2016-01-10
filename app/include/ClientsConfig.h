/*
 * =============================================================================
 *
 *       Filename:  ClientsConfig.h
 *
 *    Description:  ClientsConfig
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


#ifndef CLIENTSCONFIG_H

#define CLIENTSCONFIG_H


#include <string>
#include <vector>
#include "ConfigSegment.h"
#include "ComponentConfig.h"

class ClientsConfig : public ComponentConfig
{
    public:
        ClientsConfig(ConfigSegment* pConfigSegment);
        ~ClientsConfig();

        std::string getXXX() const;
};


#endif /* end of include guard: CLIENTSCONFIG_H */
