#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace kugushev
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(point_t centr, double width, double height);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double dx, double dy) override;
    void scale(double factor) override;

  private:
    double width_;
    double height_;
    point_t centr_;
  };
}

#endif
