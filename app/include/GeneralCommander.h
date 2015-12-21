/*
 * =============================================================================
 *
 *       Filename:  GeneralCommander.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/12/15 19:41:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#include <list>
#include "CommandNotifier.h"
#include "CommandRequestListener.h"

class GeneralCommander : public CommandNotifier, public CommandRequestListener
{
    public:
        GeneralCommander();
        ~GeneralCommander();

        void registerCommandListener(const CommandListener* listener);
        void unregisterCommandListener(const CommandListener* listener);
        void notifyCommand(int commandId) const;

        void onNotifyCommandRequest(int commandId) const;

    protected:

    private:
        std::list<const CommandListener*> mListeners;

};
