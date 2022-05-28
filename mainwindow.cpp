#include "mainwindow.h"
#include "appOne/appone.h"
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QApplication>
#include <QTextBrowser>
#include <QPalette>
#include <QFont>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      QStringLogger{"MainWindow"},
      appOneName{"appOne"},
      appTwoName{"appTwo"},
      appTreeName{"appTree"}
{
    logOut("app opened");

    QString appInfoText {"This application is intended to be as versatile as possible by providing all kinds of different apps."};

    QString fontFamily {"Time"};
    int fontSize {18};

    QString appMenuName {"Apps"};
    QString helpMenuName {"Help"};

    QString helpName {"Help"};
    QString aboutName {"About AppHarbor"};
    QString updatesName {"Check for Updates"};
    QString quitName {"Quit"};

    QFont qFont;
    qFont.setBold(true);
    qFont.setFamily(std::move(fontFamily));
    qFont.setPointSize(std::move(fontSize));

    QWidget *infoTextBrowser {new QTextBrowser(this)};
    dynamic_cast<QTextBrowser *>(infoTextBrowser)->setText(std::move(appInfoText));
    dynamic_cast<QTextBrowser *>(infoTextBrowser)->setFont(std::move(qFont));

    setCentralWidget(infoTextBrowser);

    appOneAction = new QAction(this);
    appTwoAction = new QAction(this);
    appTreeAction = new QAction(this);

    helpAction = new QAction(this);
    aboutAction = new QAction(this);
    updatesAction = new QAction(this);
    quitAction = new QAction(this);

    appOneAction->setText(std::move(appOneName));
    appTwoAction->setText(std::move(appTwoName));
    appTreeAction->setText(std::move(appTreeName));

    helpAction->setText(std::move(helpName));
    aboutAction->setText(std::move(aboutName));
    updatesAction->setText(std::move(updatesName));
    quitAction->setText(std::move(quitName));

    QMenu *apps {this->menuBar()->addMenu(std::move(appMenuName))};
    QMenu *help {this->menuBar()->addMenu(helpMenuName)};

    apps->addAction(appOneAction);
    apps->addAction(appTwoAction);
    apps->addAction(appTreeAction);

    help->addAction(helpAction);
    help->addAction(aboutAction);
    help->addAction(updatesAction);
    help->addAction(quitAction);

    createActions();
}

MainWindow::~MainWindow()
{
    logOut("app closed");
}

void MainWindow::createActions() const {
    connect(appOneAction, &QAction::triggered, this, &MainWindow::appOneClicked);
    connect(appTwoAction, &QAction::triggered, this, &MainWindow::appTwoClicked);
    connect(appTreeAction, &QAction::triggered, this, &MainWindow::appTreeClicked);

    connect(helpAction, &QAction::triggered, this, &MainWindow::helpClicked);
    connect(aboutAction, &QAction::triggered, this, &MainWindow::aboutClicked);
    connect(updatesAction, &QAction::triggered, this, &MainWindow::updatesClicked);
    connect(quitAction, &QAction::triggered, this, &QApplication::quit);
}

QSize MainWindow::sizeHint() const {
    return QSize(500, 500);
}

void MainWindow::appOneClicked() const
{
    QString logMsg {appOneName + " clicked"};
    AppOne *app {new AppOne};

    statusBar()->showMessage(logMsg, 3000);
    logOut(std::move(logMsg));

    app->setWindowTitle(appOneName);
    app->setAttribute(Qt::WA_DeleteOnClose);
    app->setFixedSize(500, 500);
    app->show();
}

void MainWindow::appTwoClicked() const
{
    QString logMsg {appTwoName + " clicked"};

    statusBar()->showMessage(logMsg, 3000);
    logOut(std::move(logMsg));
}

void MainWindow::appTreeClicked() const
{
    QString logMsg {appTreeName + " clicked"};

    statusBar()->showMessage(logMsg, 3000);
    logOut(std::move(logMsg));
}

void MainWindow::helpClicked() const
{
    QString logMsg {"help clicked"};

    statusBar()->showMessage(logMsg, 3000);
    logOut(std::move(logMsg));
}

void MainWindow::aboutClicked() const
{
    QString logMsg {"about clicked"};

    statusBar()->showMessage(logMsg, 3000);
    logOut(std::move(logMsg));

}

void MainWindow::updatesClicked() const {
    QString logMsg {"checking for updates..."};

    statusBar()->showMessage(logMsg, 3000);
    logOut(std::move(logMsg));

    QTimer::singleShot(3200, this, &MainWindow::checkForUpdates);
};

void MainWindow::checkForUpdates() const {
    QString logMsg {"no updates available"};

    statusBar()->showMessage(logMsg, 3000);
    logOut(std::move(logMsg));
}
