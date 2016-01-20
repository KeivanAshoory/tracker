/*
 * =============================================================================
 *
 *       Filename:  ClientControl.cc
 *
 *    Description:  Client control abstract base class
 *
 *        Version:  1.0
 *        Created:  13/12/15 21:26:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#include "Logger.h"
#include "ClientControl.h"

ClientControl::ClientControl()
{
    Logger::debug("ClientControl::ctor");

}

ClientControl::~ClientControl()
{
    Logger::debug("ClientControl::dtor");

}
