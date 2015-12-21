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

#include "PositionHandler.h"

PositionHandler::PositionHandler()
{

}

PositionHandler::~PositionHandler()
{

}

void PositionHandler::onNotifyPosition(int position) const
{
    //Do some extra work maybe
    onNotifyPositionEvent(position);
}
