/*
 * =============================================================================
 *
 *       Filename:  ConfigElement.h
 *
 *    Description:  Configration element interface class
 *
 *        Version:  1.0
 *        Created:  28/12/15 11:59:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef CONFIGELEMENT_H

#define CONFIGELEMENT_H

#include <string>

class ConfigElement
{
    public:
        virtual ~ConfigElement() {};

        virtual bool hasElement(const std::string& elementTag) const = 0;
        virtual ConfigElement* getElement(const std::string& elementTag) const = 0;
};

#endif /* end of include guard: CONFIGELEMENT_H */
