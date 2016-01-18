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
#include <vector>

class XmlConfigSegment : public ConfigSegment
{
    public:
        XmlConfigSegment();
        ~XmlConfigSegment();
        XmlConfigSegment* clone() const;

        bool hasSegment(const std::string& segmentTag) const;
        bool hasProperty(const std::string& propertyTag) const;
        bool hasSegmentArray() const;

        ConfigSegment* getSegment(const std::string& segmentTag) const;
        std::vector<ConfigSegment*> getSegmentArray() const;

        void getProperty(const std::string& propertyTag,
                std::string& value) const;
        void getProperty(const std::string& propertyTag,
                int& value) const;
        void getProperty(const std::string& propertyTag,
                double& value) const;
        void getProperty(const std::string& propertyTag,
                bool& value) const;
        
        void getProperty(const std::string& propertyTag,
                std::vector<std::string>& value) const;
        void getProperty(const std::string& propertyTag,
                std::vector<int>& value) const;
        void getProperty(const std::string& propertyTag,
                std::vector<double>& value) const;
        void getProperty(const std::string& propertyTag,
                std::vector<bool>& value) const;
};

#endif /* end of include guard: XMLCONFIGSEGMENT_H */
