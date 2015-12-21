/*
 * =============================================================================
 *
 *       Filename:  CommandListener.h
 *
 *    Description:  CommandListener abstract class
 *
 *        Version:  1.0
 *        Created:  12/12/15 22:17:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef COMMAND_LISTENER_H
#define COMMAND_LISTENER_H

class CommandListener
{
    public:
        virtual ~CommandListener() {};
        virtual void onNotifyCommand(int commandId) const = 0;
};

#endif
