
#include "rectangle.hpp"
#include "square.hpp"
#include "ring.hpp"

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>

// Affichage des informations d'une figure
void printShape(const Shape& shape)
{
    rectangle_t frame = shape.getFrameRect();

    std::cout << "Area: " << shape.getArea() << '\n';

    std::cout << "Frame rectangle:\n";
    std::cout << "  Width: " << frame.width << '\n';
    std::cout << "  Height: " << frame.height << '\n';
    std::cout << "  Center: ("
              << frame.pos.x << ", "
              << frame.pos.y << ")\n";
}

// Affichage de toutes les figures
void printAll(Shape* shapes[], int count)
{
    double totalArea = 0.0;

    for (int i = 0; i < count; ++i)
    {
        std::cout << "\nFigure " << i + 1 << ":\n";

        printShape(*shapes[i]);

        totalArea += shapes[i]->getArea();
    }

    std::cout << "\nTotal area: " << totalArea << '\n';

    // Calcul du rectangle englobant de toutes les figures
    rectangle_t firstFrame = shapes[0]->getFrameRect();

    double minX = firstFrame.pos.x - firstFrame.width / 2.0;
    double maxX = firstFrame.pos.x + firstFrame.width / 2.0;
    double minY = firstFrame.pos.y - firstFrame.height / 2.0;
    double maxY = firstFrame.pos.y + firstFrame.height / 2.0;

    for (int i = 1; i < count; ++i)
    {
        rectangle_t frame = shapes[i]->getFrameRect();

        double left = frame.pos.x - frame.width / 2.0;
        double right = frame.pos.x + frame.width / 2.0;
        double bottom = frame.pos.y - frame.height / 2.0;
        double top = frame.pos.y + frame.height / 2.0;

        if (left < minX) minX = left;
        if (right > maxX) maxX = right;
        if (bottom < minY) minY = bottom;
        if (top > maxY) maxY = top;
    }

    std::cout << "\nOverall frame rectangle:\n";
    std::cout << "  Width: " << maxX - minX << '\n';
    std::cout << "  Height: " << maxY - minY << '\n';
    std::cout << "  Center: ("
              << (minX + maxX) / 2.0 << ", "
              << (minY + maxY) / 2.0 << ")\n";
}

// Mise a l'echelle de toutes les figures autour d'un point
void scaleAll(Shape* shapes[], int count,
              point_t fixedPoint, double factor)
{
    for (int i = 0; i < count; ++i)
    {
        rectangle_t frame = shapes[i]->getFrameRect();

        double dx = (factor - 1.0) *
                    (frame.pos.x - fixedPoint.x);

        double dy = (factor - 1.0) *
                    (frame.pos.y - fixedPoint.y);

        shapes[i]->move(dx, dy);
        shapes[i]->scale(factor);
    }
}

int main()
{
    try
    {
        std::cout << std::fixed << std::setprecision(2);

        // Creation des figures
        Rectangle rectangle1(4.0, 2.0, {1.0, 2.0});
        Rectangle rectangle2(6.0, 3.0, {-3.0, 1.0});

        Square square1(3.0, {4.0, 2.0});
        Square square2(5.0, {-2.0, -3.0});

        Ring ring1(5.0, 2.0, {3.0, -2.0});
        Ring ring2(4.0, 1.5, {-5.0, 3.0});

        // Tableau de pointeurs vers Shape
        Shape* shapes[] =
        {
            &rectangle1,
            &rectangle2,
            &square1,
            &square2,
            &ring1,
            &ring2
        };

        const int count = sizeof(shapes) / sizeof(shapes[0]);

        // Affichage avant transformation
        std::cout << "===== BEFORE SCALING =====\n";

        printAll(shapes, count);

        // Saisie du point de reference
        point_t fixedPoint;

        std::cout << "\nEnter the fixed point (x y): ";

        if (!(std::cin >> fixedPoint.x >> fixedPoint.y) ||
            !std::isfinite(fixedPoint.x) ||
            !std::isfinite(fixedPoint.y))
        {
            throw std::invalid_argument("Invalid point coordinates");
        }

        // Saisie du coefficient
        double factor;

        std::cout << "Enter the scaling factor: ";

        if (!(std::cin >> factor) ||
            !std::isfinite(factor) ||
            factor <= 0.0)
        {
            throw std::invalid_argument("Invalid scaling factor");
        }

        // Transformation des figures
        scaleAll(shapes, count, fixedPoint, factor);

        // Affichage apres transformation
        std::cout << "\n===== AFTER SCALING =====\n";

        printAll(shapes, count);

    }
    catch (const std::exception& error)
    {
        std::cerr << "Error: " << error.what() << '\n';
        return 1;
    }

    return 0;
}
