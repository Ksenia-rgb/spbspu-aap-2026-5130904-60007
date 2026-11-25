#include "rectangle.hpp"
#include <stdexcept>

namespace shibaev
{
  Rectangle::Rectangle(double width, double height, point_t pos):
    width(width),
    height(height),
    pos(pos)
  {
    if (width <= 0 || height <= 0)
    {
      throw std::invalid_argument("Rectangle width and height must be positive");
    }
  }

  double Rectangle::getArea() const
  {
    return width * height;
  }

  rectangle_t Rectangle::getFrameRect() const
  {
    rectangle_t frame = {width, height, pos};
    return frame;
  }

  void Rectangle::move(double x, double y)
  {
    pos.x += x;
    pos.y += y;
  }

  void Rectangle::move(point_t p)
  {
    pos.x = p.x;
    pos.y = p.y;
  }

  void Rectangle::scale(double s)
  {
    if (s <= 0)
    {
      throw std::invalid_argument("Scale factor must be positive");
    }
    width *= s;
    height *= s;
  }
}
