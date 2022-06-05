#ifndef QSTRINGLOGGER_H
#define QSTRINGLOGGER_H

#include <QString>
#include "abstractlogging.h"


class QStringLogger:
        public AbstractLogging<QString>
{
public:
    explicit QStringLogger(QString &&, QString &&filePath="logOut.log");

    void logOut(QString &&) const override;
    void logOut(QString &&, QString &&) const override;
    QString logOut() const override;
};

#endif // QSTRINGLOGGER_H
