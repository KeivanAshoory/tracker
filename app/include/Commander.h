/*
 * =============================================================================
 *
 *       Filename:  Commander.h
 *
 *    Description:  Commander base abstract class
 *
 *        Version:  1.0
 *        Created:  12/12/15 20:09:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef COMMANDER_H
#define COMMANDER_H

#include "CommandRequestNotifier.h"
#include <list>

class Commander : public CommandRequestNotifier
{
    public:
        virtual ~Commander() = 0;

        //Implement CommandRequestNotifier
        virtual void registerCommandRequestListener(
                const CommandRequestListener* listener
                );
        virtual void unregisterCommandRequestListener(
                const CommandRequestListener* listener
                );

    protected:
        Commander();

        //Implement CommandRequestNotifier
        virtual void notifyCommandRequest(int commandId) const;

    private:
        std::list<const CommandRequestListener*> mListeners;
};

#endif
