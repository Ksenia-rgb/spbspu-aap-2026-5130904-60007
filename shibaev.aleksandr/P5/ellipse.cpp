#include "ellipse.hpp"
#include <stdexcept>

namespace shibaev
{
  Ellipse::Ellipse(double width, double height, point_t pos):
    width_(width),
    height_(height),
    pos_(pos)
  {
    if (width <= 0 || height <= 0)
    {
      throw std::invalid_argument("Ellipse width and height must be positive");
    }
  }

  double Ellipse::getArea() const
  {
    constexpr double pi = 3.14159265358979323846;
    return pi * width_ * height_;
  }

  rectangle_t Ellipse::getFrameRect() const
  {
    const rectangle_t frame = {2 * width_, 2 * height_, pos_};
    return frame;
  }

  void Ellipse::move(double x, double y)
  {
    pos_.x += x;
    pos_.y += y;
  }

  void Ellipse::move(point_t p)
  {
    pos_.x = p.x;
    pos_.y = p.y;
  }

  void Ellipse::scale(double s)
  {
    if (s <= 0)
    {
      throw std::invalid_argument("Scale factor must be positive");
    }
    width_ *= s;
    height_ *= s;
  }
}
