#include "appone.h"
#include "formulasLib/mathFormulas.h"
#include <QMenu>
#include <QMenuBar>
#include <QApplication>
#include <QStatusBar>
#include <QLabel>
#include <QFont>

AppOne::AppOne(QWidget *parent)
    : QMainWindow{parent},
      QStringLogger{"AppOne"}
{
    logOut("app opened");

    QString helpMenuName {"Help"};

    QString helpName {"Help"};
    QString aboutName {"About AppHarbor"};
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
    dynamic_cast<QLabel *>(appHeader)->setPalette(std::move(headerPalette));
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
    mathFunctionNames.emplace_back("permit of square");
    mathFunctionNames.emplace_back("area of rectangle");
    mathFunctionNames.emplace_back("permit of rectangle");

    mathFunctions->addItems(mathFunctionNames);
}

void AppOne::createMathFunctionsInputs()
{
    QString squareCategoryName {"squares"};
    QString rectangleCategoryName {"rectangles"};

    mathFunctionsSpinBoxes = std::make_shared<QMap<QString, QList<QDoubleSpinBox *>>>();

    mathFunctionsSpinBoxes->insert(squareCategoryName, std::move(createSquareMathFunctionsSpinBoxes()));
    mathFunctionsSpinBoxes->insert(rectangleCategoryName, std::move(createRectangleMathFunctionsSpinBoxes()));

    mathFunctionsLabels = std::make_shared<QMap<QString, QList<QLabel *>>>();

    mathFunctionsLabels->insert(squareCategoryName, std::move(createSquareMathFunctionsLabels()));
    mathFunctionsLabels->insert(rectangleCategoryName, std::move(createRectangleMathFunctionsLabels()));
}

QList<QDoubleSpinBox *> AppOne::createSquareMathFunctionsSpinBoxes()
{
    QList<QDoubleSpinBox *> squareInputs;

    QDoubleSpinBox *squareLengthInput {new QDoubleSpinBox(this)};
    squareLengthInput->move(50, 200);

    squareInputs.emplace_back(squareLengthInput);

    return squareInputs;
}

QList<QDoubleSpinBox *> AppOne::createRectangleMathFunctionsSpinBoxes()
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

QList<QLabel *> AppOne::createSquareMathFunctionsLabels()
{
    QList<QLabel *> squareLabels;

    QLabel *squareLengthLabel {new QLabel(this)};
    squareLengthLabel->setText("Length");
    squareLengthLabel->move(50, 160);

    return squareLabels;
}

QList<QLabel *> AppOne::createRectangleMathFunctionsLabels()
{
    QList<QLabel *> rectangleLabels;

    QLabel *rectangleLengthLabel {new QLabel(this)};
    rectangleLengthLabel->setText("Length");
    rectangleLengthLabel->move(50, 160);

    QLabel *rectangleWidthLabel {new QLabel(this)};
    rectangleWidthLabel->setText("Width");
    rectangleWidthLabel->move(50, 260);

    return rectangleLabels;
}

void AppOne::createMathFunctionsSignals() const
{
    connect(mathFunctions, &QComboBox::currentIndexChanged, this, &AppOne::comboBoxItemChanged);

    for (QList<QDoubleSpinBox *> const &inputs : mathFunctionsSpinBoxes->values().toList()) {
        for (QDoubleSpinBox * const &input : inputs) {
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
        areaOfSquareClicked();
        break;
    case 1:
        permitOfSquareClicked();
        break;
    case 2:
        areaOfRectangleClicked();
        break;
    case 3:
        permitOfRectangleClicked();
        break;
    default:
        break;
    }
}

void AppOne::mathFunctionResultCalc() const
{
    switch (mathFunctions->currentIndex()) {
    case 0:
        mathFunctionResult->setText("");
        break;
    default:
        break;
    }
}

void AppOne::areaOfSquareClicked() const
{
    QString msg {"areaOfSquares clicked"};

    statusBar()->showMessage(msg, 3000);
    logOut(std::move(msg));

    hideAllItems();
    showAllSquareItems();
}

void AppOne::permitOfSquareClicked() const
{
    QString msg {"permitOfSquares clicked"};

    statusBar()->showMessage(msg, 3000);
    logOut(std::move(msg));

    hideAllItems();
    showAllSquareItems();
}

void AppOne::areaOfRectangleClicked() const
{
    QString msg {"areaOfRectangles clicked"};

    statusBar()->showMessage(msg, 3000);
    logOut(std::move(msg));

    hideAllItems();
    showAllRectangleItems();
}

void AppOne::permitOfRectangleClicked() const
{
    QString msg {"permitOfRectangles clicked"};

    statusBar()->showMessage(msg, 3000);
    logOut(std::move(msg));

    hideAllItems();
    showAllRectangleItems();
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

void AppOne::showAllSquareItems() const
{
    for (QDoubleSpinBox * const &input : mathFunctionsSpinBoxes->value("squares")) {
        input->show();
    }

    for (QLabel * const &input : mathFunctionsLabels->value("squares")) {
        input->show();
    }
}

void AppOne::showAllRectangleItems() const
{
    for (QDoubleSpinBox * const &input : mathFunctionsSpinBoxes->value("rectangles")) {
        input->show();
    }

    for (QLabel * const &input : mathFunctionsLabels->value("rectangles")) {
        input->show();
    }
}
