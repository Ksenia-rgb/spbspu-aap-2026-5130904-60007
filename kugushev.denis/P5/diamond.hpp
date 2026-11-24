#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"

namespace kugushev
{
  class Diamond: public Shape
  {
  public:
    Diamond(point_t centr, double Xdiag, double Ydiag);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double dx, double dy) override;
    void scale(double factor) override;

  private:
    point_t centr_;
    double Xdiag_;
    double Ydiag_;
  };
}

#endif
