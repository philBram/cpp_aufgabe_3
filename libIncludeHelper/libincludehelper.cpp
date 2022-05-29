#include "libincludehelper.h"
#include <QDebug>

using namespace formulas;

libIncludeHelper::libIncludeHelper()
{
}

double libIncludeHelper::areaOfSquare(const double length)
{
    return MathFormulas::areaOfSquare(length);
}

double libIncludeHelper::perimeterOfSquare(const double length)
{
    return MathFormulas::perimeterOfSquare(length);
}

double libIncludeHelper::areaOfRectangle(const double length, const double width)
{
    return MathFormulas::areaOfRectangle(length, width);
}

double libIncludeHelper::perimeterOfRectangle(const double length, const double width)
{
    return MathFormulas::perimeterOfRectangle(length, width);
}

double libIncludeHelper::areaOfTrapezoid(const double longBase, const double shortBase, const double height)
{
    return MathFormulas::areaOfTrapezoid(longBase, shortBase, height);
}

double libIncludeHelper::perimeterOfTrapezoid(const double longBase, const double shortBase, const double sideA, const double sideB)
{
    return MathFormulas::perimeterOfTrapezoid(longBase, shortBase, sideA, sideB);
}
