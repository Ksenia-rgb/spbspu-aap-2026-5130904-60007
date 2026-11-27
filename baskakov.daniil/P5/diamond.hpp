#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"

namespace geom
{
  class Diamond: public Shape
  {
  public:
    Diamond(const point_t & pos, double diagonal_x, double diagonal_y);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t & pos) override;
    void move(double dx, double dy) override;
    void scale(double factor) override;

  private:
    point_t pos_;
    double diagonal_x_;
    double diagonal_y_;
  };
}

#endif
