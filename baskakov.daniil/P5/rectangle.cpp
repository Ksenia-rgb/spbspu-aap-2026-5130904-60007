#include "rectangle.hpp"

#include <stdexcept>

geom::Rectangle::Rectangle(const point_t & pos, double width, double height):
  pos_(pos),
  width_(width),
  height_(height)
{
  if ((width_ <= 0.0) || (height_ <= 0.0))
  {
    throw std::invalid_argument("Invalid rectangle dimensions");
  }
}

double geom::Rectangle::getArea() const
{
  return width_ * height_;
}

geom::rectangle_t geom::Rectangle::getFrameRect() const
{
  return {width_, height_, pos_};
}

void geom::Rectangle::move(const point_t & pos)
{
  pos_ = pos;
}

void geom::Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void geom::Rectangle::scale(double factor)
{
  if (factor <= 0.0)
  {
    throw std::invalid_argument("Invalid scale factor");
  }
  width_ *= factor;
  height_ *= factor;
}
