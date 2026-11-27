#include "diamond.hpp"

#include <stdexcept>

namespace semenov
{
  Diamond::Diamond(point_t center, double diagonal_x, double diagonal_y):
    frame_{diagonal_x, diagonal_y, center}
  {
    if (!(diagonal_x > 0.0 && diagonal_y > 0.0))
    {
      throw std::invalid_argument("Diamond diagonals must be positive.");
    }
  }

  Shape* Diamond::clone() const
  {
    return new Diamond(*this);
  }

  double Diamond::getArea() const
  {
    return frame_.width * frame_.height / 2;
  }

  rectangle_t Diamond::getFrameRect() const
  {
    return frame_;
  }

  void Diamond::move(point_t pos)
  {
    frame_.pos = pos;
  }

  void Diamond::move(double dx, double dy)
  {
    frame_.pos.x += dx;
    frame_.pos.y += dy;
  }

  void Diamond::scale(double k)
  {
    if (!(k > 0.0))
    {
      throw std::invalid_argument("Scale factor must be positive.");
    }
    frame_.width *= k;
    frame_.height *= k;
  }
}
