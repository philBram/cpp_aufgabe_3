#include "qstringlogger.h"
#include <QDebug>
#include <QDateTime>
#include <QFile>
#include <QTextStream>

QStringLogger::QStringLogger(QString &&initalMsg, QString &&filePath):
    AbstractLogging<QString>{std::move(initalMsg), std::move(filePath)}
{
}

void QStringLogger::logOut(QString &&logMsg) const {
    QFile file {std::move(this->filePath)};
    QString logOutMsg {QDateTime::currentDateTime().toString() + ":  " + initalMsg + ": " + logMsg};

    qDebug() << logOutMsg;

    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out {&file};
        out << logOutMsg + "\n";
        file.close();
    }
}

void QStringLogger::logOut(QString &&logMsg, QString &&filePath) const {
    QFile file {std::move(filePath)};
    QString logOutMsg {QDateTime::currentDateTime().toString() + ":  " + initalMsg + ": " + logMsg};

    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out {&file};
        out << logOutMsg + "\n";
        file.close();
    }

    qDebug() << logOutMsg;
}

QString QStringLogger::logOut() const {
    return QTime::currentTime().toString() + ":  " + initalMsg;
}
