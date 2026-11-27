#include "composite-shape.hpp"

#include "../common/Ellipse.hpp"
#include "../common/diamond.hpp"
#include "../common/rectangle.hpp"
#include "../common/scaling-demo.hpp"

namespace semenov
{
  void printFigures(const CompositeShape& figures)
  {
    double sum = 0;
    Bounds bounds = getBounds(figures.first().getFrameRect());
    for (std::size_t i = 0; i < figures.size(); ++i)
    {
      printFigure(figures.get(i), sum, bounds);
    }
    printTotal(sum, bounds);
  }
}

int main()
{
  constexpr double RECTANGLE_HEIGHT = 5;
  constexpr double DIAMOND_WIDTH = 6;
  const semenov::Rectangle rectangle({0, 0}, 4, RECTANGLE_HEIGHT);
  const semenov::Diamond diamond({1, 1}, DIAMOND_WIDTH, 4);
  const semenov::Ellipse ellipse({2, 3}, 4, 2);
  semenov::CompositeShape figures;
  figures.append(rectangle);
  figures.append(diamond);
  figures.append(ellipse);

  std::cout << "Before scaling:\n";
  semenov::printFigures(figures);

  semenov::point_t origin{};
  double factor = 0;
  std::cin >> origin.x >> origin.y >> factor;
  if (!std::cin || !semenov::validScale(origin, factor))
  {
    std::cerr << "Expected two finite coordinates and a positive finite scale factor.\n";
    return 1;
  }

  for (std::size_t i = 0; i < figures.size(); ++i)
  {
    semenov::scaleFigure(figures.get(i), origin, factor);
  }

  std::cout << "After scaling:\n";
  semenov::printFigures(figures);
  return 0;
}
