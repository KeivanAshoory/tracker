/*
 * =============================================================================
 *
 *       Filename:  Commander.cc
 *
 *    Description:  Commander base abstract class
 *
 *        Version:  1.0
 *        Created:  12/12/15 20:12:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#include "Commander.h"

Commander::Commander()
{

}

Commander::~Commander()
{

}

void Commander::registerCommandRequestListener (const CommandRequestListener* listener)
{
    mListeners.push_back(listener);
}

void Commander::unregisterCommandRequestListener(const CommandRequestListener* listener)
{
    mListeners.remove(listener);
}

void Commander::notifyCommandRequest(int commandId) const
{
    for(std::list<const CommandRequestListener*>::const_iterator
            it = mListeners.begin(); it != mListeners.end(); ++it) {
        (*it)->onNotifyCommandRequest(commandId);
    }
}

