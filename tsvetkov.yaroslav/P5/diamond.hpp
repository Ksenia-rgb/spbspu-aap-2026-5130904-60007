#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"

namespace tsvetkov
{
  class Diamond: public Shape
  {
  public:
    Diamond(point_t center, double diagx, double diagy);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double dx, double dy) override;
    void scale(double factor) override;
  private:
    point_t center_;
    double diagx_;
    double diagy_;
  };
}

#endif
