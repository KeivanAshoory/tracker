/*
 * =============================================================================
 *
 *       Filename:  ClientControl.h
 *
 *    Description:  Client control abstract base class
 *
 *        Version:  1.0
 *        Created:  13/12/15 21:24:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef CLIENT_CONTROL_H
#define CLIENT_CONTROL_H

class ClientControl
{
    public:
        virtual ~ClientControl() = 0;

    protected:
        ClientControl();
};

#endif
