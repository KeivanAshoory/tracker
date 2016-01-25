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
#include "ApplicationConfig.h"
#include "GeneralCommanderConfig.h"
#include "GeneralMonitorConfig.h"
#include "GeneralPositionHandlerConfig.h"
#include "PositionAcquirerConfig.h"

using namespace std;

const string Config::SEGMENT_TAG_APPLICATION = "Application";
const string Config::SEGMENT_TAG_CLIENT_MANAGER = "ClientManager";
const string Config::SEGMENT_TAG_GENERAL_COMMANDER = "GeneralCommander";
const string Config::SEGMENT_TAG_GENERAL_MONITOR = "GeneralMonitor";
const string Config::SEGMENT_TAG_GENERAL_POSITION_HANDLER = "GeneralPositionHandler";
const string Config::SEGMENT_TAG_POSITION_ACQUIRER = "PositionAcquirer";
const string Config::SEGMENT_TAG_CLIENTS = "Clients";


const string Config::PROPERTY_TAG_CONFIG_VERSION = "configVersion";
const string Config::PROPERTY_TAG_APPLICATION_VERSION = "version";
const string Config::PROPERTY_TAG_APPLICATION_NAME = "name";
const string Config::PROPERTY_TAG_CLIENT_MANAGER_MAX_CLIENT_NUMBER = "maximumClientNumber";
const string Config::PROPERTY_TAG_POSITION_ACQUIRER_DEVICE = "device";
const string Config::PROPERTY_TAG_CLIENT_TYPE = "type";
const string Config::PROPERTY_TAG_CLIENT_ROLE = "role";

const string Config::PROPERTY_VALUE_CLIENT_TYPE_CONSOLE = "console";
const string Config::PROPERTY_VALUE_CLIENT_TYPE_PUSH_BUTTON = "pushbutton";

const string Config::PROPERTY_VALUE_CLIENT_ROLE_COMMANDER = "commander";
const string Config::PROPERTY_VALUE_CLIENT_ROLE_MONITOR = "monitor";
const string Config::PROPERTY_VALUE_CLIENT_ROLE_POSITION_HANDLER = "positionhandler";

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

template <>
std::string Config::getSegmentTag<ApplicationConfig>()
{
    return SEGMENT_TAG_APPLICATION;
}

template <>
std::string Config::getSegmentTag<GeneralCommanderConfig>()
{
    return SEGMENT_TAG_GENERAL_COMMANDER;
}

template <>
std::string Config::getSegmentTag<GeneralMonitorConfig>()
{
    return SEGMENT_TAG_GENERAL_MONITOR;
}

template <>
std::string Config::getSegmentTag<GeneralPositionHandlerConfig>()
{
    return SEGMENT_TAG_GENERAL_POSITION_HANDLER;
}

template <>
std::string Config::getSegmentTag<PositionAcquirerConfig>()
{
    return SEGMENT_TAG_POSITION_ACQUIRER;
}
