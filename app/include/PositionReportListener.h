/*
 * =============================================================================
 *
 *       Filename:  PositionReportListener.h
 *
 *    Description:  PositionReportListener abstract class
 *
 *        Version:  1.0
 *        Created:  12/12/15 22:17:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef POSITION_REPORT_LISTENER_H
#define POSITION_REPORT_LISTENER_H

class PositionReportListener
{
    public:
        virtual ~PositionReportListener() {};
        virtual void onNotifyPositionReport(int position) const = 0;
};

#endif
