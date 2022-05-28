#ifndef APPONE_H
#define APPONE_H

#include "Logger/qstringlogger.h"
#include <QMainWindow>
#include <QAction>

class AppOne :
        public QMainWindow,
        public QStringLogger
{
    Q_OBJECT
public:
    explicit AppOne(QWidget *parent = nullptr);
    ~AppOne();

signals:

private slots:
    void helpClicked() const;
    void aboutClicked() const;
    void quitClicked();

private:
    QAction *helpAction;
    QAction *aboutAction;
    QAction *quitAction;

    void createActions() const;
};

#endif // APPONE_H
