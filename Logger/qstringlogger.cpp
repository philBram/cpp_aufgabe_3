#include "qstringlogger.h"
#include <QDebug>
#include <QTime>

QStringLogger::QStringLogger(QString &&initalMsg): AbstractLogging<QString>{std::move(initalMsg)}
{
}

void QStringLogger::logOut(QString &&logMsg) const {
    qDebug() << QTime::currentTime().toString() + ":  " + initalMsg + ": " + logMsg;
}
