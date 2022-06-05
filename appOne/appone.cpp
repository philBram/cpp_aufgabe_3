#include "appone.h"
#include <QMenu>
#include <QMenuBar>
#include <QApplication>
#include <QStatusBar>
#include <QLabel>
#include <QFont>
#include <QMessageBox>

AppOne::AppOne(QWidget *parent)
    : QMainWindow{parent},
      QStringLogger{"MathCalc"},
      squareAreaCategoryName {"squaresArea"},
      squarePerimeterCategoryName {"squaresPerimeter"},
      rectangleAreaCategoryName {"rectanglesArea"},
      rectanglePerimeterCategoryName {"rectanglesPerimeter"},
      circleAreaCategoryName {"circleArea"},
      circlePerimeterCategoryName {"circlePerimeter"},
      trapezoidAreaCategoryName {"trapezoidArea"},
      trapezoidPerimeterCategoryName{"trapezoidPerimeter"},
      cuboidSurfaceAreaCategoryName {"cuboidSurfaceArea"},
      cuboidVolumeCategoryName {"cuboidVolume"}
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
    mathFunctionNames.emplace_back("area of circle");
    mathFunctionNames.emplace_back("perimeter of circle");
    mathFunctionNames.emplace_back("area of trapezoid");
    mathFunctionNames.emplace_back("perimeter of trapezoid");
    mathFunctionNames.emplace_back("surface area of cuboid");
    mathFunctionNames.emplace_back("volume of cuboid");

    mathFunctions->addItems(std::move(mathFunctionNames));
}

void AppOne::createMathFunctionsInputs()
{
    //Spinboxes
    mathFunctionsSpinBoxes.insert(squareAreaCategoryName, std::move(createSquareAreaPerimeterMathFunctionSpinBoxes(this)));
    mathFunctionsSpinBoxes.insert(squarePerimeterCategoryName, std::move(createSquareAreaPerimeterMathFunctionSpinBoxes(this)));
    mathFunctionsSpinBoxes.insert(rectangleAreaCategoryName, std::move(createRectangleAreaPerimeterMathFunctionSpinBoxes(this)));
    mathFunctionsSpinBoxes.insert(rectanglePerimeterCategoryName, std::move(createRectangleAreaPerimeterMathFunctionSpinBoxes(this)));
    mathFunctionsSpinBoxes.insert(circleAreaCategoryName, std::move(createCircleAreaPerimeterMathFunctionSpinBoxes(this)));
    mathFunctionsSpinBoxes.insert(circlePerimeterCategoryName, std::move(createCircleAreaPerimeterMathFunctionSpinBoxes(this)));
    mathFunctionsSpinBoxes.insert(trapezoidAreaCategoryName, std::move(createTrapezoidAreaMathFunctionSpinBoxes(this)));
    mathFunctionsSpinBoxes.insert(trapezoidPerimeterCategoryName, std::move(createTrapezoidPerimeterMathFunctionSpinBoxes(this)));
    mathFunctionsSpinBoxes.insert(cuboidSurfaceAreaCategoryName, std::move(createCuboidSurfaceAreaVolumeMathFunctionSpinBoxes(this)));
    mathFunctionsSpinBoxes.insert(cuboidVolumeCategoryName, std::move(createCuboidSurfaceAreaVolumeMathFunctionSpinBoxes(this)));

    //Labels
    mathFunctionsLabels.insert(squareAreaCategoryName, std::move(createSquareAreaPerimeterMathFunctionLabels(this)));
    mathFunctionsLabels.insert(squarePerimeterCategoryName, std::move(createSquareAreaPerimeterMathFunctionLabels(this)));
    mathFunctionsLabels.insert(rectangleAreaCategoryName, std::move(createRectangleAreaPerimeterMathFunctionLabels(this)));
    mathFunctionsLabels.insert(rectanglePerimeterCategoryName, std::move(createRectangleAreaPerimeterMathFunctionLabels(this)));
    mathFunctionsLabels.insert(circleAreaCategoryName, std::move(createCircleAreaPerimeterMathFunctionLabels(this)));
    mathFunctionsLabels.insert(circlePerimeterCategoryName, std::move(createCircleAreaPerimeterMathFunctionLabels(this)));
    mathFunctionsLabels.insert(trapezoidAreaCategoryName, std::move(createTrapezoidAreaMathFunctionLabels(this)));
    mathFunctionsLabels.insert(trapezoidPerimeterCategoryName, std::move(createTrapezoidPerimeterMathFunctionLabels(this)));
    mathFunctionsLabels.insert(cuboidSurfaceAreaCategoryName, std::move(createCuboidSurfaceAreaVolumeMathFunctionLabels(this)));
    mathFunctionsLabels.insert(cuboidVolumeCategoryName, std::move(createCuboidSurfaceAreaVolumeMathFunctionLabels(this)));
}

