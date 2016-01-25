/*
 * =============================================================================
 *
 *       Filename:  PositionAcquirer.h
 *
 *    Description:  Position acquirer
 *
 *        Version:  1.0
 *        Created:  23/01/16 22:18:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#ifndef POSITIONACQUIRER_H

#define POSITIONACQUIRER_H

#include "VK162.h"
#include "PositionReporter.h"
#include "PositionAcquirerConfig.h"

class PositionAcquirer : public PositionReporter 
{
    public:
        PositionAcquirer(const PositionAcquirerConfig& config);
        ~PositionAcquirer();

        bool start();
        void stop();

        void tempOnTick();

    private:
        //TODO VK162 must be contacted with interface not direct!
        VK162 mGps;
};

#endif /* end of include guard: POSITIONACQUIRER_H */
