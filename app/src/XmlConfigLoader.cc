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
#include "Logger.h"
#include "XmlConfigSegment.h"
#include "XmlConfigLoader.h"

XmlConfigLoader::XmlConfigLoader()
{
    Logger::debug("XmlConfigLoader::ctor");

}

XmlConfigLoader::~XmlConfigLoader()
{
    Logger::debug("XmlConfigLoader::dtor");

}

ConfigSegment* XmlConfigLoader::loadConfig(void) const
{
    assert(0);  // Not implemented!
    ConfigSegment* pConfigSegment = new XmlConfigSegment();
    assert(pConfigSegment);
    return pConfigSegment;
}
