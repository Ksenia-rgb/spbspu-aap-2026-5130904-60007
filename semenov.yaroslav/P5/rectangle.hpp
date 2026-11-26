#ifndef SEMENOV_P5_RECTANGLE_HPP
#define SEMENOV_P5_RECTANGLE_HPP

#include "shape.hpp"

namespace semenov {
  class Rectangle: public Shape {
  public:
    Rectangle(point_t center, double width, double height);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t pos) override;
    void move(double dx, double dy) override;
    void scale(double k) override;

  private:
    rectangle_t frame_;
  };
}

#endif
