#ifndef LIBINCLUDEHELPER_H
#define LIBINCLUDEHELPER_H

#include "formulasLib/mathFormulas.h"
#include <QString>

class libIncludeHelper
{
public:
    libIncludeHelper();

    static double areaOfSquare(double const);
    static double perimeterOfSquare(double const);

    static double areaOfRectangle(double const, double const);
    static double perimeterOfRectangle(double const, double const);

    static double areaOfCircle(double const);
    static double perimeterOfCircle(double const);

    static double areaOfTrapezoid(double const, double const, double const);
    static double perimeterOfTrapezoid(double const, double const, double const, double const);

    static double surfaceAreaOfCuboid(double const, double const, double const);
    static double volumeOfCuboid(double const, double const, double const);
};

#endif // LIBINCLUDEHELPER_H
