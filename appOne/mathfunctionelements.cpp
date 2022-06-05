#include "mathfunctionelements.h"

MathFunctionElements::MathFunctionElements()
{
}

QList<QDoubleSpinBox *> MathFunctionElements::createSquareAreaPerimeterMathFunctionSpinBoxes(QWidget *const widget) const
{
    QList<QDoubleSpinBox *> squareInputs;

    QDoubleSpinBox *squareLengthInput {new QDoubleSpinBox(widget)};
    squareLengthInput->move(50, 200);

    squareInputs.emplace_back(squareLengthInput);

    return squareInputs;
}

QList<QDoubleSpinBox *> MathFunctionElements::createRectangleAreaPerimeterMathFunctionSpinBoxes(QWidget *const widget) const
{
    QList<QDoubleSpinBox *> rectangleInputs;

    QDoubleSpinBox *rectangleLengthInput {new QDoubleSpinBox(widget)};
    rectangleLengthInput->move(50, 200);

    QDoubleSpinBox *rectangleWidthInput {new QDoubleSpinBox(widget)};
    rectangleWidthInput->move(50, 300);

    rectangleInputs.emplace_back(rectangleLengthInput);
    rectangleInputs.emplace_back(rectangleWidthInput);

    return rectangleInputs;
}

QList<QDoubleSpinBox *> MathFunctionElements::createCircleAreaPerimeterMathFunctionSpinBoxes(QWidget * const widget) const
{
    QList<QDoubleSpinBox *> circleInputs;

    QDoubleSpinBox *circleRadiusInput {new QDoubleSpinBox(widget)};
    circleRadiusInput->move(50, 200);

    circleInputs.emplace_back(circleRadiusInput);

    return circleInputs;
}

QList<QDoubleSpinBox *> MathFunctionElements::createTrapezoidAreaMathFunctionSpinBoxes(QWidget *const widget) const
{
    QList<QDoubleSpinBox *> trapezoidAreaInputs;

    QDoubleSpinBox *trapezoidAreaLongBaseInput {new QDoubleSpinBox(widget)};
    trapezoidAreaLongBaseInput->move(50, 200);

    QDoubleSpinBox *trapeZoidAreaShortBaseInput {new QDoubleSpinBox(widget)};
    trapeZoidAreaShortBaseInput->move(50, 300);

    QDoubleSpinBox *trapeZoidAreaHeightInput {new QDoubleSpinBox(widget)};
    trapeZoidAreaHeightInput->move(200, 200);

    trapezoidAreaInputs.emplace_back(trapezoidAreaLongBaseInput);
    trapezoidAreaInputs.emplace_back(trapeZoidAreaShortBaseInput);
    trapezoidAreaInputs.emplace_back(trapeZoidAreaHeightInput);

    return trapezoidAreaInputs;
}

QList<QDoubleSpinBox *> MathFunctionElements::createTrapezoidPerimeterMathFunctionSpinBoxes(QWidget *const widget) const
{
    QList<QDoubleSpinBox *> trapezoidPerimeterInputs;

    QDoubleSpinBox *trapezoidPerimeterLongBaseInput {new QDoubleSpinBox(widget)};
    trapezoidPerimeterLongBaseInput->move(50, 200);

    QDoubleSpinBox *trapezoidPerimeterShortBaseInput {new QDoubleSpinBox(widget)};
    trapezoidPerimeterShortBaseInput->move(50, 300);

    QDoubleSpinBox *trapezoidPerimeterSideAInput {new QDoubleSpinBox(widget)};
    trapezoidPerimeterSideAInput->move(200, 200);

    QDoubleSpinBox *trapezoidPerimeterSideBInput {new QDoubleSpinBox(widget)};
    trapezoidPerimeterSideBInput->move(200, 300);

    trapezoidPerimeterInputs.emplace_back(trapezoidPerimeterLongBaseInput);
    trapezoidPerimeterInputs.emplace_back(trapezoidPerimeterShortBaseInput);
    trapezoidPerimeterInputs.emplace_back(trapezoidPerimeterSideAInput);
    trapezoidPerimeterInputs.emplace_back(trapezoidPerimeterSideBInput);

    return trapezoidPerimeterInputs;
}

QList<QDoubleSpinBox *> MathFunctionElements::createCuboidSurfaceAreaVolumeMathFunctionSpinBoxes(QWidget *const widget) const
{
    QList<QDoubleSpinBox *> cuboidInputs;

    QDoubleSpinBox *cuboidHeightInput {new QDoubleSpinBox(widget)};
    cuboidHeightInput->move(50, 200);

    QDoubleSpinBox *cuboidLengthInput {new QDoubleSpinBox(widget)};
    cuboidLengthInput->move(50, 300);

    QDoubleSpinBox *cuboidDepthInput {new QDoubleSpinBox(widget)};
    cuboidDepthInput->move(200, 200);

    cuboidInputs.emplace_back(cuboidHeightInput);
    cuboidInputs.emplace_back(cuboidLengthInput);
    cuboidInputs.emplace_back(cuboidDepthInput);

    return cuboidInputs;
}

