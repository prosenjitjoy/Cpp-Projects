#ifndef MYLOGGER_H
#define MYLOGGER_H

#include <iostream>
#include <fstream>

namespace ml {
    enum class LoggingLevels {
        LOG_INFO,
        LOG_WARNING,
        LOG_ALL
    };

    const std::string defaultlogfile = "defaultlogfile.txt";

    class MyLogger {
    private:
        // members
        std::fstream fs;
        std::string messagestart;
    public:
        // constructos
        MyLogger();
        explicit MyLogger(const std::string& customlogfile);
        MyLogger(const MyLogger& rhs) = delete;
        MyLogger& operator=(const MyLogger& rhs) = delete;
        MyLogger(MyLogger&& rhs) noexcept;
        MyLogger& operator=(MyLogger&& rhs) noexcept;

        // methods
        void logToFile(const std::string& message);
        void logToConsole(const std::string& message);
        void logWithLevel(const std::string& message, LoggingLevels loglevel);
        void logToAll(const std::string& message);

        // destructor
        ~MyLogger();
    };
}

#endif // MYLOGGER_H
