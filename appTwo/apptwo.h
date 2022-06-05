#ifndef APPTWO_H
#define APPTWO_H

#include <QMainWindow>
#include <QList>
#include <QNetworkAccessManager>
#include "Logger/qstringlogger.h"

namespace Ui {
class AppTwo;
}

class AppTwo :
        public QMainWindow,
        public QStringLogger
{
    Q_OBJECT

public:
    explicit AppTwo(QWidget *parent = nullptr);
    ~AppTwo();

private slots:
    void helpClicked();
    void aboutClicked();
    void quitClicked();

    void dataReadyToRead();
    void dataReadFinished();

    void getNumInfoButtonClicked();
    void getNumClearButtonClicked();
    void getNumRemoveButtonClicked();

private:
    Ui::AppTwo *ui;

    QSize sizeHint() const override;

    QNetworkAccessManager *netManager;
    QNetworkReply *netReply;
    std::shared_ptr<QByteArray> dataBuffer;

    QList<QString> numberInfos;

    void createMenuActions();
    void createButtonSignals();
    void createNetworkSignals();
};

#endif // APPTWO_H
