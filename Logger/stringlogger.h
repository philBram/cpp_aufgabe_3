#ifndef STRINGLOGGER_H
#define STRINGLOGGER_H

#include <string>
#include "abstractlogging.h"

class StringLogger:
        public AbstractLogging<std::string>
{
public:
    StringLogger(std::string &&initialMsg, std::string &&filePath);

    void logOut(std::string &&) const override;
    void logOut(std::string &&, std::string &&) const override;
    std::string logOut() const override;
};

#endif // STRINGLOGGER_H
