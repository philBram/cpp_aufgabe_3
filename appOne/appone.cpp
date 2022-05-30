#include "appone.h"
#include "formulasLib/mathFormulas.h"
#include <QMenu>
#include <QMenuBar>
#include <QApplication>
#include <QStatusBar>
#include <QLabel>
#include <QFont>
#include "libIncludeHelper/libincludehelper.h"

AppOne::AppOne(QWidget *parent)
    : QMainWindow{parent},
      QStringLogger{"AppOne"},
      squareAreaCategoryName {"squaresArea"},
      squarePerimeterCategoryName {"squaresPerimeter"},
      rectangleAreaCategoryName {"rectanglesArea"},
      rectanglePerimeterCategoryName {"rectanglesPerimeter"},
      trapezoidAreaCategoryName {"trapezoidArea"},
      trapezoidPerimeterCategoryName {"trapezoidPerimeter"}
{
    logOut("app opened");

    QString helpMenuName {"Help"};

    QString helpName {"Help"};
    QString aboutName {"About MathCalc"};
    QString quitName {"Quit"};

    helpAction = new QAction(this);
    aboutAction = new QAction(this);
    quitAction = new QAction(this);

    helpAction->setText(std::move(helpName));
    aboutAction->setText(std::move(aboutName));
    quitAction->setText(std::move(quitName));

    QWidget *helpMenu {this->menuBar()->addMenu(std::move(helpMenuName))};

    helpMenu->addAction(helpAction);
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(quitAction);

    QPalette headerPalette;

    headerPalette.setColor(QPalette::WindowText, Qt::red);

    QWidget *appHeader {new QLabel(this)};

    dynamic_cast<QLabel *>(appHeader)->setText("Math Functions");
    dynamic_cast<QLabel *>(appHeader)->setGeometry(0, 0, 150, 20);
    dynamic_cast<QLabel *>(appHeader)->setPalette(headerPalette);
    dynamic_cast<QLabel *>(appHeader)->move(50, 70);

    QFont resultFont;

    resultFont.bold();
    resultFont.setPointSize(20);

    QWidget *resultHeader {new QLabel(this)};

    dynamic_cast<QLabel *>(resultHeader)->setText("Result:");
    dynamic_cast<QLabel *>(resultHeader)->setGeometry(0, 0, 250, 50);
    dynamic_cast<QLabel *>(resultHeader)->setPalette(std::move(headerPalette));
    dynamic_cast<QLabel *>(resultHeader)->setFont(std::move(resultFont));
    dynamic_cast<QLabel *>(resultHeader)->move(50, 400);

    mathFunctionResult = new QLabel(this);

    mathFunctionResult->setGeometry(0, 0, 250, 50);
    mathFunctionResult->setFont(std::move(resultFont));
    mathFunctionResult->move(150, 400);

    mathFunctions = new QComboBox(this);
    mathFunctions->move(50, 100);

    createMathFunctionsNames();
    createMathFunctionsInputs();

    createMathFunctionsSignals();

    comboBoxItemChanged(std::move(mathFunctions->currentIndex()));

    createMenuActions();
}

AppOne::~AppOne()
{
    logOut("app closed");
}

void AppOne::createMathFunctionsNames() const
{
    QList<QString> mathFunctionNames;

    mathFunctionNames.emplace_back("area of square");
    mathFunctionNames.emplace_back("perimeter of square");
    mathFunctionNames.emplace_back("area of rectangle");
    mathFunctionNames.emplace_back("perimeter of rectangle");
    mathFunctionNames.emplace_back("area of trapezoid");
    mathFunctionNames.emplace_back("perimeter of trapezoid");

    mathFunctions->addItems(std::move(mathFunctionNames));
}

