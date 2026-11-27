#include "ring.hpp"

#include <cmath>
#include <stdexcept>

namespace
{
    constexpr double pi = 3.14159265358979323846;
}

Ring::Ring(double outer_radius, double inner_radius, point_t position)
    : outer_radius_(outer_radius),
      inner_radius_(inner_radius),
      position_(position)
{
    if (outer_radius <= 0.0 ||
        inner_radius <= 0.0 ||
        inner_radius >= outer_radius)
    {
        throw std::invalid_argument("Invalid ring radii");
    }
}

double Ring::getArea() const
{
    return pi * (outer_radius_ * outer_radius_
               - inner_radius_ * inner_radius_);
}

rectangle_t Ring::getFrameRect() const
{
    return {
        2.0 * outer_radius_,
        2.0 * outer_radius_,
        position_
    };
}

void Ring::move(point_t position)
{
    position_ = position;
}

void Ring::move(double dx, double dy)
{
    position_.x += dx;
    position_.y += dy;
}

void Ring::scale(double factor)
{
    if (factor <= 0.0)
    {
        throw std::invalid_argument("Scale factor must be positive");
    }

    outer_radius_ *= factor;
    inner_radius_ *= factor;
}
