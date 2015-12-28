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
#include "ClientManagerConfig.h"

class RootConfig
{
    RootConfig();
    ~RootConfig();

    ClientManagerConfig getClientManagerConfig() const;
    std::vector<ClientConfig> getClientsConfig() const;
};


#endif /* end of include guard: ROOTCONFIG_H */