void AppOne::createMathFunctionsInputs()
{
    mathFunctionsSpinBoxes = std::make_shared<QMap<QString, QList<QDoubleSpinBox *>>>();

    mathFunctionsSpinBoxes->insert(squareAreaCategoryName, std::move(createSquareAreaPerimeterMathFunctionsSpinBoxes()));
    mathFunctionsSpinBoxes->insert(squarePerimeterCategoryName, std::move(createSquareAreaPerimeterMathFunctionsSpinBoxes()));
    mathFunctionsSpinBoxes->insert(rectangleAreaCategoryName, std::move(createRectangleAreaPerimeterMathFunctionsSpinBoxes()));
    mathFunctionsSpinBoxes->insert(rectanglePerimeterCategoryName, std::move(createRectangleAreaPerimeterMathFunctionsSpinBoxes()));
    mathFunctionsSpinBoxes->insert(trapezoidAreaCategoryName, std::move(createTrapezoidAreaMathFunctionsSpinBoxes()));
    mathFunctionsSpinBoxes->insert(trapezoidPerimeterCategoryName, std::move(createTrapezoidPerimeterMathFunctionsSpinBoxes()));

    mathFunctionsLabels = std::make_shared<QMap<QString, QList<QLabel *>>>();

    mathFunctionsLabels->insert(squareAreaCategoryName, std::move(createSquareAreaPerimeterMathFunctionsLabels()));
    mathFunctionsLabels->insert(squarePerimeterCategoryName, std::move(createSquareAreaPerimeterMathFunctionsLabels()));
    mathFunctionsLabels->insert(rectangleAreaCategoryName, std::move(createRectangleAreaPerimeterMathFunctionsLabels()));
    mathFunctionsLabels->insert(rectanglePerimeterCategoryName, std::move(createRectangleAreaPerimeterMathFunctionsLabels()));
    mathFunctionsLabels->insert(trapezoidAreaCategoryName, std::move(createTrapezoidAreaMathFunctionsLabels()));
    mathFunctionsLabels->insert(trapezoidPerimeterCategoryName, std::move(createTrapezoidPerimeterMathFunctionsLabels()));
}

QList<QDoubleSpinBox *> AppOne::createSquareAreaPerimeterMathFunctionsSpinBoxes()
{
    QList<QDoubleSpinBox *> squareInputs;

    QDoubleSpinBox *squareLengthInput {new QDoubleSpinBox(this)};
    squareLengthInput->move(50, 200);

    squareInputs.emplace_back(squareLengthInput);

    return squareInputs;
}

QList<QDoubleSpinBox *> AppOne::createRectangleAreaPerimeterMathFunctionsSpinBoxes()
{
    QList<QDoubleSpinBox *> rectangleInputs;

    QDoubleSpinBox *rectangleLengthInput {new QDoubleSpinBox(this)};
    rectangleLengthInput->move(50, 200);

    QDoubleSpinBox *rectangleWidthInput {new QDoubleSpinBox(this)};
    rectangleWidthInput->move(50, 300);

    rectangleInputs.emplace_back(rectangleLengthInput);
    rectangleInputs.emplace_back(rectangleWidthInput);

    return rectangleInputs;
}

QList<QDoubleSpinBox *> AppOne::createTrapezoidAreaMathFunctionsSpinBoxes()
{
    QList<QDoubleSpinBox *> trapezoidAreaInputs;

    QDoubleSpinBox *trapezoidAreaLongBaseInput {new QDoubleSpinBox(this)};
    trapezoidAreaLongBaseInput->move(50, 200);

    QDoubleSpinBox *trapeZoidAreaShortBaseInput {new QDoubleSpinBox(this)};
    trapeZoidAreaShortBaseInput->move(50, 300);

    QDoubleSpinBox *trapeZoidAreaHeightInput {new QDoubleSpinBox(this)};
    trapeZoidAreaHeightInput->move(200, 200);

    trapezoidAreaInputs.emplace_back(trapezoidAreaLongBaseInput);
    trapezoidAreaInputs.emplace_back(trapeZoidAreaShortBaseInput);
    trapezoidAreaInputs.emplace_back(trapeZoidAreaHeightInput);

    return trapezoidAreaInputs;
}

