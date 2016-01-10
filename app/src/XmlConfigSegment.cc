/*
 * =============================================================================
 *
 *       Filename:  XmlConfigSegment.cc
 *
 *    Description:  Xml configuration segment concrete class
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
#include "XmlConfigSegment.h"

XmlConfigSegment::XmlConfigSegment()
{
    assert(0);  // Not Imlemented!
}

XmlConfigSegment::~XmlConfigSegment()
{

}

bool XmlConfigSegment::hasSegment(const std::string& segmentTag) const
{
    return false;
}

ConfigSegment* XmlConfigSegment::getSegment(const std::string& segmentTag) const
{
    return NULL;
}
