#ifndef SEMENOV_P5_ELLIPSE_HPP
#define SEMENOV_P5_ELLIPSE_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace semenov {
  class Ellipse: public Shape {
  public:
    Ellipse(point_t center, double a, double b);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t pos) override;
    void move(double dx, double dy) override;
    void scale(double k) override;

  private:
    point_t center_;
    double a_;
    double b_;
  };

}

#endif
