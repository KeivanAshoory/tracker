/*
 * =============================================================================
 *
 *       Filename:  ConfigLoader.h
 *
 *    Description:  Configuration loader base abstract class
 *
 *        Version:  1.0
 *        Created:  28/12/15 12:04:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef CONFIGLOADER_H

#define CONFIGLOADER_H

#include "ConfigElement.h"

class ConfigLoader
{
    public:
        virtual ~ConfigLoader() = 0;

        ConfigElement* getConfig(void) const;
        //Factory Method design pattern
        virtual ConfigElement* loadConfig(void) const = 0;

    protected:
        ConfigLoader();
};

#endif /* end of include guard: CONFIGLOADER_H */
