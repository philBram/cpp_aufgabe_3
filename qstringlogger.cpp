#include "qstringlogger.h"
#include <QDebug>

QStringLogger::QStringLogger(QString &&initalMsg): AbstractLogging<QString>{std::move(initalMsg)}
{
}

void QStringLogger::logOut(QString &&logMsg) const {
    qDebug() << initalMsg + ": " + logMsg;
}
