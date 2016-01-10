/*
 * =============================================================================
 *
 *       Filename:  XmlConfigSegment.h
 *
 *    Description:  Xml configuration segment concrete class
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

#ifndef XMLCONFIGSEGMENT_H

#define XMLCONFIGSEGMENT_H

#include "ConfigSegment.h"

class XmlConfigSegment : public ConfigSegment
{
    public:
        XmlConfigSegment();
        ~XmlConfigSegment();

        bool hasSegment(const std::string& segmentTag) const;
        ConfigSegment* getSegment(const std::string& segmentTag) const;
};

#endif /* end of include guard: XMLCONFIGSEGMENT_H */
