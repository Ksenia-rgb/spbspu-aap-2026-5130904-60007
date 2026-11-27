
#ifndef RING_HPP
#define RING_HPP

#include "shape.hpp"

class Ring : public Shape
{
public:
    Ring(double outerRadius, double innerRadius, point_t position);

    double getArea() const override;

    rectangle_t getFrameRect() const override;

    void move(point_t position) override;

    void move(double dx, double dy) override;

    void scale(double factor) override;

private:
    double outerRadius_;
    double innerRadius_;
    point_t position_;
};

#endif
