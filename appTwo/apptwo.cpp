#include "apptwo.h"
#include "ui_apptwo.h"
#include <QString>
#include <QMessageBox>
#include <QNetworkReply>

AppTwo::AppTwo(QWidget *parent) :
    QMainWindow(parent),
    QStringLogger{"NumInfo"},
    netManager {new QNetworkAccessManager(this)},
    dataBuffer {std::make_shared<QByteArray>()},
    ui(new Ui::AppTwo)
{
    ui->setupUi(this);

    createMenuActions();
    createButtonSignals();
}

AppTwo::~AppTwo()
{
    logOut("app closed");
    delete ui;
}

void AppTwo::createMenuActions() {
    connect(ui->actionHelp, &QAction::triggered, this, &AppTwo::helpClicked);
    connect(ui->actionAbout_NumInfo, &QAction::triggered, this, &AppTwo::aboutClicked);
    connect(ui->actionQuit, &QAction::triggered, this, &AppTwo::quitClicked);
}

void AppTwo::createButtonSignals() {
    connect(ui->getNumInfoButton, &QPushButton::clicked, this, &AppTwo::getNumInfoButtonClicked);
    connect(ui->getNumClearButton, &QPushButton::clicked, this, &AppTwo::getNumClearButtonClicked);
    connect(ui->getNumRemoveButton, &QPushButton::clicked, this, &AppTwo::getNumRemoveButtonClicked);
}

void AppTwo::createNetworkSignals() {
    connect(netReply, &QIODevice::readyRead, this, &AppTwo::dataReadyToRead);
    connect(netReply, &QNetworkReply::finished, this, &AppTwo::dataReadFinished);
}

void AppTwo::helpClicked() {
    QString msg {"help clicked"};

    statusBar()->showMessage(msg, 3000);
    logOut(std::move(msg));

    QMessageBox help;

    help.setWindowTitle("Help");
    help.setText("Use the input field to choose a number and press the \"Get Number Info\" "
                 "button to get information about that number");
    help.setIcon(QMessageBox::Information);
    help.setStandardButtons(QMessageBox::Ok);

    help.exec();
}


void AppTwo::aboutClicked()
{
    QString msg {"about clicked"};

    statusBar()->showMessage(msg, 3000);
    logOut(std::move(msg));

    QMessageBox about;

    about.setWindowTitle("About");
    about.setText("This application can get information about a number");
    about.setIcon(QMessageBox::Question);
    about.setStandardButtons(QMessageBox::Ok);

    about.exec();
}


void AppTwo::quitClicked()
{
    QString msg {"quit clicked"};

    statusBar()->showMessage(msg, 3000);
    logOut(std::move(msg));

    this->close();
}

void AppTwo::dataReadyToRead()
{
    dataBuffer->append(netReply->readAll());
}

void AppTwo::dataReadFinished()
{
    if (netReply->error()) {
        logOut("Request failed");
    }
    else {
        logOut("Request succeded");
        ui->getNumListWidget->addItem(QString(*dataBuffer));
        dataBuffer->clear();
    }
}

void AppTwo::getNumInfoButtonClicked()
{
    QString msg {"getNumInfo button clicked"};

    statusBar()->showMessage(msg, 3000);
    logOut(std::move(msg));

    QString apiUrl {"http://numberapi.com/" + QString::number(ui->getNumSpinBox->value()) + "/math"};

    QNetworkRequest request;
    request.setUrl(QUrl(apiUrl));

    netReply = netManager->get(request);

    createNetworkSignals();
}

void AppTwo::getNumClearButtonClicked()
{
    ui->getNumListWidget->clear();
}

void AppTwo::getNumRemoveButtonClicked()
{
    QList<QListWidgetItem *> items {ui->getNumListWidget->selectedItems()};

    foreach (QListWidgetItem *const &item, items) {
        ui->getNumListWidget->removeItemWidget(item);
        delete item;
    }
}

QSize AppTwo::sizeHint() const
{
    return QSize(500, 500);
}
