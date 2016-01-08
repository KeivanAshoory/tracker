/*
 * =============================================================================
 *
 *       Filename:  ClientConfig.h
 *
 *    Description:  ClientConfig
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

#ifndef CLIENTCONFIG_H

#define CLIENTCONFIG_H

#include <string>
#include <vector>
#include "ConfigElement.h"
#include "ComponentConfig.h"

class ClientConfig : private ComponentConfig
{
    public:
        ClientConfig(ConfigElement* pConfigElement);
        ~ClientConfig();

        std::string getClientType() const;
        std::vector<std::string> getRoles() const;
};

#endif /* end of include guard: CLIENTCONFIG_H */
