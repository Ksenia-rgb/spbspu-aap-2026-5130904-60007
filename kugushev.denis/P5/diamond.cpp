#include "diamond.hpp"

namespace kugushev
{
  Diamond::Diamond(point_t centr, double xdiag, double ydiag):
    centr_{centr},
    xdiag_{xdiag},
    ydiag_{ydiag}
  {}

  double Diamond::getArea() const
  {
    constexpr double area_divisor = 2.0;
    return xdiag_ * ydiag_ / area_divisor;
  }

  rectangle_t Diamond::getFrameRect() const
  {
    return {xdiag_, ydiag_, centr_};
  }

  void Diamond::move(point_t point)
  {
    centr_ = point;
  }

  void Diamond::move(double dx, double dy)
  {
    centr_.x += dx;
    centr_.y += dy;
  }

  void Diamond::scale(double factor)
  {
    xdiag_ *= factor;
    ydiag_ *= factor;
  }
}
