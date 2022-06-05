#ifndef APPTWO_H
#define APPTWO_H

#include <QMainWindow>

namespace Ui {
class AppTwo;
}

class AppTwo : public QMainWindow
{
    Q_OBJECT

public:
    explicit AppTwo(QWidget *parent = nullptr);
    ~AppTwo();

private:
    Ui::AppTwo *ui;
};

#endif // APPTWO_H
