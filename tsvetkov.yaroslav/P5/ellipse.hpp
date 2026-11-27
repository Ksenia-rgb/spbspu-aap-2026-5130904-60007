#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "shape.hpp"

namespace tsvetkov
{
  class Ellipse: public Shape
  {
  public:
    Ellipse(point_t center, double radx, double rady);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double dx, double dy) override;
    void scale(double factor) override;
  private:
    point_t center_;
    double radx_;
    double rady_;
  };
}
#endif
