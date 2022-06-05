#ifndef CALCULATEMATHFUNCTIONS_H
#define CALCULATEMATHFUNCTIONS_H

#include <QList>
#include <QDoubleSpinBox>
#include "libIncludeHelper/libincludehelper.h"

class CalculateMathFunctions
{
protected:
    template <typename T, typename R>
    R calculateSquareArea(QList<T> const &mathfunctionCategoryList) const
    {
        R squareLength {mathfunctionCategoryList.at(0)->value()};

        R squareArea {libIncludeHelper::areaOfSquare(squareLength)};

        return squareArea;
    }

    template <typename T, typename R>
    R calculateSquarePerimeter(QList<T> const &mathfunctionCategoryList) const
    {
        R squareLength {mathfunctionCategoryList.at(0)->value()};

        R squarePermit {libIncludeHelper::perimeterOfSquare(squareLength)};

        return squarePermit;
    }

    template <typename T, typename R>
    R calculateRectangleArea(QList<T> const &mathfunctionCategoryList) const
    {
        R rectangleLength {mathfunctionCategoryList.at(0)->value()};
        R rectangleWidth {mathfunctionCategoryList.at(1)->value()};

        R rectangleArea {libIncludeHelper::areaOfRectangle(
                        std::move(rectangleLength),
                        std::move(rectangleWidth))};

        return rectangleArea;
    }

    template <typename T, typename R>
    R calculateRectanglePerimeter(QList<T> const &mathfunctionCategoryList) const
    {
        R rectangleLength {mathfunctionCategoryList.at(0)->value()};
        R rectangleWidth {mathfunctionCategoryList.at(1)->value()};

        R rectanglePerimeter {libIncludeHelper::perimeterOfRectangle(
                        std::move(rectangleLength),
                        std::move(rectangleWidth))};

        return rectanglePerimeter;
    }

    template <typename T, typename R>
    R calculateCircleArea(QList<T> const &mathfunctionCategoryList) const
    {
        R circleRadius {mathfunctionCategoryList.at(0)->value()};

        R circleArea {libIncludeHelper::areaOfCircle(circleRadius)};

        return circleArea;
    }

    template <typename T, typename R>
    R calculateCirclePerimeter(QList<T> const &mathfunctionCategoryList) const
    {
        R circleRadius {mathfunctionCategoryList.at(0)->value()};

        R circleArea {libIncludeHelper::perimeterOfCircle(circleRadius)};

        return circleArea;
    }

    template <typename T, typename R>
    R calculateTrapezoidArea(QList<T> const &mathfunctionCategoryList) const
    {
        R trapezoidAreaLongBase {mathfunctionCategoryList.at(0)->value()};
        R trapezoidAreaShortBase {mathfunctionCategoryList.at(1)->value()};
        R trapezoidAreaHeight {mathfunctionCategoryList.at(2)->value()};

        R trapezoidArea {libIncludeHelper::areaOfTrapezoid(
                        std::move(trapezoidAreaLongBase),
                        std::move(trapezoidAreaShortBase),
                        std::move(trapezoidAreaHeight))};

        return trapezoidArea;
    }

    template <typename T, typename R>
    R calculateTrapezoidPerimeter(QList<T> const &mathfunctionCategroyList) const
    {
        R trapezoidPerimeterLongBase {mathfunctionCategroyList.at(0)->value()};
        R trapezoidPerimeterShortBase {mathfunctionCategroyList.at(1)->value()};
        R trapezoidPerimeterSideA {mathfunctionCategroyList.at(2)->value()};
        R trapezoidPerimeterSideB {mathfunctionCategroyList.at(3)->value()};

        R trapezoidPerimeter {libIncludeHelper::perimeterOfTrapezoid(
                        std::move(trapezoidPerimeterLongBase),
                        std::move(trapezoidPerimeterShortBase),
                        std::move(trapezoidPerimeterSideA),
                        std::move(trapezoidPerimeterSideB))};

        return trapezoidPerimeter;
    }

    template <typename T, typename R>
    R calculateCuboidSurfaceArea(QList<T> const &mathfunctionCategoryList) const
    {
        R cuboidSurfaceAreaHeight {mathfunctionCategoryList.at(0)->value()};
        R cuboidSurfaceAreaLength {mathfunctionCategoryList.at(1)->value()};
        R cuboidSurfaceAreaDepth {mathfunctionCategoryList.at(2)->value()};

        R cuboidSurfaceArea {libIncludeHelper::surfaceAreaOfCuboid(
                        std::move(cuboidSurfaceAreaHeight),
                        std::move(cuboidSurfaceAreaLength),
                        std::move(cuboidSurfaceAreaDepth))};

        return cuboidSurfaceArea;
    }

    template <typename T, typename R>
    R calculateCuboidVolume(QList<T> const &mathfunctionCategoryList) const
    {
        R cuboidVolumeHeight {mathfunctionCategoryList.at(0)->value()};
        R cuboidVolumeLength {mathfunctionCategoryList.at(1)->value()};
        R cuboidVolumeDepth {mathfunctionCategoryList.at(2)->value()};

        R cuboidVolume {libIncludeHelper::volumeOfCuboid(
                        std::move(cuboidVolumeHeight),
                        std::move(cuboidVolumeLength),
                        std::move(cuboidVolumeDepth))};

        return cuboidVolume;
    }

public:
    CalculateMathFunctions();
};

#endif // CALCULATEMATHFUNCTIONS_H
