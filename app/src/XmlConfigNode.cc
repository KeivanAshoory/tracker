/*
 * =============================================================================
 *
 *       Filename:  XmlConfigNode.cc
 *
 *    Description:  Xml configuration node concrete class
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
#include "XmlConfigNode.h"

XmlConfigNode::XmlConfigNode()
{
    assert(0);  // Not Imlemented!
}

XmlConfigNode::~XmlConfigNode()
{

}

bool XmlConfigNode::hasElement(const std::string& elementTag) const
{
    return false;
}

ConfigNode* XmlConfigNode::getElement(const std::string& elementTag) const
{
    return NULL;
}
