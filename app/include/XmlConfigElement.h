/*
 * =============================================================================
 *
 *       Filename:  XmlConfigElement.h
 *
 *    Description:  Xml configuration element concrete class
 *
 *        Version:  1.0
 *        Created:  28/12/15 12:02:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef XMLCONFIGELEMENT_H

#define XMLCONFIGELEMENT_H

#include "ConfigElement.h"

class XmlConfigElement : public ConfigElement
{
    public:
        XmlConfigElement();
        ~XmlConfigElement();

        bool hasElement(const std::string& elementTag) const;
        ConfigElement* getElement(const std::string& elementTag) const;
};

#endif /* end of include guard: XMLCONFIGELEMENT_H */
