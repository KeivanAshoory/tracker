/*
 * =============================================================================
 *
 *       Filename:  PositionListener.h
 *
 *    Description:  PositionListener abstract class
 *
 *        Version:  1.0
 *        Created:  12/12/15 22:17:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef POSITION_LISTENER_H
#define POSITION_LISTENER_H

class PositionListener
{
    public:
        virtual ~PositionListener() {};
        virtual void onNotifyPosition(int position) const = 0;
};

#endif
