#include "composite-shape.hpp"

#include <Ellipse.hpp>
#include <diamond.hpp>
#include <rectangle.hpp>
#include <scaling-demo.hpp>

namespace semenov {
  void printFigures(const CompositeShape& figures)
  {
    double total_area = 0;
    Bounds bounds = getBounds(figures.first().getFrameRect());
    for (std::size_t i = 0; i < figures.size(); ++i) {
      printFigure(figures.get(i), total_area, bounds);
    }
    printTotal(total_area, bounds);
  }
}

int main()
{
  constexpr double RECTANGLE_HEIGHT = 5;
  constexpr double DIAMOND_WIDTH = 6;
  semenov::Rectangle rectangle({0, 0}, 4, RECTANGLE_HEIGHT);
  semenov::Diamond diamond({1, 1}, DIAMOND_WIDTH, 4);
  semenov::Ellipse ellipse({2, 3}, 4, 2);
  semenov::CompositeShape figures;
  figures.append(rectangle);
  figures.append(diamond);
  figures.append(ellipse);

  std::cout << "Before scaling:\n";
  semenov::printFigures(figures);

  semenov::point_t origin{};
  double factor = 0;
  if (!semenov::readScale(origin, factor)) {
    std::cerr << "Expected two finite coordinates and a positive finite scale factor.\n";
    return 1;
  }

  for (std::size_t i = 0; i < figures.size(); ++i) {
    semenov::scaleFigure(figures.get(i), origin, factor);
  }

  std::cout << "After scaling:\n";
  semenov::printFigures(figures);
  return 0;
}
