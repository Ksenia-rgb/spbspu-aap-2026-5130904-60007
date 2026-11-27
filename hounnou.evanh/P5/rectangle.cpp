#include "rectangle.hpp"

#include <stdexcept>

Rectangle::Rectangle(double width, double height, point_t position)
    : width_(width),
      height_(height),
      position_(position)
{
    if (width <= 0.0 || height <= 0.0)
    {
        throw std::invalid_argument("Rectangle dimensions must be positive");
    }
}

double Rectangle::getArea() const
{
    return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
    return {width_, height_, position_};
}

void Rectangle::move(point_t position)
{
    position_ = position;
}

void Rectangle::move(double dx, double dy)
{
    position_.x += dx;
    position_.y += dy;
}

void Rectangle::scale(double factor)
{
    if (factor <= 0.0)
    {
        throw std::invalid_argument("Scale factor must be positive");
    }

    width_ *= factor;
    height_ *= factor;
}
