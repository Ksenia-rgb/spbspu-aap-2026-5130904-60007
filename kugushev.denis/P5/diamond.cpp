#include "diamond.hpp"

namespace kugushev
{
  Diamond::Diamond(point_t centr, double Xdiag, double Ydiag):
    centr_{centr},
    Xdiag_{Xdiag},
    Ydiag_{Ydiag}
  {}

  double Diamond::getArea() const
  {
    return Xdiag_ * Ydiag_ / 2.0;
  }

  rectangle_t Diamond::getFrameRect() const
  {
    return {Xdiag_, Ydiag_, centr_};
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
    Xdiag_ *= factor;
    Ydiag_ *= factor;
  }
}
