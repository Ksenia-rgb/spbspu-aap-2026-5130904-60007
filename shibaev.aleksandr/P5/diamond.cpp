#include "diamond.hpp"
#include <stdexcept>

namespace shibaev
{
  Diamond::Diamond(double diagonal1, double diagonal2, point_t pos):
    diagonal1_(diagonal1),
    diagonal2_(diagonal2),
    pos_(pos)
  {
    if (diagonal1 <= 0 || diagonal2 <= 0)
    {
      throw std::invalid_argument("Diamond diagonals must be positive");
    }
  }

  double Diamond::getArea() const
  {
    return diagonal1_ * diagonal2_ / 2;
  }

  rectangle_t Diamond::getFrameRect() const
  {
    const rectangle_t frame = {diagonal1_, diagonal2_, pos_};
    return frame;
  }

  void Diamond::move(double x, double y)
  {
    pos_.x += x;
    pos_.y += y;
  }

  void Diamond::move(point_t p)
  {
    pos_.x = p.x;
    pos_.y = p.y;
  }

  void Diamond::scale(double s)
  {
    if (s <= 0)
    {
      throw std::invalid_argument("Scale factor must be positive");
    }
    diagonal1_ *= s;
    diagonal2_ *= s;
  }
}
