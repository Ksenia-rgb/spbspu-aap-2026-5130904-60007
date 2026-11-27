#include <Ellipse.hpp>
#include <diamond.hpp>
#include <rectangle.hpp>
#include <scaling-demo.hpp>

namespace semenov
{
  void printFigures(Shape* const* figures, std::size_t size)
  {
    double total_area = 0;
    Bounds bounds = getBounds(figures[0]->getFrameRect());
    for (std::size_t i = 0; i < size; ++i)
    {
      printFigure(*figures[i], total_area, bounds);
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
  semenov::Shape* const figures[] = {&rectangle, &diamond, &ellipse};

  std::cout << "Before scaling:\n";
  semenov::printFigures(figures, sizeof(figures) / sizeof(*figures));

  semenov::point_t origin{};
  double factor = 0;
  if (!semenov::readScale(origin, factor))
  {
    std::cerr << "Expected two finite coordinates and a positive finite scale factor.\n";
    return 1;
  }

  for (semenov::Shape* figure : figures)
  {
    semenov::scaleFigure(*figure, origin, factor);
  }

  std::cout << "After scaling:\n";
  semenov::printFigures(figures, sizeof(figures) / sizeof(*figures));
  return 0;
}
