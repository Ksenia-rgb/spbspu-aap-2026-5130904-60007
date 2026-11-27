#include "diamond.hpp"

namespace tsvetkov
{
  Diamond::Diamond(point_t center, double diagx, double diagy):
    center_{center},
    diagx_{diagx},
    diagy_{diagy}
  {}

  double Diamond::getArea() const
  {
    return diagx_ * diagy_ / 2;
  }

  rectangle_t Diamond::getFrameRect() const
  {
    return {diagx_, diagy_, center_};
  }

  void Diamond::move(point_t point)
  {
    center_ = point;
  }

  void Diamond::move(double dx, double dy)
  {
    center_.x += dx;
    center_.y += dy;
  }

  void Diamond::scale(double factor)
  {
    diagx_ *= factor;
    diagy_ *= factor;
  }
}
