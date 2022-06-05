#include "stringlogger.h"
#include <iostream>
#include<fstream>

StringLogger::StringLogger(std::string &&initalMsg, std::string &&filePath):
    AbstractLogging<std::string>{std::move(initalMsg), std::move(filePath)}
{
}

void StringLogger::logOut(std::string &&logMsg) const {
    std::cout << initalMsg + ": " + logMsg;
}

void StringLogger::logOut(std::string &&logMsg, std::string &&filePath) const {
    std::ofstream file;
    std::string logOutMsg {initalMsg + ": " + logMsg};

    std::cout << logOutMsg << std::endl;

    try {
        file.exceptions(std::ofstream::badbit | std::ofstream::failbit);
        file.open(filePath, std::ios::app);
        file << logOutMsg << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    file.close();
}

std::string StringLogger::logOut() const {
    return initalMsg + ": ";
}
