#include "ellipse.hpp"
#include "diamond.hpp"
#include "rectangle.hpp"

#include <iostream>
#include <algorithm>
#include <cstddef>

namespace tsvetkov
{
  constexpr double half = 0.5;
  double areasum(const Shape* const* shapes, std::size_t n);
  void printRect(const rectangle_t& rect);
  rectangle_t genframe(const Shape* const* shapes, std::size_t n);
  void scaleFromPoint(Shape* const* shapes, std::size_t n, point_t center, double coef);
}

int main()
{
  constexpr tsvetkov::point_t rect_center{1.0, 2.0};
  constexpr double rect_width = 6.0;
  constexpr double rect_height = 3.0;
  constexpr tsvetkov::point_t diamond_center{-2.0, 4.0};
  constexpr double diamond_xdiag = 4.0;
  constexpr double diamond_ydiag = 2.0;
  constexpr tsvetkov::point_t ellipse_center{5.0, -1.0};
  constexpr double ellipse_radius_x = 3.0;
  constexpr double ellipse_radius_y = 1.5;

  tsvetkov::Rectangle rec{rect_center, rect_width, rect_height};
  tsvetkov::Diamond dia{diamond_center, diamond_xdiag, diamond_ydiag};
  tsvetkov::Ellipse ell{ellipse_center, ellipse_radius_x, ellipse_radius_y};

  constexpr std::size_t n = 3;
  tsvetkov::Shape* shapes[n]{&rec, &dia, &ell};

  for (std::size_t i = 0; i < n; i++)
  {
    const double area = shapes[i]->getArea();
    std::cout << area << "\n";
    const tsvetkov::rectangle_t rectan = shapes[i]->getFrameRect();
    tsvetkov::printRect(rectan);
  }

  double arsum = tsvetkov::areasum(shapes, n);
  std::cout << arsum << "\n";
  tsvetkov::printRect(tsvetkov::genframe(shapes, n));

  tsvetkov::point_t scale_center = {};
  double coef = 0;

  if (!(std::cin >> scale_center.x) || !(std::cin >> scale_center.y))
  {
    std::cerr << "Неправильно задана точка!" << "\n";
    return 1;
  }
  if (!(std::cin >> coef))
  {
    std::cerr << "Неправильно задан коэффициент!" << "\n";
    return 1;
  }
  if (coef <= 0)
  {
    std::cerr << "Коэффициент должен быть больше нуля!" << "\n";
    return 1;
  }

  tsvetkov::scaleFromPoint(shapes, n, scale_center, coef);

  for (std::size_t i = 0; i < n; i++)
  {
    const double area = shapes[i]->getArea();
    std::cout << area << "\n";
    const tsvetkov::rectangle_t rectan = shapes[i]->getFrameRect();
    tsvetkov::printRect(rectan);
  }

  arsum = tsvetkov::areasum(shapes, n);
  std::cout << arsum << "\n";
  tsvetkov::printRect(tsvetkov::genframe(shapes, n));

  return 0;
}

double tsvetkov::areasum(const Shape* const* shapes, std::size_t n)
{
  double s = 0;
  for (std::size_t i = 0; i < n; i++)
  {
    const double ar = shapes[i]->getArea();
    s += ar;
  }
  return s;
}

void tsvetkov::printRect(const rectangle_t& rect)
{
  std::cout << "Высота:" << rect.height << "\n";
  std::cout << "Ширина:" << rect.width << "\n";
  std::cout << "Координаты центра:" << rect.pos.x << " " << rect.pos.y << "\n";
}

tsvetkov::rectangle_t tsvetkov::genframe(const Shape* const* shapes, std::size_t n)
{
  const rectangle_t firstrec = shapes[0]->getFrameRect();
  double left = firstrec.pos.x - firstrec.width * half;
  double bottom = firstrec.pos.y - firstrec.height * half;
  double right = firstrec.pos.x + firstrec.width * half;
  double top = firstrec.pos.y + firstrec.height * half;

  for (std::size_t i = 1; i < n; i++)
  {
    const rectangle_t r = shapes[i]->getFrameRect();
    left = std::min(left, r.pos.x - r.width * half);
    bottom = std::min(bottom, r.pos.y - r.height * half);
    right = std::max(right, r.pos.x + r.width * half);
    top = std::max(top, r.pos.y + r.height * half);
  }

  const double width = right - left;
  const double height = top - bottom;
  const point_t center{(left + right) * half, (bottom + top) * half};
  return {width, height, center};
}

void tsvetkov::scaleFromPoint(Shape* const* shapes, std::size_t n, point_t center, double coef)
{
  for (std::size_t i = 0; i < n; i++)
  {
    const point_t before = shapes[i]->getFrameRect().pos;
    shapes[i]->move(center);
    const point_t moved = shapes[i]->getFrameRect().pos;
    shapes[i]->scale(coef);
    shapes[i]->move((before.x - moved.x) * coef, (before.y - moved.y) * coef);
  }
}
