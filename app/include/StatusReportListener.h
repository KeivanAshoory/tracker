/*
 * =============================================================================
 *
 *       Filename:  StatusReportListener.h
 *
 *    Description:  StatusReportListener abstract class
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

#ifndef STATUS_REPORT_LISTENER_H
#define STATUS_REPORT_LISTENER_H

class StatusReportListener
{
    public:
        virtual ~StatusReportListener() {};
        virtual void onNotifyStatusReport(int statusId) const = 0;
};

#endif
