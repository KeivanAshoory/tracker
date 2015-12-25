/*
 * =============================================================================
 *
 *       Filename:  PositionHandler.h
 *
 *    Description:  Position handler base abstract class
 *
 *        Version:  1.0
 *        Created:  12/12/15 20:09:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef POSITION_HANDLER_H
#define POSITION_HANDLER_H

#include "PositionListener.h"

class PositionHandler : public PositionListener
{
    public:
        virtual ~PositionHandler() = 0;

        // Implement PositionListener
        void onNotifyPosition(int position) const;

    protected:
        PositionHandler();

        virtual void onNotifyPositionEvent(int position) const = 0;
};

#endif