QList<QDoubleSpinBox *> AppOne::createTrapezoidPerimeterMathFunctionsSpinBoxes()
{
    QList<QDoubleSpinBox *> trapezoidPerimeterInputs;

    QDoubleSpinBox *trapezoidPerimeterLongBaseInput {new QDoubleSpinBox(this)};
    trapezoidPerimeterLongBaseInput->move(50, 200);

    QDoubleSpinBox *trapezoidPerimeterShortBaseInput {new QDoubleSpinBox(this)};
    trapezoidPerimeterShortBaseInput->move(50, 300);

    QDoubleSpinBox *trapezoidPerimeterSideAInput {new QDoubleSpinBox(this)};
    trapezoidPerimeterSideAInput->move(200, 200);

    QDoubleSpinBox *trapezoidPerimeterSideBInput {new QDoubleSpinBox(this)};
    trapezoidPerimeterSideBInput->move(200, 300);

    trapezoidPerimeterInputs.emplace_back(trapezoidPerimeterLongBaseInput);
    trapezoidPerimeterInputs.emplace_back(trapezoidPerimeterShortBaseInput);
    trapezoidPerimeterInputs.emplace_back(trapezoidPerimeterSideAInput);
    trapezoidPerimeterInputs.emplace_back(trapezoidPerimeterSideBInput);

    return trapezoidPerimeterInputs;
}

QList<QLabel *> AppOne::createSquareAreaPerimeterMathFunctionsLabels()
{
    QList<QLabel *> squareLabels;

    QLabel *squareLengthLabel {new QLabel(this)};
    squareLengthLabel->setText("Length");
    squareLengthLabel->move(50, 160);

    squareLabels.emplace_back(squareLengthLabel);

    return squareLabels;
}

QList<QLabel *> AppOne::createRectangleAreaPerimeterMathFunctionsLabels()
{
    QList<QLabel *> rectangleLabels;

    QLabel *rectangleLengthLabel {new QLabel(this)};
    rectangleLengthLabel->setText("Length");
    rectangleLengthLabel->move(50, 160);

    QLabel *rectangleWidthLabel {new QLabel(this)};
    rectangleWidthLabel->setText("Width");
    rectangleWidthLabel->move(50, 260);

    rectangleLabels.emplace_back(rectangleLengthLabel);
    rectangleLabels.emplace_back(rectangleWidthLabel);

    return rectangleLabels;
}

QList<QLabel *> AppOne::createTrapezoidAreaMathFunctionsLabels()
{
    QList<QLabel *> trapezoidAreaLabels;

    QLabel *trapezoidAreaLongBaseLabel {new QLabel(this)};
    trapezoidAreaLongBaseLabel->setText("Long Base");
    trapezoidAreaLongBaseLabel->move(50, 160);

    QLabel *trapezoidAreaShortBaseLabel {new QLabel(this)};
    trapezoidAreaShortBaseLabel->setText("Short Base");
    trapezoidAreaShortBaseLabel->move(50, 260);

    QLabel *trapezoidAreaHeightLabel {new QLabel(this)};
    trapezoidAreaHeightLabel->setText("Height");
    trapezoidAreaHeightLabel->move(200, 160);

    trapezoidAreaLabels.emplace_back(trapezoidAreaLongBaseLabel);
    trapezoidAreaLabels.emplace_back(trapezoidAreaShortBaseLabel);
    trapezoidAreaLabels.emplace_back(trapezoidAreaHeightLabel);

    return trapezoidAreaLabels;
}

