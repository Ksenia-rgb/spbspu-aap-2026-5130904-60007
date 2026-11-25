#include "elipse.hpp"
#include <stdexcept>

namespace shibaev
{
  Elipse::Elipse(double width, double height, point_t pos):
    width(width),
    height(height),
    pos(pos)
  {
    if (width <= 0 || height <= 0)
    {
      throw std::invalid_argument("Elipse width and height must be positive");
    }
  }

  double Elipse::getArea() const
  {
    constexpr double pi = 3.14159265358979323846;
    return pi * width * height;
  }

  rectangle_t Elipse::getFrameRect() const
  {
    rectangle_t frame = {2 * width, 2 * height, pos};
    return frame;
  }

  void Elipse::move(double x, double y)
  {
    pos.x += x;
    pos.y += y;
  }

  void Elipse::move(point_t p)
  {
    pos.x = p.x;
    pos.y = p.y;
  }

  void Elipse::scale(double s)
  {
    if (s <= 0)
    {
      throw std::invalid_argument("Scale factor must be positive");
    }
    width *= s;
    height *= s;
  }
}
