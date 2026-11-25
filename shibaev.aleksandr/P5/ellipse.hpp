#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "shape.hpp"

namespace shibaev
{
  class Ellipse: public Shape
  {
  public:
    Ellipse(double width, double height, point_t pos);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t) override;
    void move(double, double) override;
    void scale(double) override;
    ~Ellipse() override = default;
  private:
    double width_;
    double height_;
    point_t pos_;
  };
}

#endif
