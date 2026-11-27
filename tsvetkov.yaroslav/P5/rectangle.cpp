#include "rectangle.hpp"

namespace tsvetkov
{
  Rectangle::Rectangle(point_t center, double width, double height):
    center_{center},
    width_{width},
    height_{height}
  {}

  double Rectangle::getArea() const
  {
    return height_ * width_;
  }

  rectangle_t Rectangle::getFrameRect() const
  {
    return {width_, height_, center_};
  }

  void Rectangle::move(point_t point)
  {
    center_ = point;
  }

  void Rectangle::move(double dx, double dy)
  {
    center_.x += dx;
    center_.y += dy;
  }

  void Rectangle::scale(double factor)
  {
    width_ *= factor;
    height_ *= factor;
  }
}
