
#include "ring.hpp"

#include <cmath>
#include <stdexcept>

namespace
{
    constexpr double PI = 3.14159265358979323846;
}

Ring::Ring(double outerRadius, double innerRadius, point_t position)
    : outerRadius_(outerRadius),
      innerRadius_(innerRadius),
      position_(position)
{
    if (outerRadius <= 0.0 || innerRadius <= 0.0 ||
        innerRadius >= outerRadius)
    {
        throw std::invalid_argument("Invalid ring radii");
    }
}

double Ring::getArea() const
{
    return PI * (outerRadius_ * outerRadius_
               - innerRadius_ * innerRadius_);
}

rectangle_t Ring::getFrameRect() const
{
    return {
        2.0 * outerRadius_,
        2.0 * outerRadius_,
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

    outerRadius_ *= factor;
    innerRadius_ *= factor;
}
