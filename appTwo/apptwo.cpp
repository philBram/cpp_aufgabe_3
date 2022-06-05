#include "apptwo.h"
#include "ui_apptwo.h"

AppTwo::AppTwo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AppTwo)
{
    ui->setupUi(this);
}

AppTwo::~AppTwo()
{
    delete ui;
}
