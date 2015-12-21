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

#include <list>
#include "StatusNotifier.h"
#include "StatusListener.h"

class GeneralMonitor : public StatusNotifier
{
    public:
        GeneralMonitor();
        ~GeneralMonitor();

        void registerStatusListener(const StatusListener* listener);
        void unregisterStatusListener(const StatusListener* listener);
        void notifyStatus(int StatusId) const;

    private:
        std::list<const StatusListener*> mListeners;
};
