#include "mainwindow.h"
#include <QApplication>
#include "formulasLib/mathFormulas.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("AppHarbor");
    w.show();
    return a.exec();
}
