#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace semenov
{
  class Shape
  {
  public:
    virtual ~Shape() = default;

    virtual Shape* clone() const = 0;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t pos) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double k) = 0;
  };
}

#endif
