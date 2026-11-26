#include "diamond.hpp"

#include <stdexcept>

namespace semenov {
  Diamond::Diamond(point_t center, double diagonalX, double diagonalY):
    frame_{diagonalX, diagonalY, center}
  {
    if (!(diagonalX > 0.0 && diagonalY > 0.0)) {
      throw std::invalid_argument("Diamond diagonals must be positive.");
    }
  }

  double Diamond::getArea() const
  {
    return (frame_.width * 0.5) * frame_.height;
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
    if (!(k > 0.0)) {
      throw std::invalid_argument("Scale factor must be positive.");
    }
    frame_.width *= k;
    frame_.height *= k;
  }
}
