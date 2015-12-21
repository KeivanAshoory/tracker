/*
 * =============================================================================
 *
 *       Filename:  CommandRequestListener.h
 *
 *    Description:  CommandRequestListener abstract class
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

#ifndef COMMAND_REQUEST_LISTENER_H
#define COMMAND_REQUEST_LISTENER_H

class CommandRequestListener
{
    public:
        virtual ~CommandRequestListener() {};
        virtual void onNotifyCommandRequest(int commandId) const = 0;
};

#endif