QList<QLabel *> MathFunctionElements::createSquareAreaPerimeterMathFunctionLabels(QWidget *const widget) const
{
    QList<QLabel *> squareLabels;

    QLabel *squareLengthLabel {new QLabel(widget)};
    squareLengthLabel->setText("Length");
    squareLengthLabel->move(50, 160);

    squareLabels.emplace_back(squareLengthLabel);

    return squareLabels;
}

QList<QLabel *> MathFunctionElements::createRectangleAreaPerimeterMathFunctionLabels(QWidget *const widget) const
{
    QList<QLabel *> rectangleLabels;

    QLabel *rectangleLengthLabel {new QLabel(widget)};
    rectangleLengthLabel->setText("Length");
    rectangleLengthLabel->move(50, 160);

    QLabel *rectangleWidthLabel {new QLabel(widget)};
    rectangleWidthLabel->setText("Width");
    rectangleWidthLabel->move(50, 260);

    rectangleLabels.emplace_back(rectangleLengthLabel);
    rectangleLabels.emplace_back(rectangleWidthLabel);

    return rectangleLabels;
}

QList<QLabel *> MathFunctionElements::createCircleAreaPerimeterMathFunctionLabels(QWidget * const widget) const
{
    QList<QLabel *> circleLabels;

    QLabel *circleRadiusLabel {new QLabel(widget)};
    circleRadiusLabel->setText("Radius");
    circleRadiusLabel->move(50, 160);

    circleLabels.emplace_back(circleRadiusLabel);

    return circleLabels;
}

QList<QLabel *> MathFunctionElements::createTrapezoidAreaMathFunctionLabels(QWidget *const widget) const
{
    QList<QLabel *> trapezoidAreaLabels;

    QLabel *trapezoidAreaLongBaseLabel {new QLabel(widget)};
    trapezoidAreaLongBaseLabel->setText("Long Base");
    trapezoidAreaLongBaseLabel->move(50, 160);

    QLabel *trapezoidAreaShortBaseLabel {new QLabel(widget)};
    trapezoidAreaShortBaseLabel->setText("Short Base");
    trapezoidAreaShortBaseLabel->move(50, 260);

    QLabel *trapezoidAreaHeightLabel {new QLabel(widget)};
    trapezoidAreaHeightLabel->setText("Height");
    trapezoidAreaHeightLabel->move(200, 160);

    trapezoidAreaLabels.emplace_back(trapezoidAreaLongBaseLabel);
    trapezoidAreaLabels.emplace_back(trapezoidAreaShortBaseLabel);
    trapezoidAreaLabels.emplace_back(trapezoidAreaHeightLabel);

    return trapezoidAreaLabels;
}

QList<QLabel *> MathFunctionElements::createTrapezoidPerimeterMathFunctionLabels(QWidget *const widget) const
{
    QList<QLabel *> trapezoidPerimeterLabels;

    QLabel *trapezoidPerimeterLongBaseLabel {new QLabel(widget)};
    trapezoidPerimeterLongBaseLabel->setText("Long Base");
    trapezoidPerimeterLongBaseLabel->move(50, 160);

    QLabel *trapezoidPerimeterShortBaseLabel {new QLabel(widget)};
    trapezoidPerimeterShortBaseLabel->setText("Short Base");
    trapezoidPerimeterShortBaseLabel->move(50, 260);

    QLabel *trapezoidPerimeterSideALabel {new QLabel(widget)};
    trapezoidPerimeterSideALabel->setText("Side A");
    trapezoidPerimeterSideALabel->move(200, 160);

    QLabel *trapezoidPerimeterSideBLabel {new QLabel(widget)};
    trapezoidPerimeterSideBLabel->setText("Side B");
    trapezoidPerimeterSideBLabel->move(200, 260);

    trapezoidPerimeterLabels.emplace_back(trapezoidPerimeterLongBaseLabel);
    trapezoidPerimeterLabels.emplace_back(trapezoidPerimeterShortBaseLabel);
    trapezoidPerimeterLabels.emplace_back(trapezoidPerimeterSideALabel);
    trapezoidPerimeterLabels.emplace_back(trapezoidPerimeterSideBLabel);

    return trapezoidPerimeterLabels;
}

QList<QLabel *> MathFunctionElements::createCuboidSurfaceAreaVolumeMathFunctionLabels(QWidget *const widget) const
{
    QList<QLabel *> cuboidLabels;

    QLabel *cuboidHeightLabel {new QLabel(widget)};
    cuboidHeightLabel->setText("Height");
    cuboidHeightLabel->move(50, 160);

    QLabel *cuboidLengthLabel {new QLabel(widget)};
    cuboidLengthLabel->setText("Length");
    cuboidLengthLabel->move(50, 260);

    QLabel *cuboidDepthLabel {new QLabel(widget)};
    cuboidDepthLabel->setText("Depth");
    cuboidDepthLabel->move(200, 160);

    cuboidLabels.emplace_back(cuboidHeightLabel);
    cuboidLabels.emplace_back(cuboidLengthLabel);
    cuboidLabels.emplace_back(cuboidDepthLabel);

    return cuboidLabels;
}
