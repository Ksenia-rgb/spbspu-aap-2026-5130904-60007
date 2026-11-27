#include "diamond.hpp"

#include <stdexcept>

geom::Diamond::Diamond(const point_t & pos, double diagonal_x, double diagonal_y):
  pos_(pos),
  diagonal_x_(diagonal_x),
  diagonal_y_(diagonal_y)
{
  if ((diagonal_x_ <= 0.0) || (diagonal_y_ <= 0.0))
  {
    throw std::invalid_argument("Invalid diamond diagonals");
  }
}

double geom::Diamond::getArea() const
{
  constexpr double half_divisor = 2.0;
  return (diagonal_x_ * diagonal_y_) / half_divisor;
}

geom::rectangle_t geom::Diamond::getFrameRect() const
{
  return {diagonal_x_, diagonal_y_, pos_};
}

void geom::Diamond::move(const point_t & pos)
{
  pos_ = pos;
}

void geom::Diamond::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void geom::Diamond::scale(double factor)
{
  if (factor <= 0.0)
  {
    throw std::invalid_argument("Invalid scale factor");
  }
  diagonal_x_ *= factor;
  diagonal_y_ *= factor;
}
