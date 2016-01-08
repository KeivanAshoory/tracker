/*
 * =============================================================================
 *
 *       Filename:  ComponentConfig.cc
 *
 *    Description:  Component config base abstract class
 *
 *        Version:  1.0
 *        Created:  05/01/16 23:04:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#include "ComponentConfig.h"

ComponentConfig::ComponentConfig(ConfigElement* pConfigElement) : 
    mpConfigElement(pConfigElement)
{

}

ComponentConfig::~ComponentConfig()
{
    delete mpConfigElement;
}

