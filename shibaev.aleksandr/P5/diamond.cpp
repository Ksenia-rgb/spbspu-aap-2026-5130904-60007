#include "diamond.hpp"
#include <stdexcept>

namespace shibaev
{
  Diamond::Diamond(double diagonal1, double diagonal2, point_t pos):
    diagonal1(diagonal1),
    diagonal2(diagonal2),
    pos(pos)
  {
    if (diagonal1 <= 0 || diagonal2 <= 0)
    {
      throw std::invalid_argument("Diamond diagonals must be positive");
    }
  }

  double Diamond::getArea() const
  {
    return diagonal1 * diagonal2 / 2;
  }

  rectangle_t Diamond::getFrameRect() const
  {
    rectangle_t frame = {diagonal1, diagonal2, pos};
    return frame;
  }

  void Diamond::move(double x, double y)
  {
    pos.x += x;
    pos.y += y;
  }

  void Diamond::move(point_t p)
  {
    pos.x = p.x;
    pos.y = p.y;
  }

  void Diamond::scale(double s)
  {
    if (s <= 0)
    {
      throw std::invalid_argument("Scale factor must be positive");
    }
    diagonal1 *= s;
    diagonal2 *= s;
  }
}
