#ifndef MATHFUNCTIONELEMENTS_H
#define MATHFUNCTIONELEMENTS_H

#include <QDoubleSpinBox>
#include <QLabel>
#include <QWidget>

class MathFunctionElements
{
protected:
    QList<QDoubleSpinBox *> createSquareAreaPerimeterMathFunctionSpinBoxes(QWidget *const) const;
    QList<QDoubleSpinBox *> createRectangleAreaPerimeterMathFunctionSpinBoxes(QWidget *const) const;
    QList<QDoubleSpinBox *> createCircleAreaPerimeterMathFunctionSpinBoxes(QWidget *const) const;
    QList<QDoubleSpinBox *> createTrapezoidAreaMathFunctionSpinBoxes(QWidget *const) const;
    QList<QDoubleSpinBox *> createTrapezoidPerimeterMathFunctionSpinBoxes(QWidget *const) const;
    QList<QDoubleSpinBox *> createCuboidSurfaceAreaVolumeMathFunctionSpinBoxes(QWidget *const) const;

    QList<QLabel *> createSquareAreaPerimeterMathFunctionLabels(QWidget *const) const;
    QList<QLabel *> createRectangleAreaPerimeterMathFunctionLabels(QWidget *const) const;
    QList<QLabel *> createCircleAreaPerimeterMathFunctionLabels(QWidget *const) const;
    QList<QLabel *> createTrapezoidAreaMathFunctionLabels(QWidget *const) const;
    QList<QLabel *> createTrapezoidPerimeterMathFunctionLabels(QWidget *const) const;
    QList<QLabel *> createCuboidSurfaceAreaVolumeMathFunctionLabels(QWidget *const) const;

public:
    explicit MathFunctionElements();
};

#endif // MATHFUNCTIONELEMENTS_H
