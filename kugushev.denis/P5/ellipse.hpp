#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "shape.hpp"

namespace kugushev
{
  class Ellipse: public Shape
  {
  public:
    Ellipse(point_t centr, double radiusX, double radiusY);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double dx, double dy) override;
    void scale(double factor) override;

  private:
    point_t centr_;
    double radiusX_;
    double radiusY_;
  };
}

#endif
