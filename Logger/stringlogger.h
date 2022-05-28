#ifndef STRINGLOGGER_H
#define STRINGLOGGER_H

#include <string>
#include "abstractlogging.h"

class StringLogger: public AbstractLogging<std::string>
{
public:
    StringLogger(std::string &&initialMsg);

    void logOut(std::string &&) const override;
};

#endif // STRINGLOGGER_H
