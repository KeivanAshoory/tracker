/*
 * =============================================================================
 *
 *       Filename:  XmlConfigLoader.cc
 *
 *    Description:  Xml configuration loader concrete class
 *
 *        Version:  1.0
 *        Created:  28/12/15 12:08:26
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
#include "XmlConfigLoader.h"

XmlConfigLoader::XmlConfigLoader()
{

}

XmlConfigLoader::~XmlConfigLoader()
{

}

ConfigSegment* XmlConfigLoader::loadConfig(void) const
{
    assert(0);  // Not implemented!
    ConfigSegment* pConfigSegment = new XmlConfigSegment();
    assert(pConfigSegment);
    return pConfigSegment;
}
