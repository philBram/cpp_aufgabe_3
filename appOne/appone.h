#ifndef APPONE_H
#define APPONE_H

#include "Logger/qstringlogger.h"
#include "formulasLib/mathFormulas.h"
#include "mathfunctionelements.h"
#include "calculatemathfunctions.h"
#include <QMainWindow>
#include <QAction>
#include <QComboBox>
#include <QList>
#include <QMap>
#include <QDoubleSpinBox>
#include <QLabel>

class AppOne :
        public QMainWindow,
        public QStringLogger,
        public MathFunctionElements,
        public CalculateMathFunctions
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
    QString squareAreaCategoryName;
    QString squarePerimeterCategoryName;
    QString rectangleAreaCategoryName;
    QString rectanglePerimeterCategoryName;
    QString circleAreaCategoryName;
    QString circlePerimeterCategoryName;
    QString trapezoidAreaCategoryName;
    QString trapezoidPerimeterCategoryName;
    QString cuboidSurfaceAreaCategoryName;
    QString cuboidVolumeCategoryName;

    QAction *helpAction;
    QAction *aboutAction;
    QAction *quitAction;

    QComboBox *mathFunctions;

    QLabel *mathFunctionResult;

    QMap<QString, QList<QDoubleSpinBox *>> mathFunctionsSpinBoxes;
    QMap<QString, QList<QLabel *>> mathFunctionsLabels;

    void createMathFunctionsNames() const;
    void createMathFunctionsInputs();

    void createMathFunctionsSignals() const;
    void createMenuActions() const;

    void mathFunctionClicked(QString const &) const;
    void mathFunctionClicked(int const) const;

    void hideAllItems() const;
    void showMathFunctionCategoryItems(QString const &) const;
    void showMathFunctionCategoryItems(int const) const;
};

#endif // APPONE_H
