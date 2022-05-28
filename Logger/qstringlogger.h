#ifndef QSTRINGLOGGER_H
#define QSTRINGLOGGER_H

#include <QString>
#include "abstractlogging.h"


class QStringLogger: public AbstractLogging<QString>
{
public:
    explicit QStringLogger(QString &&);

    void logOut(QString &&) const override;
};

#endif // QSTRINGLOGGER_H
