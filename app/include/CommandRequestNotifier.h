/*
 * =============================================================================
 *
 *       Filename:  CommandRequestNotifier.h
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

#ifndef COMMAND_REQUEST_NOTIFIER_H
#define COMMAND_REQUEST_NOTIFIER_H

#include "CommandRequestListener.h"

class CommandRequestNotifier
{
    public:
        virtual ~CommandRequestNotifier() {};
        virtual void registerCommandRequestListener(
                const CommandRequestListener* listener
                ) = 0;
        virtual void unregisterCommandRequestListener(
                const CommandRequestListener* listener
                ) = 0;
        virtual void notifyCommandRequest(int commandId) const = 0;
};

#endif
