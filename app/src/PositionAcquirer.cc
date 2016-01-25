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

#include "Logger.h"
#include "PositionAcquirer.h"

PositionAcquirer::PositionAcquirer(const PositionAcquirerConfig& config) :
    mGps(VK162(config.getDevice()))
{
    Logger::debug("PositionAcquirer::ctor");

}

PositionAcquirer::~PositionAcquirer()
{
    Logger::debug("PositionAcquirer::dtor");
    // I don't think we need to do anything for GPS as it should be closed on
    // its own dtor.

}

bool PositionAcquirer::start()
{
    if(!mGps.openSerial(VK162::Asynchronous)) {
        Logger::fatal("Failed to open serial port!");
        //TODO Make sure you do all the clean-up!!
        return false;
    }

    Logger::info("Serial port opened successfully.");
    return true;
}

void PositionAcquirer::stop()
{
    mGps.closeSerial();
}

void PositionAcquirer::tempOnTick()
{
    if(mGps.isDataAvailable()) {
        if(mGps.readSerial()) {
        }
    }
}
