/*
 * =============================================================================
 *
 *       Filename:  ConfigSegment.cc
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

#include "Logger.h"
#include "ConfigSegment.h"

ConfigSegment::ConfigSegment()
{
    Logger::debug("ConfigSegment::ctor");

}

ConfigSegment::~ConfigSegment()
{
    Logger::debug("ConfigSegment::dtor");

}


template <typename T>
T ConfigSegment::getProperty(const std::string& propertyTag) const
{
    //TODO what if there is no such property in conf file? exit?!
    T value;
    getProperty(propertyTag, value);
    return value;
}

template <typename T> 
T ConfigSegment::getProperty(const std::string& propertyTag,
        const T& defaultValue) const
{
    return hasProperty(propertyTag) ?
        getProperty<T>(propertyTag) : defaultValue;
}

//TODO isn't it disgusting?! maybe an impl.h for template definitions?
template std::string ConfigSegment::getProperty(
        const std::string& propertyTag) const;

template int ConfigSegment::getProperty(
        const std::string& propertyTag) const;

template double ConfigSegment::getProperty(
        const std::string& propertyTag) const;

template bool ConfigSegment::getProperty(
        const std::string& propertyTag) const;


template std::string ConfigSegment::getProperty(
        const std::string& propertyTag, const std::string& defaultValue) const;

template int ConfigSegment::getProperty(
        const std::string& propertyTag, const int& defaultValue) const;

template double ConfigSegment::getProperty(
        const std::string& propertyTag, const double& defaultValue) const;

template bool ConfigSegment::getProperty(
        const std::string& propertyTag, const bool& defaultValue) const;


template std::vector<std::string> ConfigSegment::getProperty(
        const std::string& propertyTag) const;

template std::vector<int> ConfigSegment::getProperty(
        const std::string& propertyTag) const;

template std::vector<double> ConfigSegment::getProperty(
        const std::string& propertyTag) const;

template std::vector<bool> ConfigSegment::getProperty(
        const std::string& propertyTag) const;

template std::vector<std::string> ConfigSegment::getProperty(
        const std::string& propertyTag,
        const std::vector<std::string>& defaultValue) const;

template std::vector<int> ConfigSegment::getProperty(
        const std::string& propertyTag,
        const std::vector<int>& defaultValue) const;

template std::vector<double> ConfigSegment::getProperty(
        const std::string& propertyTag,
        const std::vector<double>& defaultValue) const;

template std::vector<bool> ConfigSegment::getProperty(
        const std::string& propertyTag,
        const std::vector<bool>& defaultValue) const;

