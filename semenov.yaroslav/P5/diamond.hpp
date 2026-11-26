#pragma once

#include "shape.hpp"

namespace semenov {
  class Diamond: public Shape {
  public:
    Diamond(point_t center, double diagonalX, double diagonalY);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t pos) override;
    void move(double dx, double dy) override;
    void scale(double k) override;

  private:
    rectangle_t frame_;
  };
}
