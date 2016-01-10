/*
 * =============================================================================
 *
 *       Filename:  ConfigSegment.h
 *
 *    Description:  Configration segment interface class
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

#ifndef CONFIGSEGMENT_H

#define CONFIGSEGMENT_H

#include <string>

class ConfigSegment
{
    public:
        virtual ~ConfigSegment() {};

        virtual bool hasSegment(const std::string& segmentTag) const = 0;
        virtual ConfigSegment* getSegment(const std::string& segmentTag) const = 0;
};

#endif /* end of include guard: CONFIGSEGMENT_H */
