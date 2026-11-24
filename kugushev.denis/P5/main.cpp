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
  kugushev::Rectangle rect{{2.0, 3.0}, 4.0, 2.0};
  kugushev::Diamond diam{{3.0, 4.0}, 2.0, 3.0};
  kugushev::Ellipse ellip{{4.0, 5.0}, 2.0, 3.0};

  constexpr int count = 3;
  kugushev::Shape* shapes[count]{&rect, &diam, &ellip};
  for (const kugushev::Shape* shape : shapes)
  {
    if (shape == nullptr)
    {
      std::cerr << "Ошибка: пустой указатель на фигуру.\n";
      return 1;
    }
  }
  const char* names[count]{"Rectangle", "Diamond", "Ellipse"};

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

    double totalArea = 0.0;
    const kugushev::rectangle_t first = shapes[0]->getFrameRect();
    double left = first.pos.x - first.width / 2.0;
    double right = first.pos.x + first.width / 2.0;
    double bottom = first.pos.y - first.height / 2.0;
    double top = first.pos.y + first.height / 2.0;

    for (int i = 0; i < count; ++i)
    {
      const double area = shapes[i]->getArea();
      const kugushev::rectangle_t frame = shapes[i]->getFrameRect();
      totalArea += area;

      std::cout << names[i] << '\n'
                << "Площадь: " << area << '\n'
                << "Центр рамки: (" << frame.pos.x << ", " << frame.pos.y << ")\n"
                << "Ширина: " << frame.width << '\n'
                << "Высота: " << frame.height << '\n';

      left = std::min(left, frame.pos.x - frame.width / 2.0);
      right = std::max(right, frame.pos.x + frame.width / 2.0);
      bottom = std::min(bottom, frame.pos.y - frame.height / 2.0);
      top = std::max(top, frame.pos.y + frame.height / 2.0);
    }

    std::cout << "Суммарная площадь: " << totalArea << '\n'
              << "Общая рамка\n"
              << "Центр: (" << (left + right) / 2.0 << ", " << (bottom + top) / 2.0 << ")\n"
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