QList<QLabel *> AppOne::createTrapezoidPerimeterMathFunctionsLabels()
{
    QList<QLabel *> trapezoidPerimeterLabels;

    QLabel *trapezoidPerimeterLongBaseLabel {new QLabel(this)};
    trapezoidPerimeterLongBaseLabel->setText("Long Base");
    trapezoidPerimeterLongBaseLabel->move(50, 160);

    QLabel *trapezoidPerimeterShortBaseLabel {new QLabel(this)};
    trapezoidPerimeterShortBaseLabel->setText("Short Base");
    trapezoidPerimeterShortBaseLabel->move(50, 260);

    QLabel *trapezoidPerimeterSideALabel {new QLabel(this)};
    trapezoidPerimeterSideALabel->setText("Side A");
    trapezoidPerimeterSideALabel->move(200, 160);

    QLabel *trapezoidPerimeterSideBLabel {new QLabel(this)};
    trapezoidPerimeterSideBLabel->setText("Side B");
    trapezoidPerimeterSideBLabel->move(200, 260);

    trapezoidPerimeterLabels.emplace_back(trapezoidPerimeterLongBaseLabel);
    trapezoidPerimeterLabels.emplace_back(trapezoidPerimeterShortBaseLabel);
    trapezoidPerimeterLabels.emplace_back(trapezoidPerimeterSideALabel);
    trapezoidPerimeterLabels.emplace_back(trapezoidPerimeterSideBLabel);

    return trapezoidPerimeterLabels;
}

void AppOne::createMathFunctionsSignals() const
{
    connect(mathFunctions, &QComboBox::currentIndexChanged, this, &AppOne::comboBoxItemChanged);

    for (QList<QDoubleSpinBox *> const &inputs : mathFunctionsSpinBoxes->values().toList()) {
        for (QDoubleSpinBox const * const &input : inputs) {
            connect(input, &QDoubleSpinBox::valueChanged, this, &AppOne::mathFunctionResultCalc);
        }
    }
}

void AppOne::createMenuActions() const
{
    connect(helpAction, &QAction::triggered, this, &AppOne::helpClicked);
    connect(aboutAction, &QAction::triggered, this, &AppOne::aboutClicked);
    connect(quitAction, &QAction::triggered, this, &AppOne::quitClicked);
}

void AppOne::helpClicked() const
{
    QString msg {"help clicked"};

    statusBar()->showMessage(msg, 3000);
    logOut(std::move(msg));
}

void AppOne::aboutClicked() const
{
    QString msg {"about clicked"};

    statusBar()->showMessage(msg, 3000);
    logOut(std::move(msg));
}

void AppOne::quitClicked() {
    QString msg {"quit clicked"};

    statusBar()->showMessage(msg, 3000);
    logOut(std::move(msg));

    this->close();
}

void AppOne::comboBoxItemChanged(int const index) const
{
    switch (index) {
    case 0:
        mathFunctionClicked(squareAreaCategoryName);
        break;
    case 1:
        mathFunctionClicked(squarePerimeterCategoryName);
        break;
    case 2:
        mathFunctionClicked(rectangleAreaCategoryName);
        break;
    case 3:
        mathFunctionClicked(rectanglePerimeterCategoryName);
        break;
    case 4:
        mathFunctionClicked(trapezoidAreaCategoryName);
        break;
    case 5:
        mathFunctionClicked(trapezoidPerimeterCategoryName);
        break;
    default:
        break;
    }

    mathFunctionResultCalc();
}

void AppOne::mathFunctionClicked(QString const &mathFunctionCategory) const
{
    QString msg {mathFunctionCategory + " clicked"};

    statusBar()->showMessage(msg, 3000);
    logOut(std::move(msg));

    hideAllItems();
    showMathFunctionCategoryItems(mathFunctionCategory);
}

void AppOne::mathFunctionResultCalc() const
{
    switch (mathFunctions->currentIndex()) {
    case 0:
        calculateSquareArea();
        break;
    case 1:
        calculateSquarePerimeter();
        break;
    case 2:
        calculateRectangleArea();
        break;
    case 3:
        calculateRectanglePerimeter();
        break;
   case 4:
        calculateTrapezoidArea();
        break;
    case 5:
        calculateTrapezoidPerimeter();
        break;
    default:
        break;
    }
}

void AppOne::calculateSquareArea() const
{
    double squareLength {mathFunctionsSpinBoxes->value(squareAreaCategoryName).at(0)->value()};

    double squareArea {libIncludeHelper::areaOfSquare(squareLength)};

    mathFunctionResult->setText(QString::number(std::move(squareArea)));
}

