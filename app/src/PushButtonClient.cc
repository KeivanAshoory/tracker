/*
 * =============================================================================
 *
 *       Filename:  PushButtonClient.cc
 *
 *    Description:  Push button client
 *
 *        Version:  1.0
 *        Created:  16/12/15 20:11:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#include "Logger.h"
#include "PushButtonClient.h"

PushButtonClient::PushButtonClient(const ClientConfig& config) : Client(config)

{
    Logger::debug("PushButtonClient::ctor");

}

PushButtonClient::~PushButtonClient()
{
    Logger::debug("PushButtonClient::dtor");

}

