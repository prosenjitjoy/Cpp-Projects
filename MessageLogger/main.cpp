#include <iostream>
#include <fstream>
#include "mylogger.h"

int main()
{
    ml::MyLogger o1;
    o1.logToConsole("Console log message 1.");
    o1.logToFile("Default file name log message 1.");
    o1.logWithLevel("Console log message 2.", ml::LoggingLevels::LOG_INFO);
    o1.logToAll("Logging to both the console and a file from o1.");

    ml::MyLogger o2{"mylogfile.txt"};
    o2.logToConsole("Console log message 1.");
    o2.logToFile("Custom file name log message 1.");
    o2.logWithLevel("Console log message 2.", ml::LoggingLevels::LOG_WARNING);
    o2.logToAll("Logging to both the console and a file from o2.");

    ml::MyLogger o3 = std::move(o2);
    o3.logToAll("Logging to both the console and a file from 03.");
    return 0;
}
