#include "ellipse.hpp"

namespace tsvetkov
{
  constexpr double Pi = 3.14159265358979323846;

  Ellipse::Ellipse(point_t center, double radx, double rady):
    center_{center},
    radx_{radx},
    rady_{rady}
  {}

  double Ellipse::getArea() const
  {
    return radx_ * rady_ * Pi;
  }

  rectangle_t Ellipse::getFrameRect() const
  {
    return {radx_ * 2, rady_ * 2, center_};
  }

  void Ellipse::move(point_t point)
  {
    center_ = point;
  }

  void Ellipse::move(double dx, double dy)
  {
    center_.x += dx;
    center_.y += dy;
  }

  void Ellipse::scale(double factor)
  {
    radx_ *= factor;
    rady_ *= factor;
  }
}
