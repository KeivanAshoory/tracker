/*
 * =============================================================================
 *
 *       Filename:  ClientConfig.cc
 *
 *    Description:  ClientConfig
 *
 *        Version:  1.0
 *        Created:  27/12/15 20:39:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#include <algorithm>
#include "Logger.h"
#include "Config.h"
#include "ClientConfig.h"

ClientConfig::ClientConfig(ConfigSegment* pConfigSegment) : 
    ComponentConfig(pConfigSegment)
{
    Logger::debug("ClientConfig::ctor");

}

ClientConfig::~ClientConfig()
{
    Logger::debug("ClientConfig::dtor");

}

Client::Type ClientConfig::getType() const
{
    if(mpConfigSegment->hasProperty(Config::PROPERTY_TAG_CLIENT_TYPE)) {
        return parseType(mpConfigSegment->getProperty<std::string>(
                    Config::PROPERTY_TAG_CLIENT_TYPE));
    } else {
        // No type is defined!
        return Client::UndefinedType;
    }
}

std::vector<Client::Role> ClientConfig::getRoles() const
{
    if(mpConfigSegment->hasProperty(Config::PROPERTY_TAG_CLIENT_ROLE)) {
        std::vector<std::string> roleStrings =
            mpConfigSegment->getProperty<std::vector<std::string> >(
                    Config::PROPERTY_TAG_CLIENT_ROLE);

        std::vector<Client::Role> roles;
        for(std::vector<std::string>::iterator it = roleStrings.begin();
                it != roleStrings.end(); ++it) {
            roles.push_back(parseRole(*it));
        }

        return roles;
    } else {
        // No role is defined => return empty vector.
        return std::vector<Client::Role>();
    }
}

Client::Type ClientConfig::parseType(const std::string& type)
{
    //TODO improve this function later. Maybe you should define a specific class
    // for cllient type and imlement a parser there.
    std::string normalisedType = normaliseProperty(type);

    if(normalisedType ==
            normaliseProperty(Config::PROPERTY_VALUE_CLIENT_TYPE_CONSOLE))
        return Client::Console;
    if(normalisedType ==
            normaliseProperty(Config::PROPERTY_VALUE_CLIENT_TYPE_PUSH_BUTTON))
        return Client::PushButton;
    return Client::UnknownType;
}

Client::Role ClientConfig::parseRole(const std::string& role)
{
    //TODO improve this function later. Maybe you should define a specific class
    // for cllient type and imlement a parser there.
    std::string normalisedRole = normaliseProperty(role);

    if(normalisedRole ==
            normaliseProperty(Config::PROPERTY_VALUE_CLIENT_ROLE_COMMANDER))
        return Client::Commander;
    if(normalisedRole ==
            normaliseProperty(Config::PROPERTY_VALUE_CLIENT_ROLE_MONITOR))
        return Client::Monitor;
    if(normalisedRole ==
            normaliseProperty(
                Config::PROPERTY_VALUE_CLIENT_ROLE_POSITION_HANDLER))
        return Client::PositionHandler;
    return Client::UnknownRole;
}

std::string ClientConfig::normaliseProperty(const std::string& value)
{
    std::string normalisedValue(value.size(), '\0');

    // ignore case by converting the string to lower case
    std::transform(value.begin(), value.end(),
            normalisedValue.begin(), ::tolower);

    // remove all spaces.
    normalisedValue.erase(std::remove_if(
                normalisedValue.begin(), normalisedValue.end(), ::isspace),
            normalisedValue.end());
    return normalisedValue;
}
