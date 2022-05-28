#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QApplication>
#include <QTextBrowser>
#include <QPalette>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), QStringLogger{"MainWindow"}
{
    QString appInfoText {"This application is intended to be as versatile as possible by providing all kinds of different apps."};

    QString fontFamily {"Time"};
    int fontSize {18};

    QString appOneName {"appOne"};
    QString appTwoName {"appTwo"};
    QString appTreeName {"appTree"};

    QString quitName {"Quit"};
    QString aboutName {"About"};
    QString helpName {"Help"};

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
    quitAction = new QAction(this);
    aboutAction = new QAction(this);
    helpAction = new QAction(this);

    appOneAction->setText(std::move(appOneName));
    appTwoAction->setText(std::move(appTwoName));
    appTreeAction->setText(std::move(appTreeName));
    quitAction->setText(std::move(quitName));
    aboutAction->setText(std::move(aboutName));
    helpAction->setText(std::move(helpName));

    QString appMenuName {"Apps"};
    QMenu *apps {this->menuBar()->addMenu(std::move(appMenuName))};

    QString quitMenuName {"Quit"};
    QMenu *quit {this->menuBar()->addMenu(std::move(quitMenuName))};

    QString aboutMenuName {"About"};
    QMenu *about {this->menuBar()->addMenu(std::move(aboutMenuName))};

    QString helpMenuName {"Help"};
    QMenu *help {this->menuBar()->addMenu(helpMenuName)};

    apps->addAction(appOneAction);
    apps->addAction(appTwoAction);
    apps->addAction(appTreeAction);

    quit->addAction(quitAction);
    about->addAction(aboutAction);
    help->addAction(helpAction);

    createActions();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createActions() const {
    connect(appOneAction, &QAction::triggered, this, &MainWindow::appOneClicked);
    connect(appTwoAction, &QAction::triggered, this, &MainWindow::appTwoClicked);
    connect(appTreeAction, &QAction::triggered, this, &MainWindow::appTreeClicked);

    connect(quitAction, &QAction::triggered, this, &QApplication::quit);
    connect(aboutAction, &QAction::triggered, this, &MainWindow::aboutClicked);
    connect(helpAction, &QAction::triggered, this, &MainWindow::helpClicked);
}

QSize MainWindow::sizeHint() const {
    return QSize(500, 500);
}

void MainWindow::appOneClicked() const
{
    QString logMsg {"app one clicked"};
    logOut(std::move(logMsg));

    statusBar()->showMessage(std::move(logMsg), 3000);
}

void MainWindow::appTwoClicked() const
{
    QString logMsg {"app two clicked"};
    logOut(std::move(logMsg));

    statusBar()->showMessage(std::move(logMsg), 3000);
}

void MainWindow::appTreeClicked() const
{
    QString logMsg {"app tree clicked"};
    logOut(std::move(logMsg));

    statusBar()->showMessage(std::move(logMsg), 3000);
}

void MainWindow::aboutClicked() const
{
    QString logMsg {"about clicked"};
    logOut(std::move(logMsg));

    statusBar()->showMessage(std::move(logMsg), 3000);
}

void MainWindow::helpClicked() const
{
    QString logMsg {"help clicked"};
    logOut(std::move(logMsg));

    statusBar()->showMessage(std::move(logMsg), 3000);
}