void AppOne::createMathFunctionsSignals() const
{
    connect(mathFunctions, &QComboBox::currentIndexChanged, this, &AppOne::comboBoxItemChanged);

    foreach (QList<QDoubleSpinBox *> const &inputs, mathFunctionsSpinBoxes.values()) {
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

    QMessageBox help;

    help.setWindowTitle("Help");
    help.setText("Choose a Mathfunction and use the input fields to calculate the result");
    help.setIcon(QMessageBox::Information);
    help.setStandardButtons(QMessageBox::Ok);

    help.exec();
}

void AppOne::aboutClicked() const
{
    QString msg {"about clicked"};

    statusBar()->showMessage(msg, 3000);
    logOut(std::move(msg));

    QMessageBox about;

    about.setWindowTitle("About");
    about.setText("This application can calculate basic mathfunctions");
    about.setIcon(QMessageBox::Question);
    about.setStandardButtons(QMessageBox::Ok);

    about.exec();
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
        mathFunctionClicked(circleAreaCategoryName);
        break;
    case 5:
        mathFunctionClicked(circlePerimeterCategoryName);
        break;
    case 6:
        mathFunctionClicked(trapezoidAreaCategoryName);
        break;
    case 7:
        mathFunctionClicked(trapezoidPerimeterCategoryName);
        break;
    case 8:
        mathFunctionClicked(cuboidSurfaceAreaCategoryName);
        break;
    case 9:
        mathFunctionClicked(cuboidVolumeCategoryName);
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
    double result {0};

    switch (mathFunctions->currentIndex()) {
    case 0:
        result = calculateSquareArea<QDoubleSpinBox *, double>(
                    mathFunctionsSpinBoxes.value(squareAreaCategoryName));
        break;
    case 1:
        result = calculateSquarePerimeter<QDoubleSpinBox *, double>(
                    mathFunctionsSpinBoxes.value(squarePerimeterCategoryName));
        break;
    case 2:
        result = calculateRectangleArea<QDoubleSpinBox *, double>(
                    mathFunctionsSpinBoxes.value(rectangleAreaCategoryName));
        break;
    case 3:
        result = calculateRectanglePerimeter<QDoubleSpinBox *, double>(
                    mathFunctionsSpinBoxes.value(rectanglePerimeterCategoryName));
        break;
    case 4:
        result = calculateCircleArea<QDoubleSpinBox *, double>(
                    mathFunctionsSpinBoxes.value(circleAreaCategoryName));
        break;
    case 5:
        result = calculateCirclePerimeter<QDoubleSpinBox *, double>(
                    mathFunctionsSpinBoxes.value(circlePerimeterCategoryName));
        break;
    case 6:
        result = calculateTrapezoidArea<QDoubleSpinBox *, double>(
                    mathFunctionsSpinBoxes.value(trapezoidAreaCategoryName));
        break;
    case 7:
        result = calculateTrapezoidPerimeter<QDoubleSpinBox *, double>(
                    mathFunctionsSpinBoxes.value(trapezoidPerimeterCategoryName));
        break;
    case 8:
        result = calculateCuboidSurfaceArea<QDoubleSpinBox *, double>(
                    mathFunctionsSpinBoxes.value(cuboidSurfaceAreaCategoryName));
        break;
    case 9:
        result = calculateCuboidVolume<QDoubleSpinBox *, double>(
                    mathFunctionsSpinBoxes.value(cuboidVolumeCategoryName));
        break;
    default:
        break;
    }

    mathFunctionResult->setText(QString::number(std::move(result)));
}

void AppOne::hideAllItems() const
{
    foreach (QList<QDoubleSpinBox *> const &inputs, mathFunctionsSpinBoxes.values()) {
        for (QDoubleSpinBox * const &input : inputs) {
            input->hide();
        }
    }

    foreach (QList<QLabel *> const &inputs, mathFunctionsLabels.values()) {
        for (QLabel * const &input : inputs) {
            input->hide();
        }
    }
}

void AppOne::showMathFunctionCategoryItems(const QString &mathFunctionCategory) const
{
    for (QDoubleSpinBox * const &input : mathFunctionsSpinBoxes.value(mathFunctionCategory)) {
        input->show();
    }

    for (QLabel * const &input : mathFunctionsLabels.value(mathFunctionCategory)) {
        input->show();
    }
}
