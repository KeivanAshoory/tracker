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
        //Override observer method
        void onNotifyPosition(int position) const;
        virtual void onNotifyPositionEvent(int position) const = 0;

    protected:
        PositionHandler();
};

#endif
