#include "shape.hpp"
#include "Ellipse.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "base-types.hpp"

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iostream>

namespace semenov
{
  void printFrame(const rectangle_t& frame)
  {
    std::cout << frame.width << ' ' << frame.height << ' ' << frame.pos.x << ' ' << frame.pos.y << '\n';
  }

  template< std::size_t N >
  void printFigures(Shape* const (&figures)[N])
  {
    const auto first = figures[0]->getFrameRect();
    double left = first.pos.x - first.width / 2;
    double right = first.pos.x + first.width / 2;
    double bottom = first.pos.y - first.height / 2;
    double top = first.pos.y + first.height / 2;
    double total_area = 0;

    for (const Shape* const figure : figures)
    {
      const double area = figure->getArea();
      const auto frame = figure->getFrameRect();
      std::cout << area << '\n';
      printFrame(frame);
      total_area += area;

      left = std::min(left, frame.pos.x - frame.width / 2);
      right = std::max(right, frame.pos.x + frame.width / 2);
      bottom = std::min(bottom, frame.pos.y - frame.height / 2);
      top = std::max(top, frame.pos.y + frame.height / 2);
    }

    std::cout << "Total Area: " << total_area << '\n';
    std::cout << "Total Frame: ";
    printFrame({right - left, top - bottom, {left / 2 + right / 2, bottom / 2 + top / 2}});
  }

  template< std::size_t N >
  void scaleFigures(Shape* const (&figures)[N], point_t origin, double factor)
  {
    for (Shape* const figure : figures)
    {
      const auto center = figure->getFrameRect().pos;
      figure->move({origin.x + (center.x - origin.x) * factor, origin.y + (center.y - origin.y) * factor});
      figure->scale(factor);
    }
  }
}

int main()
{
  constexpr double RECTANGLE_HEIGHT = 5;
  constexpr double DIAMOND_WIDTH = 6;
  semenov::Rectangle rectangle({0, 0}, 4, RECTANGLE_HEIGHT);
  semenov::Diamond diamond({1, 1}, DIAMOND_WIDTH, 4);
  semenov::Ellipse ellipse({2, 3}, 4, 2);
  semenov::Shape* const figures[] = {&rectangle, &diamond, &ellipse};

  std::cout << "Before scaling:\n";
  semenov::printFigures(figures);

  semenov::point_t origin{};
  double factor = 0;
  if (!(std::cin >> origin.x >> origin.y >> factor) || !std::isfinite(origin.x) || !std::isfinite(origin.y)
      || !std::isfinite(factor) || factor <= 0)
  {
    std::cerr << "Expected two finite coordinates and a positive finite scale factor.\n";
    return 1;
  }

  semenov::scaleFigures(figures, origin, factor);
  std::cout << "After scaling:\n";
  semenov::printFigures(figures);
}
