/*
 * =============================================================================
 *
 *       Filename:  PositionHandler.cc
 *
 *    Description:  Posiotion handler base abstract class
 *
 *        Version:  1.0
 *        Created:  12/12/15 20:12:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#include "Logger.h"
#include "PositionHandler.h"

PositionHandler::PositionHandler()
{
    Logger::debug("PositionHandler:ctor");

}

PositionHandler::~PositionHandler()
{
    Logger::debug("PositionHandler:dtor");

}

void PositionHandler::onNotifyPosition(int position) const
{
    //Do some extra work maybe
    onNotifyPositionEvent(position);
}
