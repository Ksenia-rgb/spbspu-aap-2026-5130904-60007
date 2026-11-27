
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle(double width, double height, point_t position);

    double getArea() const override;

    rectangle_t getFrameRect() const override;

    void move(point_t position) override;

    void move(double dx, double dy) override;

    void scale(double factor) override;

private:
    double width_;
    double height_;
    point_t position_;
};

#endif
