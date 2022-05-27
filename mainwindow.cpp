#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), QStringLogger{"MainWindow"}
{
    appOneAction = new QAction(this);
    appTwoAction = new QAction(this);
    appTreeAction = new QAction(this);
    quitAction = new QAction(this);

    QString appOneName {"appOne"};
    QString appTwoName {"appTwo"};
    QString appTreeName {"appTree"};
    QString quitName {"Quit"};

    appOneAction->setText(std::move(appOneName));
    appTwoAction->setText(std::move(appTwoName));
    appTreeAction->setText(std::move(appTreeName));
    quitAction->setText(std::move(quitName));

    QString appMenuName {"Apps"};
    QMenu *apps {menuBar()->addMenu(std::move(appMenuName))};

    apps->addAction(appOneAction);
    apps->addAction(appTwoAction);
    apps->addAction(appTreeAction);
}

MainWindow::~MainWindow()
{
}

QSize MainWindow::sizeHint() const {
    return QSize(500, 500);
}
