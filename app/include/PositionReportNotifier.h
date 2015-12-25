/*
 * =============================================================================
 *
 *       Filename:  PositionReportNotifier.h
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

#ifndef POSITION_REPORT_NOTIFIER_H
#define POSITION_REPORT_NOTIFIER_H

#include "PositionReportListener.h"

class PositionReportNotifier
{
    public:
        virtual ~PositionReportNotifier() {};
        virtual void registerPositionReportListener(
                const PositionReportListener* listener
                ) = 0;
        virtual void unregisterPositionReportListener(
                const PositionReportListener* listener
                ) = 0;
        virtual void notifyPositionReport(int position) const = 0;
};

#endif
