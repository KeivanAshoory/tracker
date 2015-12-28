/*
 * =============================================================================
 *
 *       Filename:  ConfigNode.h
 *
 *    Description:  Configration node abstract base class
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

class ConfigNode
{
    public:
        virtual ~ConfigNode() = 0;

    protected:
        ConfigNode();
};

#endif /* end of include guard: CONFIGNODE_H */
