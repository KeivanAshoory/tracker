/*
 * =============================================================================
 *
 *       Filename:  PushButtonClient.h
 *
 *    Description:  Push button client
 *
 *        Version:  1.0
 *        Created:  16/12/15 20:10:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef PUSH_BUTTON_CLIENT_H
#define PUSH_BUTTON_CLIENT_H

#include "ClientConfig.h"
#include "Client.h"

class PushButtonClient : public Client
{
    public:
        PushButtonClient(const ClientConfig& config);
        ~PushButtonClient();
};

#endif
