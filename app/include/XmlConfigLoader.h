/*
 * =============================================================================
 *
 *       Filename:  XmlConfigLoader.h
 *
 *    Description:  Xml configuration loader concrete class
 *
 *        Version:  1.0
 *        Created:  28/12/15 12:04:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef XMLCONFIGLOADER_H

#define XMLCONFIGLOADER_H

#include "ConfigLoader.h"

class XmlConfigLoader : public ConfigLoader
{
    public:
        XmlConfigLoader();
        ~XmlConfigLoader();

        // Implement ConfigLoader
        ConfigNode* loadConfig(void) const;
};

#endif /* end of include guard: XMLCONFIGLOADER_H */
