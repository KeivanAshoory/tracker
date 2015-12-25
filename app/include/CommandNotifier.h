/*
 * =============================================================================
 *
 *       Filename:  CommandNotifier.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/12/15 21:24:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef COMMAND_NOTIFIER_H
#define COMMAND_NOTIFIER_H

#include "CommandListener.h"

class CommandNotifier
{
    public:
        virtual ~CommandNotifier() {};
        virtual void registerCommandListener(
                const CommandListener* listener
                ) = 0;
        virtual void unregisterCommandListener(
                const CommandListener* listener
                ) = 0;

    protected:
        virtual void notifyCommand(int commandId) const = 0;
};

#endif
