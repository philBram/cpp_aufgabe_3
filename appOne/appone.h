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
    QString squareAreaCategoryName;
    QString squarePerimeterCategoryName;
    QString rectangleAreaCategoryName;
    QString rectanglePerimeterCategoryName;
    QString trapezoidAreaCategoryName;
    QString trapezoidPerimeterCategoryName;

    QAction *helpAction;
    QAction *aboutAction;
    QAction *quitAction;

    QComboBox *mathFunctions;

    QLabel *mathFunctionResult;

    std::shared_ptr<QMap<QString, QList<QDoubleSpinBox *>>> mathFunctionsSpinBoxes;
    std::shared_ptr<QMap<QString, QList<QLabel *>>> mathFunctionsLabels;

    void createMathFunctionsNames() const;
    void createMathFunctionsInputs();

    QList<QDoubleSpinBox *> createSquareAreaPerimeterMathFunctionsSpinBoxes();
    QList<QDoubleSpinBox *> createRectangleAreaPerimeterMathFunctionsSpinBoxes();
    QList<QDoubleSpinBox *> createTrapezoidAreaMathFunctionsSpinBoxes();
    QList<QDoubleSpinBox *> createTrapezoidPerimeterMathFunctionsSpinBoxes();

    QList<QLabel *> createSquareAreaPerimeterMathFunctionsLabels();
    QList<QLabel *> createRectangleAreaPerimeterMathFunctionsLabels();
    QList<QLabel *> createTrapezoidAreaMathFunctionsLabels();
    QList<QLabel *> createTrapezoidPerimeterMathFunctionsLabels();

    void createMathFunctionsSignals() const;
    void createMenuActions() const;

    void mathFunctionClicked(QString const &) const;

    void calculateSquareArea() const;
    void calculateSquarePerimeter() const;
    void calculateRectangleArea() const;
    void calculateRectanglePerimeter() const;
    void calculateTrapezoidArea() const;
    void calculateTrapezoidPerimeter() const;

    void hideAllItems() const;
    void showMathFunctionCategoryItems(QString const &) const;
};

#endif // APPONE_H
