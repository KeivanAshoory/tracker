/*
 * =============================================================================
 *
 *       Filename:  Config.cc
 *
 *    Description:  Config definitions and settings
 *
 *        Version:  1.0
 *        Created:  04/01/16 19:50:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#include "Config.h"
#include "ClientManagerConfig.h"
#include "ClientsConfig.h"

const std::string Config::SEGMENT_TAG_APPLICATION = "Application";
const std::string Config::SEGMENT_TAG_CLIENT_MANAGER = "ClientManager";
const std::string Config::SEGMENT_TAG_GENERAL_COMMANDER = "GeneralCommander";
const std::string Config::SEGMENT_TAG_GENERAL_MONITOR = "GeneralMonitor";
const std::string Config::SEGMENT_TAG_GENERAL_POSITION_HANDLER = "GeneralPositionHandler";
const std::string Config::SEGMENT_TAG_CLIENTS = "Clients";

template <>
std::string Config::getSegmentTag<ClientManagerConfig>()
{
    return SEGMENT_TAG_CLIENT_MANAGER;
}

template <>
std::string Config::getSegmentTag<ClientsConfig>()
{
    return SEGMENT_TAG_CLIENTS;
}
