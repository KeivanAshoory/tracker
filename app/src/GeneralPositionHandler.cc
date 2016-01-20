/*
 * =============================================================================
 *
 *       Filename:  GeneralPositionHandler.cc
 *
 *    Description:  GeneralPositionHandler
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
#include "GeneralPositionHandler.h"

using namespace std;

GeneralPositionHandler::GeneralPositionHandler(
        const GeneralPositionHandlerConfig& config)
{
    Logger::debug("GeneralPositionHandler::ctor");

}

GeneralPositionHandler::~GeneralPositionHandler()
{
    Logger::debug("GeneralPositionHandler::dtor");

}

void GeneralPositionHandler::registerPositionListener (const PositionListener* listener)
{
    mListeners.push_back(listener);
}

void GeneralPositionHandler::unregisterPositionListener(const PositionListener* listener)
{
    mListeners.remove(listener);
}

void GeneralPositionHandler::notifyPosition(int position) const
{
    for(std::list<const PositionListener*>::const_iterator
            it = mListeners.begin(); it != mListeners.end(); ++it) {
        (*it)->onNotifyPosition(position);
    }
}

void GeneralPositionHandler::onNotifyPositionReport(int position) const
{
    Logger::info("GeneralPositionHandler::onNotifyPositionReport: " + position);

    notifyPosition(position);
}
