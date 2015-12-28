/*
 * =============================================================================
 *
 *       Filename:  XmlConfigNode.h
 *
 *    Description:  Xml configuration node concrete class
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

#ifndef XMLCONFIGNODE_H

#define XMLCONFIGNODE_H

#include "ConfigNode.h"

class XmlConfigNode : public ConfigNode
{
    public:
        XmlConfigNode();
        ~XmlConfigNode();

};

#endif /* end of include guard: XMLCONFIGNODE_H */
