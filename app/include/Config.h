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
        static const std::string ELEMENT_TAG_APPLICATION;
        static const std::string ELEMENT_TAG_CLIENT_MANAGER;
        static const std::string ELEMENT_TAG_GENERAL_COMMANDER;
        static const std::string ELEMENT_TAG_GENERAL_MONITOR;
        static const std::string ELEMENT_TAG_GENERAL_POSITION_HANDLER;
        static const std::string ELEMENT_TAG_CLIENTS;

        template <typename T>
            static std::string getElementTag();
};

#endif /* end of include guard: CONFIG_H */
