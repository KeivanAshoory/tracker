/*
 * =============================================================================
 *
 *       Filename:  logger.cc
 *
 *    Description:  Message logger
 *
 *        Version:  1.0
 *        Created:  13/10/15 22:45:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  none
 *
 * =============================================================================
 */

#include <cassert>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <syslog.h>
#include <sys/types.h>
#include <unistd.h>
#include <Logger.h>

using namespace std;

const string Logger::kLogfileTimeFormat = "%Y-%m-%d.%X";
const string Logger::kLogfileSeparator = ",";
const int Logger::kConsoleDateTimeWidth = 20;
const int Logger::kConsoleLoglevelWidth = 6;

Logger Logger::sInstance;

Logger::Logger()
{
    mInitialised = false;
    mLogDestinationInitialised = false;
    mLogIdentifier = "";
    mLogDestnation = DESTINATION_NONE;
    mLogfilePath = "";
    mMinimumLogLevel = LEVEL_NONE;
    mMinimumConsoleLevel = LEVEL_NONE;
}

Logger::~Logger()
{
    if(mInitialised) {
        if(closeLog()) {
            Logger::info("Logger closed.");
        } else {
            Logger::error("Failed to close Logger!");
        }
    }
}

bool Logger::init(LogDestination destination,
        LogLevel minLogLevel, LogLevel minConsoleLevel,
        const std::string& identifier, const std::string& logFilePath)
{
    return sInstance.initialise(destination, minLogLevel, minConsoleLevel,
            identifier,logFilePath);
}

void Logger::info(const std::string& message)
{
    sInstance.log(LEVEL_INFO, message);
}

void Logger::debug(const std::string& message)
{
    sInstance.log(LEVEL_DEBUG, message);
}

void Logger::error(const std::string& message)
{
    sInstance.log(LEVEL_ERROR, message);
}

void Logger::fatal(const std::string& message)
{
    sInstance.log(LEVEL_FATAL, message);
}

bool Logger::isInitialised()
{
    return sInstance.mInitialised;
}

bool Logger::isLogDestinationInitialised()
{
    return sInstance.mLogDestinationInitialised;
}

Logger::LogDestination Logger::getLogDestination()
{
    return sInstance.mLogDestnation;
}

std::string Logger::getLogIdentifier()
{
    return sInstance.mLogIdentifier;
}

Logger::LogLevel Logger::getMinimumLogLevel()
{
    return sInstance.mMinimumLogLevel;
}

Logger::LogLevel Logger::getMinimumConsoleLevel()
{
    return sInstance.mMinimumConsoleLevel;
}

void Logger::log(Logger::LogLevel level, const std::string& message)
{
    assert(mInitialised);   //One should not call log before init!

    if(level != LEVEL_NONE) {
        if(level >= mMinimumLogLevel) {
            commitLog(level, message);
        }

        if(level >= mMinimumConsoleLevel) {
            commitConsole(level, message);
        }
    }
}

bool Logger::initialise(LogDestination destination,
        LogLevel minLogLevel, LogLevel minConsoleLevel,
        const std::string& identifier, const std::string& logFilePath)
{
    assert(!mInitialised);   //Why should someone call init twice?!

    mInitialised = true;
    mLogDestnation = destination;
    mMinimumLogLevel = minLogLevel;
    mMinimumConsoleLevel = minConsoleLevel;
    mLogIdentifier = identifier;
    mLogfilePath = logFilePath;

    if(openLog()) {
        Logger::info("Logger initialised.");
        mLogDestinationInitialised = true;
        return true;    //Logger initialised successfully.
    } else {
        Logger::error("Failed to initialise Logger! Console is okay though.");
        mLogDestinationInitialised = false;
        return false;   //Failed to initialise logger. Console will work though.
    }
}

bool Logger::openLog()
{
    switch(mLogDestnation) {
        case DESTINATION_SYSLOG:
            return openSyslog();
        case DESTINATION_FILE:
            return openLogfile();
        case DESTINATION_NONE:
            return true;
        default:
            Logger::fatal("Unknown log destination!");
            assert(true);
            return false;
    }
}

bool Logger::closeLog()
{
    //TODO should we check mLogDestinationInitialised here?
    switch(mLogDestnation) {
        case DESTINATION_SYSLOG:
            return closeSyslog();
        case DESTINATION_FILE:
            return closeLogfile();
        case DESTINATION_NONE:
            return true;
        default:
            Logger::fatal("Unknown log destination!");
            assert(true);
            return false;
    }
}

bool Logger::commitLog(LogLevel level, const std::string& message)
{
    if(mLogDestinationInitialised) {
        switch(mLogDestnation) {
            case DESTINATION_SYSLOG:
                return commitSysLog(level, message);
            case DESTINATION_FILE:
                return commitLogfile(level, message);
            case DESTINATION_NONE:
                return true;
            default:
                Logger::fatal("Unknown log destination!");
                assert(true);
                return false;
        }
    } else {
        return false;
    }
}

