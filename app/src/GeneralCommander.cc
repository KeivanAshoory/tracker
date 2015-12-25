/*
 * =============================================================================
 *
 *       Filename:  GeneralCommander.cc
 *
 *    Description:  GeneralCommander
 *
 *        Version:  1.0
 *        Created:  12/12/15 20:12:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#include "Logger.h"
#include "GeneralCommander.h"

using namespace std;

GeneralCommander::GeneralCommander(const string& config)
{

}

GeneralCommander::~GeneralCommander()
{

}

void GeneralCommander::registerCommandListener(const CommandListener* listener)
{
    mListeners.push_back(listener);
}

void GeneralCommander::unregisterCommandListener(const CommandListener* listener)
{
    mListeners.remove(listener);
}

void GeneralCommander::notifyCommand(int commandId) const
{
    for(std::list<const CommandListener*>::const_iterator
            it = mListeners.begin(); it != mListeners.end(); ++it) {
        (*it)->onNotifyCommand(commandId);
    }
}

void GeneralCommander::onNotifyCommandRequest(int commandId) const
{
    Logger::info("GeneralCommander::onNotifyCommandRequest: " + commandId);

    notifyCommand(commandId);
}
