#include "rectangle.hpp"
#include "square.hpp"
#include "ring.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>

void printShape(const Shape& shape)
{
    const rectangle_t frame = shape.getFrameRect();

    std::cout << "Area: " << shape.getArea() << '\n';

    std::cout << "Frame rectangle:\n";
    std::cout << "  Width: " << frame.width << '\n';
    std::cout << "  Height: " << frame.height << '\n';
    std::cout << "  Center: ("
              << frame.pos.x << ", "
              << frame.pos.y << ")\n";
}

void printAll(Shape* shapes[], int count)
{
    double total_area = 0.0;

    for (int i = 0; i < count; ++i)
    {
        std::cout << "\nFigure " << i + 1 << ":\n";

        printShape(*shapes[i]);

        total_area += shapes[i]->getArea();
    }

    std::cout << "\nTotal area: " << total_area << '\n';

    const rectangle_t first_frame = shapes[0]->getFrameRect();

    double min_x = first_frame.pos.x - first_frame.width / 2.0;
    double max_x = first_frame.pos.x + first_frame.width / 2.0;
    double min_y = first_frame.pos.y - first_frame.height / 2.0;
    double max_y = first_frame.pos.y + first_frame.height / 2.0;

    for (int i = 1; i < count; ++i)
    {
        const rectangle_t frame = shapes[i]->getFrameRect();

        const double left = frame.pos.x - frame.width / 2.0;
        const double right = frame.pos.x + frame.width / 2.0;
        const double bottom = frame.pos.y - frame.height / 2.0;
        const double top = frame.pos.y + frame.height / 2.0;

        if (left < min_x)
        {
            min_x = left;
        }

        if (right > max_x)
        {
            max_x = right;
        }

        if (bottom < min_y)
        {
            min_y = bottom;
        }

        if (top > max_y)
        {
            max_y = top;
        }
    }

    std::cout << "\nOverall frame rectangle:\n";
    std::cout << "  Width: " << max_x - min_x << '\n';
    std::cout << "  Height: " << max_y - min_y << '\n';
    std::cout << "  Center: ("
              << (min_x + max_x) / 2.0 << ", "
              << (min_y + max_y) / 2.0 << ")\n";
}

void scaleAll(Shape* shapes[], int count,
              point_t fixed_point, double factor)
{
    for (int i = 0; i < count; ++i)
    {
        const rectangle_t frame = shapes[i]->getFrameRect();

        const double dx = (factor - 1.0) *
                          (frame.pos.x - fixed_point.x);

        const double dy = (factor - 1.0) *
                          (frame.pos.y - fixed_point.y);

        shapes[i]->move(dx, dy);
        shapes[i]->scale(factor);
    }
}

int main()
{
    try
    {
        std::cout << std::fixed << std::setprecision(2);

        Rectangle rectangle1(4.0, 2.0, {1.0, 2.0});
        Rectangle rectangle2(6.0, 3.0, {-3.0, 1.0});

        Square square1(3.0, {4.0, 2.0});
        Square square2(5.0, {-2.0, -3.0});

        Ring ring1(5.0, 2.0, {3.0, -2.0});
        Ring ring2(4.0, 1.5, {-5.0, 3.0});

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

        std::cout << "===== BEFORE SCALING =====\n";

        printAll(shapes, count);

        point_t fixed_point;

        std::cout << "\nEnter the fixed point (x y): ";

        if (!(std::cin >> fixed_point.x >> fixed_point.y) ||
            !std::isfinite(fixed_point.x) ||
            !std::isfinite(fixed_point.y))
        {
            throw std::invalid_argument("Invalid point coordinates");
        }

        double factor;

        std::cout << "Enter the scaling factor: ";

        if (!(std::cin >> factor) ||
            !std::isfinite(factor) ||
            factor <= 0.0)
        {
            throw std::invalid_argument("Invalid scaling factor");
        }

        scaleAll(shapes, count, fixed_point, factor);

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
