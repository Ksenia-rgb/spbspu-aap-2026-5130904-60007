#include "ellipse.hpp"

#include <stdexcept>

namespace kugushev
{
  Ellipse::Ellipse(point_t centr, double radiusX, double radiusY):
    centr_{centr},
    radiusX_{radiusX},
    radiusY_{radiusY}
  {
    if (radiusX <= 0.0 || radiusY <= 0.0)
    {
      throw std::invalid_argument("Ellipse radii must be positive");
    }
  }

  double Ellipse::getArea() const
  {
    constexpr double pi = 3.141592653589793;
    return pi * radiusX_ * radiusY_;
  }

  rectangle_t Ellipse::getFrameRect() const
  {
    return {2.0 * radiusX_, 2.0 * radiusY_, centr_};
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
    radiusX_ *= factor;
    radiusY_ *= factor;
  }
}
