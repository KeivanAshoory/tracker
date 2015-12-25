/*
 * =============================================================================
 *
 *       Filename:  StatusReportNotifier.h
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

#ifndef STATUS_REPORT_NOTIFIER_H
#define STATUS_REPORT_NOTIFIER_H

#include "StatusReportListener.h"

class StatusReportNotifier
{
    public:
        virtual ~StatusReportNotifier() {};
        virtual void registerStatusReportListener(
                const StatusReportListener* listener
                ) = 0;
        virtual void unregisterStatusReportListener(
                const StatusReportListener* listener
                ) = 0;
        virtual void notifyStatusReport(int statusId) const = 0;
};

#endif
