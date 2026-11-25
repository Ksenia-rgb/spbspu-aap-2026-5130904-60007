#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"

namespace shibaev
{
  class Diamond: public Shape
  {
  public:
    Diamond(double diagonal1, double diagonal2, point_t pos);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t) override;
    void move(double, double) override;
    void scale(double) override;
    ~Diamond() override = default;
  private:
    double diagonal1_;
    double diagonal2_;
    point_t pos_;
  };
}

#endif
