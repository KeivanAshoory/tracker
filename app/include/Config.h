/*
 * =============================================================================
 *
 *       Filename:  Config.h
 *
 *    Description:  Config definitions and settings
 *
 *        Version:  1.0
 *        Created:  04/01/16 00:33:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef CONFIG_H

#define CONFIG_H

#include <string>
class Config
{
    public:
        static const std::string SEGMENT_TAG_APPLICATION;
        static const std::string SEGMENT_TAG_CLIENT_MANAGER;
        static const std::string SEGMENT_TAG_GENERAL_COMMANDER;
        static const std::string SEGMENT_TAG_GENERAL_MONITOR;
        static const std::string SEGMENT_TAG_GENERAL_POSITION_HANDLER;
        static const std::string SEGMENT_TAG_CLIENTS;


        static const std::string PROPERTY_TAG_CONFIG_VERSION;
        static const std::string PROPERTY_TAG_APPLICATION_VERSION;
        static const std::string PROPERTY_TAG_APPLICATION_NAME;
        static const std::string PROPERTY_TAG_CLIENT_MANAGER_MAX_CLIENT_NUMBER;
        static const std::string PROPERTY_TAG_CLIENT_TYPE;
        static const std::string PROPERTY_TAG_CLIENT_ROLE;

        static const std::string PROPERTY_VALUE_CLIENT_TYPE_CONSOLE;
        static const std::string PROPERTY_VALUE_CLIENT_TYPE_PUSH_BUTTON;

        static const std::string PROPERTY_VALUE_CLIENT_ROLE_COMMANDER;
        static const std::string PROPERTY_VALUE_CLIENT_ROLE_MONITOR;
        static const std::string PROPERTY_VALUE_CLIENT_ROLE_POSITION_HANDLER;

        template <typename T>
            static std::string getSegmentTag();
};

#endif /* end of include guard: CONFIG_H */
