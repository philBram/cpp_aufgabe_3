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
