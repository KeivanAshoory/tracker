/*
 * =============================================================================
 *
 *       Filename:  XmlConfigElement.cc
 *
 *    Description:  Xml configuration element concrete class
 *
 *        Version:  1.0
 *        Created:  28/12/15 12:03:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#include <cassert>
#include "XmlConfigElement.h"

XmlConfigElement::XmlConfigElement()
{
    assert(0);  // Not Imlemented!
}

XmlConfigElement::~XmlConfigElement()
{

}

bool XmlConfigElement::hasElement(const std::string& elementTag) const
{
    return false;
}

ConfigElement* XmlConfigElement::getElement(const std::string& elementTag) const
{
    return NULL;
}
