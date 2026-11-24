#include "rectangle.hpp"
#include "diamond.hpp"
#include "ellipse.hpp"

#include <algorithm>
#include <iostream>

namespace kugushev
{
  void scaleShapes(Shape* shapes[], int count, point_t pivot, double factor);
}

int main()
{
  constexpr kugushev::point_t rect_center{2.0, 3.0};
  constexpr double rect_width = 4.0;
  constexpr double rect_height = 2.0;
  constexpr kugushev::point_t diamond_center{3.0, 4.0};
  constexpr double diamond_xdiag = 2.0;
  constexpr double diamond_ydiag = 3.0;
  constexpr kugushev::point_t ellipse_center{4.0, 5.0};
  constexpr double ellipse_radius_x = 2.0;
  constexpr double ellipse_radius_y = 3.0;
  constexpr double half = 0.5;

  kugushev::Rectangle rect{rect_center, rect_width, rect_height};
  kugushev::Diamond diam{diamond_center, diamond_xdiag, diamond_ydiag};
  kugushev::Ellipse ellip{ellipse_center, ellipse_radius_x, ellipse_radius_y};

  constexpr int count = 3;
  kugushev::Shape* shapes[count]{&rect, &diam, &ellip};
  for (const kugushev::Shape* const shape : shapes)
  {
    if (shape == nullptr)
    {
      std::cerr << "Ошибка: пустой указатель на фигуру.\n";
      return 1;
    }
  }
  const char* const names[count]{"Rectangle", "Diamond", "Ellipse"};

  kugushev::point_t pivot{};
  double factor = 0.0;

  std::cout << "Введите x, y и коэффициент масштабирования:\n";
  if (!(std::cin >> pivot.x >> pivot.y >> factor) || factor <= 0.0)
  {
    std::cerr << "Ошибка: введите две координаты и положительный коэффициент.\n";
    return 1;
  }

  for (int step = 0; step < 2; ++step)
  {
    if (step == 0)
    {
      std::cout << "До масштабирования\n";
    }
    else
    {
      kugushev::scaleShapes(shapes, count, pivot, factor);
      std::cout << "\nПосле масштабирования\n";
    }

    double total_area = 0.0;
    const kugushev::rectangle_t first = shapes[0]->getFrameRect();
    double left = first.pos.x - first.width * half;
    double right = first.pos.x + first.width * half;
    double bottom = first.pos.y - first.height * half;
    double top = first.pos.y + first.height * half;

    for (int i = 0; i < count; ++i)
    {
      const double area = shapes[i]->getArea();
      const kugushev::rectangle_t frame = shapes[i]->getFrameRect();
      total_area += area;

      std::cout << names[i] << '\n'
                << "Площадь: " << area << '\n'
                << "Центр рамки: (" << frame.pos.x << ", " << frame.pos.y << ")\n"
                << "Ширина: " << frame.width << '\n'
                << "Высота: " << frame.height << '\n';

      left = std::min(left, frame.pos.x - frame.width * half);
      right = std::max(right, frame.pos.x + frame.width * half);
      bottom = std::min(bottom, frame.pos.y - frame.height * half);
      top = std::max(top, frame.pos.y + frame.height * half);
    }

    std::cout << "Суммарная площадь: " << total_area << '\n'
              << "Общая рамка\n"
              << "Центр: (" << (left + right) * half << ", " << (bottom + top) * half << ")\n"
              << "Ширина: " << right - left << '\n'
              << "Высота: " << top - bottom << '\n';
  }

  return 0;
}

void kugushev::scaleShapes(Shape* shapes[], int count, point_t pivot, double factor)
{
  for (int i = 0; i < count; ++i)
  {
    const point_t center = shapes[i]->getFrameRect().pos;
    const point_t newCenter{pivot.x + (center.x - pivot.x) * factor, pivot.y + (center.y - pivot.y) * factor};

    shapes[i]->scale(factor);
    shapes[i]->move(newCenter);
  }
}
