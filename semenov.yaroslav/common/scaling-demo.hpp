#ifndef SCALING_DEMO_HPP
#define SCALING_DEMO_HPP

#include <shape.hpp>

#include <algorithm>
#include <cmath>
#include <iostream>

namespace semenov
{
  inline void printFrame(const rectangle_t& frame)
  {
    std::cout << frame.width << ' ' << frame.height << ' ' << frame.pos.x << ' ' << frame.pos.y << '\n';
  }

  struct Bounds
  {
    double left;
    double right;
    double bottom;
    double top;
  };

  inline Bounds getBounds(const rectangle_t& frame)
  {
    return {
      frame.pos.x - frame.width / 2,
      frame.pos.x + frame.width / 2,
      frame.pos.y - frame.height / 2,
      frame.pos.y + frame.height / 2
    };
  }

  inline void printFigure(const Shape& figure, double& total_area, Bounds& bounds)
  {
    const double area = figure.getArea();
    const rectangle_t frame = figure.getFrameRect();
    std::cout << area << '\n';
    printFrame(frame);
    total_area += area;

    const Bounds current = getBounds(frame);
    bounds.left = std::min(bounds.left, current.left);
    bounds.right = std::max(bounds.right, current.right);
    bounds.bottom = std::min(bounds.bottom, current.bottom);
    bounds.top = std::max(bounds.top, current.top);
  }

  inline void printTotal(double total_area, const Bounds& bounds)
  {
    std::cout << "Total Area: " << total_area << '\n';
    std::cout << "Total Frame: ";
    const point_t center{bounds.left / 2 + bounds.right / 2, bounds.bottom / 2 + bounds.top / 2};
    printFrame({bounds.right - bounds.left, bounds.top - bounds.bottom, center});
  }

  inline void scaleFigure(Shape& figure, point_t origin, double factor)
  {
    const point_t center = figure.getFrameRect().pos;
    const point_t pos{origin.x + (center.x - origin.x) * factor,
      origin.y + (center.y - origin.y) * factor};
    figure.move(pos);
    figure.scale(factor);
  }

  inline bool readScale(point_t& origin, double& factor)
  {
    std::cin >> origin.x >> origin.y >> factor;
    return std::cin && std::isfinite(origin.x) && std::isfinite(origin.y)
      && std::isfinite(factor) && factor > 0;
  }
}

#endif
