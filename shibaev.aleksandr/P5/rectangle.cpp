#include "rectangle.hpp"
#include <stdexcept>

namespace shibaev
{
  Rectangle::Rectangle(double width, double height, point_t pos):
    width_(width),
    height_(height),
    pos_(pos)
  {
    if (width <= 0 || height <= 0)
    {
      throw std::invalid_argument("Rectangle width and height must be positive");
    }
  }

  double Rectangle::getArea() const
  {
    return width_ * height_;
  }

  rectangle_t Rectangle::getFrameRect() const
  {
    const rectangle_t frame = {width_, height_, pos_};
    return frame;
  }

  void Rectangle::move(double x, double y)
  {
    pos_.x += x;
    pos_.y += y;
  }

  void Rectangle::move(point_t p)
  {
    pos_.x = p.x;
    pos_.y = p.y;
  }

  void Rectangle::scale(double s)
  {
    if (s <= 0)
    {
      throw std::invalid_argument("Scale factor must be positive");
    }
    width_ *= s;
    height_ *= s;
  }
}
