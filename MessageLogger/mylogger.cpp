#include "mylogger.h"

namespace ml {
    // Constructors
    MyLogger::~MyLogger() {
        fs.close();
    }
    MyLogger::MyLogger() {
        fs.open(defaultlogfile, std::ios::app);
        messagestart = "Started logging to a default file";
    }
    MyLogger::MyLogger(const std::string& customlogfile) {
        fs.open(customlogfile, std::ios::app);
        messagestart = "Started logging. ";
    }
    MyLogger::MyLogger(MyLogger&& rhs) noexcept: fs{std::move(rhs.fs)}, messagestart{std::move(rhs.messagestart)} {}
    MyLogger& MyLogger::operator=(MyLogger&& rhs) noexcept {
        fs = std::move(rhs.fs);
        messagestart = std::move(rhs.messagestart);
        return *this;
    }

    // Methods
    void MyLogger::logToFile(const std::string& message) {
        messagestart = "FILE log: ";
        fs << message << "\n";
    }
    void MyLogger::logToConsole(const std::string& message) {
        messagestart = "CONSOLE log: ";
        std::cout << messagestart << message << "\n";
    }
    void MyLogger::logWithLevel(const std::string& message, LoggingLevels loglevel) {
        switch (loglevel) {
        case LoggingLevels::LOG_INFO:
            logToConsole("Log Level INFO: " + message);
            break;
        case LoggingLevels::LOG_WARNING:
            logToConsole("Log Level WARNING: " + message);
            break;
        case LoggingLevels::LOG_ALL:
            logToConsole("Log Level ALL: " + message);
            break;
        default:
            logToConsole("No logging Level: " + message);
            break;
        }
    }
    void MyLogger::logToAll(const std::string& message) {
        logToConsole(message);
        logToFile(message);
    }
}
