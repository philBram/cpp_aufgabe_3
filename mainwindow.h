#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Logger/qstringlogger.h"

class MainWindow :
        public QMainWindow,
        public QStringLogger
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void appOneClicked() const;
    void appTwoClicked() const;
    void appTreeClicked() const;
    void helpClicked() const;
    void aboutClicked() const;
    void updatesClicked() const;
    void checkForUpdates() const;

private:
    QString appOneName;
    QString appTwoName;
    QString appTreeName;

    QSize sizeHint() const override;

    QAction *appOneAction;
    QAction *appTwoAction;
    QAction *appTreeAction;

    QAction *helpAction;
    QAction *aboutAction;
    QAction *updatesAction;
    QAction *quitAction;

    void createActions() const;

    void detailsOutMsg(QString &&) const;
    void detailsOutMsg() const;
};
#endif // MAINWINDOW_H