void AppOne::calculateSquarePerimeter() const
{
    double squareLength {mathFunctionsSpinBoxes->value(squarePerimeterCategoryName).at(0)->value()};

    double squarePermit {libIncludeHelper::perimeterOfSquare(squareLength)};

    mathFunctionResult->setText(QString::number(std::move(squarePermit)));

}

void AppOne::calculateRectangleArea() const
{
    double rectangleLength {mathFunctionsSpinBoxes->value(rectangleAreaCategoryName).at(0)->value()};
    double rectangleWidth {mathFunctionsSpinBoxes->value(rectangleAreaCategoryName).at(1)->value()};

    double rectangleArea {libIncludeHelper::areaOfRectangle(std::move(rectangleLength), std::move(rectangleWidth))};

    mathFunctionResult->setText(QString::number(std::move(rectangleArea)));
}

void AppOne::calculateRectanglePerimeter() const
{
    double rectangleLength {mathFunctionsSpinBoxes->value(rectanglePerimeterCategoryName).at(0)->value()};
    double rectangleWidth {mathFunctionsSpinBoxes->value(rectanglePerimeterCategoryName).at(1)->value()};

    double rectanglePerimeter {libIncludeHelper::perimeterOfRectangle(std::move(rectangleLength), std::move(rectangleWidth))};

    mathFunctionResult->setText(QString::number(std::move(rectanglePerimeter)));
}

void AppOne::calculateTrapezoidArea() const
{
    double trapezoidAreaLongBase {mathFunctionsSpinBoxes->value(trapezoidAreaCategoryName).at(0)->value()};
    double trapezoidAreaShortBase {mathFunctionsSpinBoxes->value(trapezoidAreaCategoryName).at(1)->value()};
    double trapezoidAreaHeight {mathFunctionsSpinBoxes->value(trapezoidAreaCategoryName).at(2)->value()};

    double trapezoidArea {libIncludeHelper::areaOfTrapezoid(std::move(trapezoidAreaLongBase),
                                                                 std::move(trapezoidAreaShortBase),
                                                                 std::move(trapezoidAreaHeight))};

    mathFunctionResult->setText(QString::number(std::move(trapezoidArea)));
}

void AppOne::calculateTrapezoidPerimeter() const
{
    double trapezoidPerimeterLongBase {mathFunctionsSpinBoxes->value(trapezoidPerimeterCategoryName).at(0)->value()};
    double trapezoidPerimeterShortBase {mathFunctionsSpinBoxes->value(trapezoidPerimeterCategoryName).at(1)->value()};
    double trapezoidPerimeterSideA {mathFunctionsSpinBoxes->value(trapezoidPerimeterCategoryName).at(2)->value()};
    double trapezoidPerimeterSideB {mathFunctionsSpinBoxes->value(trapezoidPerimeterCategoryName).at(3)->value()};

    double trapezoidPerimeter {libIncludeHelper::perimeterOfTrapezoid(std::move(trapezoidPerimeterLongBase),
                                                                      std::move(trapezoidPerimeterShortBase),
                                                                      std::move(trapezoidPerimeterSideA),
                                                                      std::move(trapezoidPerimeterSideB))};

    mathFunctionResult->setText(QString::number(std::move(trapezoidPerimeter)));
}

void AppOne::hideAllItems() const
{
    for (QList<QDoubleSpinBox *> const &inputs : mathFunctionsSpinBoxes->values().toList()) {
        for (QDoubleSpinBox * const &input : inputs) {
            input->hide();
        }
    }

    for (QList<QLabel *> const &inputs : mathFunctionsLabels->values().toList()) {
        for (QLabel * const &input : inputs) {
            input->hide();
        }
    }
}

void AppOne::showMathFunctionCategoryItems(const QString &mathFunctionCategory) const
{
    for (QDoubleSpinBox * const &input : mathFunctionsSpinBoxes->value(mathFunctionCategory)) {
        input->show();
    }

    for (QLabel * const &input : mathFunctionsLabels->value(mathFunctionCategory)) {
        input->show();
    }
}
