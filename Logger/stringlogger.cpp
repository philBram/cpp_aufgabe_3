#include "stringlogger.h"
#include <iostream>
#include <chrono>
#include <ctime>

StringLogger::StringLogger(std::string &&initalMsg): AbstractLogging<std::string>(std::move(initalMsg))
{
}

void StringLogger::logOut(std::string &&logMsg) const {
    std::cout << initalMsg + ": " + logMsg;
}


std::string StringLogger::logOut() const {
    return initalMsg + ": ";
}
