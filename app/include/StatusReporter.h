/*
 * =============================================================================
 *
 *       Filename:  StatusReporter.h
 *
 *    Description:  Status Reporter base abstract class
 *
 *        Version:  1.0
 *        Created:  12/12/15 20:09:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef STATUS_REPORTER_H
#define STATUS_REPORTER_H

#include "StatusReportNotifier.h"
#include <list>

class StatusReporter : public StatusReportNotifier
{
    public:
        virtual ~StatusReporter() = 0;

        virtual void registerStatusReportListener(
                const StatusReportListener* listener
                );
        virtual void unregisterStatusReportListener(
                const StatusReportListener* listener
                );
        virtual void notifyStatusReport(int statusId) const;

    protected:
        StatusReporter();

    private:
        std::list<const StatusReportListener*> mListeners;
};

#endif