bool Logger::openSyslog()
{
    openlog(mLogIdentifier.empty() ? NULL : mLogIdentifier.c_str(),
            LOG_CONS | LOG_NDELAY | LOG_PID,
            LOG_USER);
    //It looks like there is no normal way to test openlog success
    return true;
}

bool Logger::closeSyslog()
{
    ::closelog();   //call Linux closeLog not local method
    //It looks like there is no normal way to test closelog success
    return true;
}

bool Logger::commitSysLog(LogLevel level, const std::string& message) const
{
    syslog(Loglevel2SyslogLevel(level), "%s", message.c_str());
    return true;
}

bool Logger::openLogfile()
{
    if(!mLogfilePath.empty()) {
        //TODO check it is not already open! Assert on it
        mLogfileOutStream.open(mLogfilePath.c_str(),
                ofstream::out | ofstream::app);
        if(mLogfileOutStream.good()) {
            return true;
        } else {
            Logger::error("Failed to open/create log file!");
            return false;
        }
    } else {
        Logger::error("Log file path is empty!");
        return false;
    }
}

bool Logger::closeLogfile()
{
    //TODO should we check if it is initialised before close it?
    mLogfileOutStream.close();
    if(mLogfileOutStream.fail()) {
        Logger::error("Failed to close log file!");
    }
    return mLogfileOutStream.fail();
}

bool Logger::commitLogfile(LogLevel level, const std::string& message)
{
    switch(level) {
        case LEVEL_DEBUG:
        case LEVEL_INFO:
        case LEVEL_ERROR:
        case LEVEL_FATAL:
            if(mLogfileOutStream.good()) {
                mLogfileOutStream << getCurrentDateTime() << kLogfileSeparator;
                mLogfileOutStream << getLoglevelName(level) << kLogfileSeparator;
                mLogfileOutStream << mLogIdentifier << kLogfileSeparator;
                mLogfileOutStream << getpid() << kLogfileSeparator;
                mLogfileOutStream << message << endl;
                //TODO add tread id and tick as well
                return true;
            } else {
                Logger::error("Failed to write to log file!");
                return false;
            }
            break;
        case LEVEL_NONE:
        default:
            Logger::fatal("Unknown log level!");
            assert(true);
            return false;
    }
}

bool Logger::commitConsole(LogLevel level, const std::string& message) const
{
    ostream* pStandardOutputStream = NULL;
    switch(level) {
        case LEVEL_DEBUG:
        case LEVEL_INFO:
            pStandardOutputStream = &cout;
            break;
        case LEVEL_ERROR:
        case LEVEL_FATAL:
            pStandardOutputStream = &cerr;
            break;
        case LEVEL_NONE:
        default:
            Logger::fatal("Unknown log level!");
            assert(true);
            return false;
    }

    assert(pStandardOutputStream != NULL);

    //TODO Add color support based on:
    *pStandardOutputStream << setw(kConsoleDateTimeWidth) << left << getCurrentDateTime();
    *pStandardOutputStream << setw(kConsoleLoglevelWidth) << left << getLoglevelName(level);
    *pStandardOutputStream << message << endl;
    return true;
}

int Logger::Loglevel2SyslogLevel(LogLevel level)
{
    switch(level) {
        case LEVEL_DEBUG:
            return LOG_DEBUG;
        case LEVEL_INFO:
            return LOG_INFO;
        case LEVEL_ERROR:
            return LOG_ERR;
        case LEVEL_FATAL:
            return LOG_CRIT;
        case LEVEL_NONE:
        default:
            Logger::fatal("Unknown log level!");
            assert(true);
            return -1;  //TODO is that enough? What happens in release?
    }
}

string Logger::getLoglevelName(LogLevel level)
{
    switch(level) {
        case LEVEL_DEBUG:
            return "DEBUG";
        case LEVEL_INFO:
            return "INFO";
        case LEVEL_ERROR:
            return "ERROR";
        case LEVEL_FATAL:
            return "FATAL";
        case LEVEL_NONE:
        default:
            Logger::fatal("Unknown log level!");
            assert(true);
            return "NONE";
    }
}

const string Logger::getCurrentDateTime()
{
    time_t nowSeconds = time(NULL);
    if(nowSeconds != (time_t)(-1)) {
        struct tm* pLocalTime = localtime(&nowSeconds);
        if(pLocalTime != NULL) {
            char buf[100];
            if(strftime(buf, sizeof(buf), kLogfileTimeFormat.c_str(), pLocalTime) != 0) {
                return(buf);
            } else {
                //Unable to format time
                //TODO what to do?!
                return "";
            }
        } else {
            //Unable to get the local time
            //TODO what to do?!
            return "";
        }
    } else {
        //Unable to get the time
        //TODO what to do?!
        return "";
    }
}
