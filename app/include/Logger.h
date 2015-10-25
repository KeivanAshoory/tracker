/*
 * =============================================================================
 *
 *       Filename:  Logger.h
 *
 *    Description:  Message logger
 *
 *        Version:  1.0
 *        Created:  13/10/15 22:46:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  none
 *
 * =============================================================================
 */

#include <string>
#include <iostream>
#include <fstream>

class Logger
{
    public:
        enum LogLevel {
            LEVEL_DEBUG = 0,
            LEVEL_INFO,
            LEVEL_ERROR,
            LEVEL_FATAL,
            LEVEL_NONE
        };

        enum LogDestination {
            DESTINATION_SYSLOG,
            DESTINATION_FILE,
            DESTINATION_NONE
        };

        static bool init(LogDestination destination,
                LogLevel minLogLevel, LogLevel minConsoleLevel,
                const std::string& identifier, const std::string& logfilePath);

        static void info(const std::string& message);
        static void debug(const std::string& message);
        static void error(const std::string& message);
        static void fatal(const std::string& message);

        static bool isInitialised();
        static bool isLogDestinationInitialised();
        static LogDestination getLogDestination();
        static std::string getLogIdentifier();
        static LogLevel getMinimumLogLevel();
        static LogLevel getMinimumConsoleLevel();

    private:
        static const std::string kLogfileTimeFormat;
        static const std::string kLogfileSeparator;
        static const int kConsoleDateTimeWidth;
        static const int kConsoleLoglevelWidth;

        Logger();
        ~Logger();

        void log(LogLevel level, const std::string& message);
        bool initialise(LogDestination destination,
                LogLevel minLogLevel, LogLevel minConsoleLevel,
                const std::string& identifier, const std::string& logfilePath);

        bool openLog();
        bool closeLog();
        bool commitLog(LogLevel level, const std::string& message);

        bool openSyslog();
        bool closeSyslog();
        bool commitSysLog(LogLevel level, const std::string& message) const;

        bool openLogfile();
        bool closeLogfile();
        bool commitLogfile(LogLevel level, const std::string& message);

        bool commitConsole(LogLevel level, const std::string& message) const;

        //static Logger& instance();
        static int Loglevel2SyslogLevel(LogLevel level);
        static std::string getLoglevelName(LogLevel level);
        static const std::string getCurrentDateTime();

        static Logger sInstance;

        bool mInitialised;
        bool mLogDestinationInitialised;
        std::ofstream mLogfileOutStream;
        std::string mLogIdentifier;
        LogDestination mLogDestnation;
        std::string mLogfilePath;
        LogLevel mMinimumLogLevel;
        LogLevel mMinimumConsoleLevel;
};
