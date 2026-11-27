#include <algorithm>
#include <cstddef>
#include <iostream>
#include <stdexcept>

#include "base-types.hpp"
#include "diamond.hpp"
#include "ellipse.hpp"
#include "rectangle.hpp"
#include "shape.hpp"

namespace geom
{
  void scaleShapes(Shape * const * shapes, std::size_t count, const point_t & center, double factor);
  double getTotalArea(const Shape * const * shapes, std::size_t count);
  rectangle_t getTotalFrameRect(const Shape * const * shapes, std::size_t count);
  void printShapesInfo(std::ostream & out, const Shape * const * shapes, std::size_t count);
  void freeShapes(Shape * const * shapes, std::size_t count);
}

void geom::scaleShapes(Shape * const * shapes, std::size_t count, const point_t & center, double factor)
{
  if (factor <= 0.0)
  {
    throw std::invalid_argument("Invalid scale factor");
  }
  for (std::size_t i = 0; i < count; ++i)
  {
    const point_t pos_before = shapes[i]->getFrameRect().pos;
    shapes[i]->move(center);
    const point_t pos_at_center = shapes[i]->getFrameRect().pos;
    shapes[i]->scale(factor);
    const double dx = (pos_before.x - pos_at_center.x) * factor;
    const double dy = (pos_before.y - pos_at_center.y) * factor;
    shapes[i]->move(dx, dy);
  }
}

double geom::getTotalArea(const Shape * const * shapes, std::size_t count)
{
  double total_area = 0.0;
  for (std::size_t i = 0; i < count; ++i)
  {
    total_area += shapes[i]->getArea();
  }
  return total_area;
}

geom::rectangle_t geom::getTotalFrameRect(const Shape * const * shapes, std::size_t count)
{
  if (count == 0)
  {
    return {0.0, 0.0, {0.0, 0.0}};
  }

  constexpr double half_divisor = 2.0;
  const rectangle_t first_rect = shapes[0]->getFrameRect();
  double min_x = first_rect.pos.x - (first_rect.width / half_divisor);
  double max_x = first_rect.pos.x + (first_rect.width / half_divisor);
  double min_y = first_rect.pos.y - (first_rect.height / half_divisor);
  double max_y = first_rect.pos.y + (first_rect.height / half_divisor);

  for (std::size_t i = 1; i < count; ++i)
  {
    const rectangle_t rect = shapes[i]->getFrameRect();
    const double left = rect.pos.x - (rect.width / half_divisor);
    const double right = rect.pos.x + (rect.width / half_divisor);
    const double bottom = rect.pos.y - (rect.height / half_divisor);
    const double top = rect.pos.y + (rect.height / half_divisor);

    min_x = std::min(min_x, left);
    max_x = std::max(max_x, right);
    min_y = std::min(min_y, bottom);
    max_y = std::max(max_y, top);
  }

  const double width = max_x - min_x;
  const double height = max_y - min_y;
  const point_t pos = {(min_x + max_x) / half_divisor, (min_y + max_y) / half_divisor};
  return {width, height, pos};
}

void geom::printShapesInfo(std::ostream & out, const Shape * const * shapes, std::size_t count)
{
  for (std::size_t i = 0; i < count; ++i)
  {
    const rectangle_t rect = shapes[i]->getFrameRect();
    out << "Shape " << (i + 1) << " area: " << shapes[i]->getArea() << "\n";
    out << "Shape " << (i + 1) << " frame: " << rect.width << " " << rect.height << " ";
    out << rect.pos.x << " " << rect.pos.y << "\n";
  }

  const rectangle_t total_rect = getTotalFrameRect(shapes, count);
  out << "Total area: " << getTotalArea(shapes, count) << "\n";
  out << "Total frame: " << total_rect.width << " " << total_rect.height << " ";
  out << total_rect.pos.x << " " << total_rect.pos.y << "\n";
}

void geom::freeShapes(Shape * const * shapes, std::size_t count)
{
  for (std::size_t i = 0; i < count; ++i)
  {
    delete shapes[i];
  }
}

int main()
{
  constexpr std::size_t shapes_count = 3;
  geom::Shape * shapes[shapes_count] = {nullptr, nullptr, nullptr};

  try
  {
    constexpr double rect_x = 1.0;
    constexpr double rect_y = 2.0;
    constexpr double rect_width = 4.0;
    constexpr double rect_height = 6.0;

    constexpr double diamond_x = -2.0;
    constexpr double diamond_y = 4.0;
    constexpr double diamond_diag_x = 6.0;
    constexpr double diamond_diag_y = 4.0;

    constexpr double ellipse_x = 0.0;
    constexpr double ellipse_y = -3.0;
    constexpr double ellipse_radius_x = 5.0;
    constexpr double ellipse_radius_y = 2.0;

    shapes[0] = new geom::Rectangle({rect_x, rect_y}, rect_width, rect_height);
    shapes[1] = new geom::Diamond({diamond_x, diamond_y}, diamond_diag_x, diamond_diag_y);
    shapes[2] = new geom::Ellipse({ellipse_x, ellipse_y}, ellipse_radius_x, ellipse_radius_y);

    double scale_x = 0.0;
    double scale_y = 0.0;
    double factor = 0.0;
    if (!(std::cin >> scale_x >> scale_y >> factor))
    {
      std::cerr << "Error: invalid input\n";
      geom::freeShapes(shapes, shapes_count);
      return 1;
    }

    if (factor <= 0.0)
    {
      std::cerr << "Error: scale factor must be positive\n";
      geom::freeShapes(shapes, shapes_count);
      return 1;
    }

    std::cout << "Before scaling:\n";
    geom::printShapesInfo(std::cout, shapes, shapes_count);

    const geom::point_t scale_center = {scale_x, scale_y};
    geom::scaleShapes(shapes, shapes_count, scale_center, factor);

    std::cout << "After scaling:\n";
    geom::printShapesInfo(std::cout, shapes, shapes_count);
  }
  catch (const std::exception & err)
  {
    std::cerr << err.what() << "\n";
    geom::freeShapes(shapes, shapes_count);
    return 2;
  }

  geom::freeShapes(shapes, shapes_count);
  return 0;
}
