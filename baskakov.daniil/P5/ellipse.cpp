#include "ellipse.hpp"

#include <stdexcept>

geom::Ellipse::Ellipse(const point_t & pos, double radius_x, double radius_y):
  pos_(pos),
  radius_x_(radius_x),
  radius_y_(radius_y)
{
  if ((radius_x_ <= 0.0) || (radius_y_ <= 0.0))
  {
    throw std::invalid_argument("Invalid ellipse radii");
  }
}

double geom::Ellipse::getArea() const
{
  constexpr double pi = 3.14159265358979323846;
  return pi * radius_x_ * radius_y_;
}

geom::rectangle_t geom::Ellipse::getFrameRect() const
{
  constexpr double diameter_factor = 2.0;
  const double width = diameter_factor * radius_x_;
  const double height = diameter_factor * radius_y_;
  return {width, height, pos_};
}

void geom::Ellipse::move(const point_t & pos)
{
  pos_ = pos;
}

void geom::Ellipse::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void geom::Ellipse::scale(double factor)
{
  if (factor <= 0.0)
  {
    throw std::invalid_argument("Invalid scale factor");
  }
  radius_x_ *= factor;
  radius_y_ *= factor;
}
