#include "mathFormulas.h"
#include <cmath>

namespace formulas {

    //Formulas of Square
    double MathFormulas::areaOfSquare(const double length)
    {
        return std::pow(length, 2.0);
    }

    double MathFormulas::perimeterOfSquare(const double length)
    {
        return 4.0 * length;
    }

    //Formulas of Rectangle
    double MathFormulas::areaOfRectangle(const double length, const double width)
    {
        return length * width;
    }

    double MathFormulas::perimeterOfRectangle(const double length, const double width)
    {
        return 2.0 * (length + width);
    }

    //Formulas of Circle
    double MathFormulas::areaOfCircle(const double radius)
    {
        return M_PI * std::pow(radius, 2.0);
    }

    double MathFormulas::perimeterOfCircle(const double radius)
    {
        return 2.0 * M_PI * radius;
    }

    //Formulas of Scalene Triangle
    double MathFormulas::areaOfScaleneTriangle(const double sideA, const double sideB, const double sideC)
    {
        double s {(sideA + sideB + sideC) / 2.0};
        return std::sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    }

    double MathFormulas::perimeterOfScaleneTriangle(const double sideA, const double sideB, const double sideC)
    {
        return sideA + sideB + sideC;
    }

    //Formulas of Isoscele Triangle
    double MathFormulas::areaOfIsosceleTriangle(const double base, const double height)
    {
        return (1.0 / 2.0) * base * height;
    }

    double MathFormulas::altitudeOfIsoceleTriangle(const double base, const double lengthOfTwoEqualSides)
    {
        return std::sqrt(std::pow(lengthOfTwoEqualSides, 2.0) - (std::pow(base, 2.0) / 4.0));
    }

    double MathFormulas::perimeterOfIsosceleTriangle(const double base, const double lengthOfTwoEqualSides)
    {
        return (2.0 * lengthOfTwoEqualSides) + base;
    }

    //Formulas of Right Triangle
    double MathFormulas::areaOfRightTriangle(const double base, const double hypotenuse)
    {
        return (1.0 / 2.0) * base * hypotenuse;
    }

    double MathFormulas::perimeterOfRightTriangle(const double height, const double base, const double sideC)
    {
        return height + base + sideC;
    }

    double MathFormulas::semiPerimeterRightTriangle(const double height, const double base, const double sideC)
    {
        return (height + base + sideC) / 2.0;
    }

    //Formulas of Equilateral Triangle
    double MathFormulas::areaOfEquilateralTriangle(const double side)
    {
        return (std::pow(side, 2.0) * std::sqrt(3.0)) / 4.0;
    }

    double MathFormulas::perimeterOfEquilateralTriangle(const double side)
    {
        return 3.0 * side;
    }

    double MathFormulas::semiPerimeterOfEquilateralTriangle(const double side)
    {
        return (3.0 * side) / 2.0;
    }

    double MathFormulas::heightOfEquilateralTriangle(const double side)
    {
        return (std::sqrt(3.0) * side) * 2.0;
    }

    //Formulas of Rhombus
    double MathFormulas::areaOfRhombus(const double diagonalOne, const double diagonalTwo)
    {
        return (1.0 / 2.0) * diagonalOne * diagonalTwo;
    }

    double MathFormulas::perimeterOfRhombus(const double side)
    {
        return 4.0 * side;
    }

    //Formulas of Parallelogram
    double MathFormulas::areaOfParallelogram(const double base, const double height)
    {
        return base * height;
    }

    double MathFormulas::perimeterOfParallelogram(const double base, const double height)
    {
        return 2.0 * (base + height);
    }

    //Formulas of Trapezoid
    double MathFormulas::areaOfTrapezoid(const double longBase, const double shortBase, const double height)
    {
        return (1.0 / 2.0) * height * (shortBase + longBase);
    }

    double MathFormulas::perimeterOfTrapezoid(const double longBase, const double shortBase, const double sideA, const double sideB)
    {
        return longBase + shortBase + sideA + sideB;
    }

    //Formulas of Cube
    double MathFormulas::surfaceAreaOfCube(const double sideLength)
    {
        return 6.0 * std::pow(sideLength, 2.0);
    }

    double MathFormulas::volumeOfCube(const double sideLength)
    {
        return std::pow(sideLength, 3.0);
    }

    //Formulas of Cuboid
    double MathFormulas::surfaceAreaOfCuboid(const double height, const double length, const double depth)
    {
        return 2.0 * ((length * depth) + (depth * height) * (length * height));
    }

    double MathFormulas::volumeOfCuboid(const double height, const double length, const double depth)
    {
        return height * length * depth;
    }

    //Formulas of sphere
    double MathFormulas::surfaceAreaOfSphere(const double radius)
    {
        return 4.0 * M_PI * std::pow(radius, 2.0);
    }

    double MathFormulas::volumeOfSphere(const double radius)
    {
        return (4.0 / 3.0) * M_PI * std::pow(radius, 3.0);
    }

    double MathFormulas::diameterOfSphere(const double radius)
    {
        return 2.0 * radius;
    }

    double MathFormulas::circumferenceOfSphere(const double radius)
    {
        return 2.0 * M_PI * radius;
    }

    //Formulas of Hemisphere
    double MathFormulas::curvedSurfaceAreaOfHimsphere(const double radius)
    {
        return 4.0 * M_PI * std::pow(radius, 2.0);
    }

    double MathFormulas::totalSurfaceAreaOfHemisphere(const double radius)
    {
        return 3.0 * M_PI * std::pow(radius, 2.0);
    }

    static double volumeOfHemisphere(double const radius)
    {
        return (2.0 / 3.0) * M_PI * std::pow(radius, 3.0);
    }

    //Formulas of Cylinder
    double MathFormulas::curvedSurfaceAreaOfCylinder(const double radius, const double height)
    {
        return 2.0 * M_PI * radius * height;
    }

    double MathFormulas::totalSurfaceAreaOfCylinder(const double radius, const double height)
    {
        return 2 * M_PI * radius * (radius + height);
    }

    double MathFormulas::volumeOfCylinder(const double radius, const double height)
    {
        return M_PI * std::pow(radius, 2.0) * height;
    }

    //Formulas of cone
    double MathFormulas::curevedSurfaceAreaOfCone(const double radius, const double slantHeight)
    {
        return M_PI * radius * slantHeight;
    }

    double MathFormulas::totalSurfaceAreaOfCone(const double radius, const double slantHeight)
    {
        return M_PI * radius * (slantHeight + radius);
    }

    double MathFormulas::volumeOfCone(const double radius, const double height)
    {
        return (1.0 / 3.0) * M_PI * std::pow(radius, 2.0) * height;
    }

}
