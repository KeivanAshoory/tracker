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

#ifndef GENERAL_COMMANDER_H
#define GENERAL_COMMANDER_H

#include <list>
#include <string>
#include "CommandNotifier.h"
#include "CommandListener.h"
#include "CommandRequestListener.h"

class GeneralCommander : public CommandNotifier, public CommandRequestListener
{
    public:
        GeneralCommander(const std::string& config);
        ~GeneralCommander();

        // Impelement CommandNotifier
        void registerCommandListener(const CommandListener* listener);
        void unregisterCommandListener(const CommandListener* listener);

        // Impelement CommandRequestListener
        void onNotifyCommandRequest(int commandId) const;

    protected:
        // Impelement CommandNotifier
        void notifyCommand(int commandId) const;

    private:
        std::list<const CommandListener*> mListeners;
};

#endif
