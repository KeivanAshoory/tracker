/*
 * =============================================================================
 *
 *       Filename:  ConfigSegment.h
 *
 *    Description:  Configration segment semi-interface class
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
#include <vector>

class ConfigSegment
{
    public:
        virtual ~ConfigSegment() = 0;
        virtual ConfigSegment* clone() const = 0;

        virtual bool hasSegment(const std::string& segmentTag) const = 0;
        virtual bool hasProperty(const std::string& propertyTag) const = 0;
        virtual bool hasSegmentArray() const = 0;

        virtual ConfigSegment* getSegment(const std::string& segmentTag)
            const = 0;
        virtual std::vector<ConfigSegment*> getSegmentArray() const = 0;

        template <typename T> 
            T getProperty(const std::string& propertyTag) const;

        template <typename T> 
            T getProperty(const std::string& propertyTag,
                    const T& defaultValue) const;

    protected:
        ConfigSegment();

        //TODO isn't there any better way than defining multiple methods?
        //virtual template does not exist in c++!
        virtual void getProperty(const std::string& propertyTag,
                std::string& value) const = 0;
        virtual void getProperty(const std::string& propertyTag,
                int& value) const = 0;
        virtual void getProperty(const std::string& propertyTag,
                double& value) const = 0;
        virtual void getProperty(const std::string& propertyTag,
                bool& value) const = 0;

        virtual void getProperty(const std::string& propertyTag,
                std::vector<std::string>& value) const = 0;
        virtual void getProperty(const std::string& propertyTag,
                std::vector<int>& value) const = 0;
        virtual void getProperty(const std::string& propertyTag,
                std::vector<double>& value) const = 0;
        virtual void getProperty(const std::string& propertyTag,
                std::vector<bool>& value) const = 0;

};

#endif /* end of include guard: CONFIGSEGMENT_H */
