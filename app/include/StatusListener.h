/*
 * =============================================================================
 *
 *       Filename:  StatusListener.h
 *
 *    Description:  StatusListener abstract base class
 *
 *        Version:  1.0
 *        Created:  12/12/15 22:11:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef STATUS_LISTENER_H
#define STATUS_LISTENER_H

class StatusListener
{
    public:
        virtual ~StatusListener() {};
        virtual void onNotifyStatus(int StatusId) const = 0;
};

#endif
