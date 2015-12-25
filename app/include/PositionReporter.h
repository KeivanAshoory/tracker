/*
 * =============================================================================
 *
 *       Filename:  PositionReporter.h
 *
 *    Description:  Position Reporter base abstract class
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

#ifndef POSITION_REPORTER_H
#define POSITION_REPORTER_H

#include "PositionReportNotifier.h"
#include <list>

class PositionReporter : public PositionReportNotifier
{
    public:
        virtual ~PositionReporter() = 0;

        virtual void registerPositionReportListener(
                const PositionReportListener* listener
                );
        virtual void unregisterPositionReportListener(
                const PositionReportListener* listener
                );
        virtual void notifyPositionReport(int position) const;

    protected:
        PositionReporter();

    private:
        std::list<const PositionReportListener*> mListeners;
};

#endif
