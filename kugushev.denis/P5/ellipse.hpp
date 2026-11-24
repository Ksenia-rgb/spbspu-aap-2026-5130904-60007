#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "shape.hpp"

namespace kugushev
{
  class Ellipse: public Shape
  {
  public:
    Ellipse(point_t centr, double radius_x, double radius_y);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double dx, double dy) override;
    void scale(double factor) override;

  private:
    point_t centr_;
    double radius_x_;
    double radius_y_;
  };
}

#endif
