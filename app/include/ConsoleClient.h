/*
 * =============================================================================
 *
 *       Filename:  ConsoleClient.h
 *
 *    Description:  Console Client
 *
 *        Version:  1.0
 *        Created:  14/12/15 21:39:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef CONSOLE_CLIENT_H
#define CONSOLE_CLIENT_H

#include "Client.h"

class ConsoleClient : public Client
{
    public:
        ConsoleClient();
        ~ConsoleClient();
};

#endif
