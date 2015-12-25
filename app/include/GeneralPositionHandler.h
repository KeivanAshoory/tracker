/*
 * =============================================================================
 *
 *       Filename:  GeneralPositionHandler.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/12/15 20:02:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef GENERAL_POSITION_HANDLER_H
#define GENERAL_POSITION_HANDLER_H 

#include <list>
#include <string>
#include "PositionNotifier.h"
#include "PositionListener.h"

class GeneralPositionHandler : public PositionNotifier
{
    public:
        GeneralPositionHandler(const std::string& config);
        ~GeneralPositionHandler();

        void registerPositionListener(const PositionListener* listener);
        void unregisterPositionListener(const PositionListener* listener);
        void notifyPosition(int position) const;

    private:
        std::list<const PositionListener*> mListeners;
};

#endif
