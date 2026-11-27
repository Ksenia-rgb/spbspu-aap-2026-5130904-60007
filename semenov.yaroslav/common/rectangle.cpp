#include "rectangle.hpp"

#include <stdexcept>

namespace semenov
{
  Rectangle::Rectangle(point_t center, double width, double height):
    frame_{width, height, center}
  {
    if (!(width > 0.0 && height > 0.0))
    {
      throw std::invalid_argument("Rectangle dimensions must be positive.");
    }
  }

  Shape* Rectangle::clone() const
  {
    return new Rectangle(*this);
  }

  double Rectangle::getArea() const
  {
    return frame_.width * frame_.height;
  }

  rectangle_t Rectangle::getFrameRect() const
  {
    return frame_;
  }

  void Rectangle::move(point_t pos)
  {
    frame_.pos = pos;
  }

  void Rectangle::move(double dx, double dy)
  {
    frame_.pos.x += dx;
    frame_.pos.y += dy;
  }

  void Rectangle::scale(double k)
  {
    if (!(k > 0.0))
    {
      throw std::invalid_argument("Scale factor must be positive.");
    }
    frame_.width *= k;
    frame_.height *= k;
  }
}
