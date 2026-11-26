#include "Ellipse.hpp"
#include <stdexcept>

namespace semenov
{
  Ellipse::Ellipse(point_t center, double a, double b):
    center_(center),
    a_(a),
    b_(b)
  {
    if (a <= 0.0 || b <= 0.0)
    {
      throw std::invalid_argument("Invalid ellipse parameters: a and b must be positive.");
    }
  }

  double Ellipse::getArea() const
  {
    constexpr double PI = 3.141592653589793;
    return PI * a_ * b_;
  }
  rectangle_t Ellipse::getFrameRect() const
  {
    return rectangle_t{2 * a_, 2 * b_, center_};
  }
  void Ellipse::move(point_t pos)
  {
    center_ = pos;
  }
  void Ellipse::move(double dx, double dy)
  {
    center_.x += dx;
    center_.y += dy;
  }
  void Ellipse::scale(double k)
  {
    if (k <= 0.0)
    {
      throw std::invalid_argument("Invalid scale factor: k must be positive.");
    }
    a_ *= k;
    b_ *= k;
  }
}
