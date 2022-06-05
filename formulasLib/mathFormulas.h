#ifndef APPONE_H
#define APPONE_H

namespace formulas {
    class MathFormulas
    {
    public:
        explicit MathFormulas() = delete;

        //https://www.andlearning.org/math-formula/

        //Formulas of Square
        static double areaOfSquare(double const);
        static double perimeterOfSquare(double const);

        //Formulas of Rectangle
        static double areaOfRectangle(double const, double const);
        static double perimeterOfRectangle(double const, double const);

        //Formulas of Circle
        static double areaOfCircle(double const);
        static double perimeterOfCircle(double const);

        //Formulas of Scalene Triangle
        static double areaOfScaleneTriangle(double const, double const, double const);
        static double perimeterOfScaleneTriangle(double const, double const, double const);

        //Formulas of Isoscele Triangle
        static double areaOfIsosceleTriangle(double const, double const);
        static double altitudeOfIsoceleTriangle(double const, double const);
        static double perimeterOfIsosceleTriangle(double const, double const);

        //Formulas of Right Triangle
        static double areaOfRightTriangle(double const, double const);
        static double perimeterOfRightTriangle(double const, double const, double const);
        static double semiPerimeterRightTriangle(double const, double const, double const);

        //Formulas of Equilateral Triangle
        static double areaOfEquilateralTriangle(double const);
        static double perimeterOfEquilateralTriangle(double const);
        static double semiPerimeterOfEquilateralTriangle(double const);
        static double heightOfEquilateralTriangle(double const);

        //Formulas of Rhombus
        static double areaOfRhombus(double const, double const);
        static double perimeterOfRhombus(double const);

        //Formulas of Parallelogram
        static double areaOfParallelogram(double const, double const);
        static double perimeterOfParallelogram(double const, double const);

        //Formulas of Trapezoid
        static double areaOfTrapezoid(double const, double const, double const);
        static double perimeterOfTrapezoid(double const, double const, double const, double const);

        //Formulas of Cube
        static double surfaceAreaOfCube(double const);
        static double volumeOfCube(double const);

        //Formulas of Cuboid
        static double surfaceAreaOfCuboid(double const, double const, double const);
        static double volumeOfCuboid(double const, double const, double const);

        //Formulas of sphere
        static double surfaceAreaOfSphere(double const);
        static double volumeOfSphere(double const);
        static double diameterOfSphere(double const);
        static double circumferenceOfSphere(double const);

        //Formulas of Hemisphere
        static double curvedSurfaceAreaOfHemisphere(double const);
        static double totalSurfaceAreaOfHemisphere(double const);
        static double volumeOfHemisphere(double const);

        //Formulas of Cylinder
        static double curvedSurfaceAreaOfCylinder(double const, double const);
        static double totalSurfaceAreaOfCylinder(double const, double const);
        static double volumeOfCylinder(double const, double const);

        //Formulas of cone
        static double curevedSurfaceAreaOfCone(double const, double const);
        static double totalSurfaceAreaOfCone(double const, double const);
        static double volumeOfCone(double const, double const);
    };
}

#endif // APPONE_H
