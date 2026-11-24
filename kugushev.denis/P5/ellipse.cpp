#include "ellipse.hpp"

#include <stdexcept>

namespace kugushev
{
  Ellipse::Ellipse(point_t centr, double radius_x, double radius_y):
    centr_{centr},
    radius_x_{radius_x},
    radius_y_{radius_y}
  {
    if (radius_x <= 0.0 || radius_y <= 0.0)
    {
      throw std::invalid_argument("Ellipse radii must be positive");
    }
  }

  double Ellipse::getArea() const
  {
    constexpr double pi = 3.141592653589793;
    return pi * radius_x_ * radius_y_;
  }

  rectangle_t Ellipse::getFrameRect() const
  {
    constexpr double diameter_factor = 2.0;
    return {diameter_factor * radius_x_, diameter_factor * radius_y_, centr_};
  }

  void Ellipse::move(point_t point)
  {
    centr_ = point;
  }

  void Ellipse::move(double dx, double dy)
  {
    centr_.x += dx;
    centr_.y += dy;
  }

  void Ellipse::scale(double factor)
  {
    radius_x_ *= factor;
    radius_y_ *= factor;
  }
}
