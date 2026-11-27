#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "rectangle.hpp"

class Square : public Rectangle
{
public:
    Square(double side, point_t position);
};

#endif // SQUARE_HPP
