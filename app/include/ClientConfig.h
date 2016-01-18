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
#include "ConfigSegment.h"
#include "Client.h"
#include "ComponentConfig.h"

class ClientConfig : private ComponentConfig
{
    public:
        ClientConfig(ConfigSegment* pConfigSegment);
        ~ClientConfig();

        Client::Type getType() const;
        std::vector<Client::Role> getRoles() const;

    private:
        static Client::Type parseType(const std::string& type);
        static Client::Role parseRole(const std::string& role);
        static std::string normaliseProperty(const std::string& value);
};

#endif /* end of include guard: CLIENTCONFIG_H */
