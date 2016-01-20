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
#include "GeneralPositionHandlerConfig.h" 
#include "PositionReportListener.h"

class GeneralPositionHandler : public PositionNotifier,
    public PositionReportListener
{
    public:
        GeneralPositionHandler(const GeneralPositionHandlerConfig& config);
        ~GeneralPositionHandler();

        // Implement PositionNotifier
        void registerPositionListener(const PositionListener* listener);
        void unregisterPositionListener(const PositionListener* listener);

        // Impelement PositionReportListener
        void onNotifyPositionReport(int position) const;

    protected:
        // Implement PositionNotifier
        void notifyPosition(int position) const;

    private:
        std::list<const PositionListener*> mListeners;
};

#endif
