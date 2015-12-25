/*
 * =============================================================================
 *
 *       Filename:  GeneralMonitor.h
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

#ifndef GENERAL_MONITOR_H
#define GENERAL_MONITOR_H

#include <list>
#include <string>
#include "StatusNotifier.h"
#include "StatusListener.h"
#include "StatusReportListener.h"

class GeneralMonitor : public StatusNotifier, public StatusReportListener
{
    public:
        GeneralMonitor(const std::string& config);
        ~GeneralMonitor();

        // Impelement StatusNotifier
        void registerStatusListener(const StatusListener* listener);
        void unregisterStatusListener(const StatusListener* listener);

        // Impelement StatusReportListener
        void onNotifyStatusReport(int statusId) const;

    protected:
        // Impelement StatusNotifier
        void notifyStatus(int StatusId) const;

    private:
        std::list<const StatusListener*> mListeners;
};

#endif
