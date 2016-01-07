/*
 * =============================================================================
 *
 *       Filename:  ConfigNode.h
 *
 *    Description:  Configration node interface class
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

#ifndef CONFIGNODE_H

#define CONFIGNODE_H

#include <string>

class ConfigNode
{
    public:
        virtual ~ConfigNode() {};

        virtual bool hasElement(const std::string& elementTag) const = 0;
        virtual ConfigNode* getElement(const std::string& elementTag) const = 0;
};

#endif /* end of include guard: CONFIGNODE_H */
