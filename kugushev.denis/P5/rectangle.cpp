#include "rectangle.hpp"

namespace kugushev
{
  Rectangle::Rectangle(point_t centr, double width, double height):
    width_{width},
    height_{height},
    centr_{centr}
  {}

  double Rectangle::getArea() const
  {
    return width_ * height_;
  }

  rectangle_t Rectangle::getFrameRect() const
  {
    return {width_, height_, centr_};
  }

  void Rectangle::move(point_t point)
  {
    centr_ = point;
  }

  void Rectangle::move(double dx, double dy)
  {
    centr_.x += dx;
    centr_.y += dy;
  }

  void Rectangle::scale(double factor)
  {
    width_ *= factor;
    height_ *= factor;
  }
}
