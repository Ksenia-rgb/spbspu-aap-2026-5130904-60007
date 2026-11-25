#ifndef SHIBAEV_ELIPSE_HPP
#define SHIBAEV_ELIPSE_HPP

#include "shape.hpp"

namespace shibaev
{
  class Elipse: public Shape
  {
  public:
    Elipse(double width, double height, point_t pos);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t) override;
    void move(double, double) override;
    void scale(double) override;
    ~Elipse() override = default;
  private:
    double width;
    double height;
    point_t pos;
  };
}

#endif
