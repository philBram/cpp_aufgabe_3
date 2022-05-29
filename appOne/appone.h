#ifndef APPONE_H
#define APPONE_H

#include "Logger/qstringlogger.h"
#include "formulasLib/mathFormulas.h"
#include <QMainWindow>
#include <QAction>
#include <QComboBox>
#include <QList>
#include <QMap>
#include <QDoubleSpinBox>
#include <QLabel>

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

    void comboBoxItemChanged(int const) const;
    void mathFunctionResultCalc() const;

private:
    QAction *helpAction;
    QAction *aboutAction;
    QAction *quitAction;

    QComboBox *mathFunctions;

    QLabel *mathFunctionResult;

    std::shared_ptr<QMap<QString, QList<QDoubleSpinBox *>>> mathFunctionsSpinBoxes;
    std::shared_ptr<QMap<QString, QList<QLabel *>>> mathFunctionsLabels;

    void createMathFunctionsNames() const;
    void createMathFunctionsInputs();
    QList<QDoubleSpinBox *> createSquareMathFunctionsSpinBoxes();
    QList<QDoubleSpinBox *> createRectangleMathFunctionsSpinBoxes();
    QList<QLabel *> createSquareMathFunctionsLabels();
    QList<QLabel *> createRectangleMathFunctionsLabels();
    void createMathFunctionsSignals() const;
    void createMenuActions() const;

    void areaOfSquareClicked() const;
    void permitOfSquareClicked() const;
    void areaOfRectangleClicked() const;
    void permitOfRectangleClicked() const;

    void hideAllItems() const;
    void showAllSquareItems() const;
    void showAllRectangleItems() const;
};

#endif // APPONE_H
