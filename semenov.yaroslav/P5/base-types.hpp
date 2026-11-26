#ifndef SEMENOV_P5_BASE_TYPES_HPP
#define SEMENOV_P5_BASE_TYPES_HPP

namespace semenov {
  struct point_t {
    double x;
    double y;
  };
  struct rectangle_t {
    double width;
    double height;
    point_t pos;
  };
}

#endif
