#include "mainwindow.h"
#include "appOne/appone.h"
#include "appTwo/apptwo.h"
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QApplication>
#include <QTextBrowser>
#include <QPalette>
#include <QFont>
#include <QTimer>
#include <QMessageBox>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      QStringLogger{"MainWindow"},
      appOneName{"MathCalc"},
      appTwoName{"NumInfo"}
{
    logOut("app opened");

    QString appInfoText {"This application is intended to be as versatile as possible by providing all kinds of different apps."};

    QString fontFamily {"Time"};
    int fontSize {14};

    QString appMenuName {"Apps"};
    QString helpMenuName {"Help"};

    QString helpName {"Help"};
    QString aboutName {"About AppHarbor"};
    QString updatesName {"Check for Updates"};
    QString quitName {"Quit"};

    QPushButton *button {new QPushButton(this)};
    button->setText("hello");
    button->show();

    QFont qFont;
    qFont.setBold(true);
    qFont.setFamily(std::move(fontFamily));
    qFont.setPointSize(std::move(fontSize));

    QWidget *infoTextBrowser {new QTextBrowser(this)};
    dynamic_cast<QTextBrowser *>(infoTextBrowser)->setText(std::move(appInfoText));
    dynamic_cast<QTextBrowser *>(infoTextBrowser)->setFont(std::move(qFont));
    dynamic_cast<QTextBrowser *>(infoTextBrowser)->setAlignment(Qt::AlignCenter);

    setCentralWidget(infoTextBrowser);

    appOneAction = new QAction(this);
    appTwoAction = new QAction(this);

    helpAction = new QAction(this);
    aboutAction = new QAction(this);
    updatesAction = new QAction(this);
    quitAction = new QAction(this);

    appOneAction->setText(std::move(appOneName));
    appTwoAction->setText(std::move(appTwoName));

    helpAction->setText(std::move(helpName));
    aboutAction->setText(std::move(aboutName));
    updatesAction->setText(std::move(updatesName));
    quitAction->setText(std::move(quitName));

    QMenu *appsMenu {this->menuBar()->addMenu(std::move(appMenuName))};
    QMenu *helpMenu {this->menuBar()->addMenu(helpMenuName)};

    appsMenu->addAction(appOneAction);
    appsMenu->addAction(appTwoAction);

    helpMenu->addAction(helpAction);
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(updatesAction);
    helpMenu->addAction(quitAction);

    createMenuActions();
}

MainWindow::~MainWindow()
{
    logOut("app closed");
}

void MainWindow::createMenuActions() const {
    connect(appOneAction, &QAction::triggered, this, &MainWindow::appOneClicked);
    connect(appTwoAction, &QAction::triggered, this, &MainWindow::appTwoClicked);

    connect(helpAction, &QAction::triggered, this, &MainWindow::helpClicked);
    connect(aboutAction, &QAction::triggered, this, &MainWindow::aboutClicked);
    connect(updatesAction, &QAction::triggered, this, &MainWindow::updatesClicked);
    connect(quitAction, &QAction::triggered, this, &QApplication::quit);
}

QSize MainWindow::sizeHint() const {
    return QSize(600, 600);
}

void MainWindow::appOneClicked()
{
    QString logMsg {appOneName + " clicked"};

    detailsOutMsg(std::move(logMsg));

    AppOne *app {new AppOne(this)};

    app->setWindowTitle(appOneName);
    app->setAttribute(Qt::WA_DeleteOnClose);
    app->setFixedSize(500, 500);
    app->show();
}

void MainWindow::appTwoClicked()
{
    QString logMsg {appTwoName + " clicked"};

    detailsOutMsg(std::move(logMsg));

    AppTwo *app {new AppTwo(this)};

    app->setWindowTitle(appTwoName);
    app->setAttribute(Qt::WA_DeleteOnClose);
    app->show();
}

void MainWindow::helpClicked() const
{
    QString logMsg {"help clicked"};

    detailsOutMsg(std::move(logMsg));

    QMessageBox help;

    help.setWindowTitle("Help");
    help.setText("Choose a app you want to open under 'Apps'");
    help.setIcon(QMessageBox::Information);
    help.setStandardButtons(QMessageBox::Ok);

    help.exec();
}

void MainWindow::aboutClicked() const
{
    QString logMsg {"about clicked"};

    detailsOutMsg(std::move(logMsg));

    QMessageBox about;

    about.setWindowTitle("Help");
    about.setText("This application is intended to be as versatile as possible by providing all kinds of different apps.");
    about.setIcon(QMessageBox::Question);
    about.setStandardButtons(QMessageBox::Ok);

    about.exec();
}

void MainWindow::updatesClicked() const {
    QString logMsg {"checking for updates..."};

    detailsOutMsg(std::move(logMsg));

    QTimer::singleShot(3200, this, &MainWindow::checkForUpdates);
};

void MainWindow::checkForUpdates() const {
    QString logMsg {"no updates available"};

    detailsOutMsg(std::move(logMsg));
}

void MainWindow::detailsOutMsg(QString &&msg) const {
    statusBar()->showMessage(msg, 3000);
    logOut(std::move(msg));
}

void MainWindow::detailsOutMsg() const {
    statusBar()->showMessage(logOut(), 3000);
    qDebug() << logOut();
}
