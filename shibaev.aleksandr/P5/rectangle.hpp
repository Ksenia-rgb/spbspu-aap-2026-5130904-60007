#pragma once
#include "shape.hpp"

namespace shibaev
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(double width, double height, point_t pos);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t) override;
    void move(double, double) override;
    void scale(double) override;
    ~Rectangle() override = default;
  private:
    double width;
    double height;
    point_t pos;
  };
}
