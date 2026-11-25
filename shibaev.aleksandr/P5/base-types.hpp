#ifndef SHIBAEV_BASE_TYPES_HPP
#define SHIBAEV_BASE_TYPES_HPP

namespace shibaev
{
  struct point_t
  {
    double x;
    double y;
  };

  struct rectangle_t
  {
    double width;
    double height;
    point_t pos;
  };
}

#endif
