/*
 * =============================================================================
 *
 *       Filename:  PositionNotifier.h
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

#ifndef POSITION_NOTIFIER_H
#define POSITION_NOTIFIER_H

#include "PositionListener.h"

class PositionNotifier
{
    public:
        virtual ~PositionNotifier() {};
        virtual void registerPositionListener(
                const PositionListener* listener
                ) = 0;
        virtual void unregisterPositionListener(
                const PositionListener* listener
                ) = 0;

    protected:
        virtual void notifyPosition(int Position) const = 0;
};

#endif
