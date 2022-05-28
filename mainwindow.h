#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qstringlogger.h"
#include "appone.h"

class MainWindow : public QMainWindow, public QStringLogger, public testing::appOne
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void testing() const override;

signals:

private slots:
    void appOneClicked() const;
    void appTwoClicked() const;
    void appTreeClicked() const;
    void aboutClicked() const;
    void helpClicked() const;

private:
    QSize sizeHint() const override;

    QAction *appOneAction;
    QAction *appTwoAction;
    QAction *appTreeAction;
    QAction *quitAction;
    QAction *aboutAction;
    QAction *helpAction;

    void createActions() const;
};
#endif // MAINWINDOW_H
