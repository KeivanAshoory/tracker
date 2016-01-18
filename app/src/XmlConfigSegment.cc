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

XmlConfigSegment* XmlConfigSegment::clone() const
{
    return new XmlConfigSegment(*this);
}

bool XmlConfigSegment::hasSegment(const std::string& segmentTag) const
{
    return false;
}

bool XmlConfigSegment::hasProperty(const std::string& propertyTag) const
{
    return false;
}

bool XmlConfigSegment::hasSegmentArray() const
{
    return false;
}

ConfigSegment* XmlConfigSegment::getSegment(const std::string& segmentTag) const
{
    return NULL;
}

std::vector<ConfigSegment*> XmlConfigSegment::getSegmentArray() const
{
    std::vector<ConfigSegment*> configSegments;
    return configSegments;
}

void XmlConfigSegment::getProperty(
        const std::string& propertyTag, std::string& value) const
{
}

void XmlConfigSegment::getProperty(
        const std::string& propertyTag, int& value) const
{
}

void XmlConfigSegment::getProperty(
        const std::string& propertyTag, double& value) const
{
}

void XmlConfigSegment::getProperty(
        const std::string& propertyTag, bool& value) const
{
}

void XmlConfigSegment::getProperty(
        const std::string& propertyTag, std::vector<std::string>& value) const
{
}

void XmlConfigSegment::getProperty(
        const std::string& propertyTag, std::vector<int>& value) const
{
}

void XmlConfigSegment::getProperty(
        const std::string& propertyTag, std::vector<double>& value) const
{
}

void XmlConfigSegment::getProperty(
        const std::string& propertyTag, std::vector<bool>& value) const
{
}

