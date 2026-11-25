#include "diamond.hpp"
#include "ellipse.hpp"
#include "rectangle.hpp"
#include <cstddef>
#include <iostream>
#include <stdexcept>

namespace shibaev
{
  void resultCout(const Rectangle& rectangle, const Diamond& diamond, const Ellipse& ellipse);
  rectangle_t generalFrameRect(const Shape* const* shapes, std::size_t count);
  void scaleShapes(Shape* const* shapes, std::size_t count, point_t center, double factor);

  constexpr std::size_t shapeCount = 3;
}

int main()
{
  constexpr double rectangleWidth = 3.0;
  constexpr double rectangleHeight = 6.0;
  constexpr shibaev::point_t rectanglePosition = {-1.0, 7.0};
  shibaev::Rectangle rectangle{rectangleWidth, rectangleHeight, rectanglePosition};

  constexpr double diamondDiagonal1 = 5.0;
  constexpr double diamondDiagonal2 = 2.0;
  constexpr shibaev::point_t diamondPosition = {5.0, 8.0};
  shibaev::Diamond diamond{diamondDiagonal1, diamondDiagonal2, diamondPosition};

  constexpr double ellipseRadiusX = 1.0;
  constexpr double ellipseRadiusY = 4.0;
  constexpr shibaev::point_t ellipsePosition = {2.0, -3.0};
  shibaev::Ellipse ellipse{ellipseRadiusX, ellipseRadiusY, ellipsePosition};

  std::cout << "---Before--- " << '\n';
  shibaev::resultCout(rectangle, diamond, ellipse);

  std::cout << '\n';
  std::cout << "Enter the scaling point (x y) and scale factor: ";
  double x = 0.0, y = 0.0, s = 0.0;
  if (!(std::cin >> x >> y >> s))
  {
    std::cerr << "Invalid input\n";
    return 1;
  }

  shibaev::Shape* const shapes[] = {&rectangle, &diamond, &ellipse};
  try
  {
    shibaev::scaleShapes(shapes, shibaev::shapeCount, {x, y}, s);
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }

  std::cout << '\n';
  std::cout << "---After--- " << '\n';
  shibaev::resultCout(rectangle, diamond, ellipse);
}

void shibaev::resultCout(const Rectangle& rectangle, const Diamond& diamond, const Ellipse& ellipse)
{
  std::cout << "Area:" << '\n';
  std::cout << "  Rectangle: " << rectangle.getArea() << '\n';
  std::cout << "  Diamond: " << diamond.getArea() << '\n';
  std::cout << "  Ellipse: " << ellipse.getArea() << '\n';

  std::cout << "Sum Area: " << rectangle.getArea() + diamond.getArea() + ellipse.getArea() << '\n';

  std::cout << "Frame Rectangle:" << '\n';
  const rectangle_t frame_rectangle = rectangle.getFrameRect();
  std::cout << "  Rectangle: " << frame_rectangle.width << ' ' << frame_rectangle.height << "; "
            << frame_rectangle.pos.x << ' ' << frame_rectangle.pos.y << '\n';
  const rectangle_t frame_diamond = diamond.getFrameRect();
  std::cout << "  Diamond: " << frame_diamond.width << ' ' << frame_diamond.height << "; " << frame_diamond.pos.x << ' '
            << frame_diamond.pos.y << '\n';
  const rectangle_t frame_ellipse = ellipse.getFrameRect();
  std::cout << "  Ellipse: " << frame_ellipse.width << ' ' << frame_ellipse.height << "; " << frame_ellipse.pos.x << ' '
            << frame_ellipse.pos.y << '\n';

  const Shape* shapes[] = {&rectangle, &diamond, &ellipse};
  const rectangle_t general_frame = generalFrameRect(shapes, shapeCount);
  std::cout << "General Frame Rectangle: " << general_frame.width << ' ' << general_frame.height << "; "
            << general_frame.pos.x << ' ' << general_frame.pos.y << '\n';
}

shibaev::rectangle_t shibaev::generalFrameRect(const Shape* const* const shapes, std::size_t count)
{
  rectangle_t frame_rectangle = shapes[0]->getFrameRect();
  double left = frame_rectangle.pos.x - frame_rectangle.width / 2;
  double right = frame_rectangle.pos.x + frame_rectangle.width / 2;
  double top = frame_rectangle.pos.y + frame_rectangle.height / 2;
  double bottom = frame_rectangle.pos.y - frame_rectangle.height / 2;
  for (std::size_t i = 1; i < count; ++i)
  {
    frame_rectangle = shapes[i]->getFrameRect();
    const double left_temp = frame_rectangle.pos.x - frame_rectangle.width / 2;
    if (left > left_temp)
    {
      left = left_temp;
    }
    const double right_temp = frame_rectangle.pos.x + frame_rectangle.width / 2;
    if (right < right_temp)
    {
      right = right_temp;
    }
    const double top_temp = frame_rectangle.pos.y + frame_rectangle.height / 2;
    if (top < top_temp)
    {
      top = top_temp;
    }
    const double bottom_temp = frame_rectangle.pos.y - frame_rectangle.height / 2;
    if (bottom > bottom_temp)
    {
      bottom = bottom_temp;
    }
  }
  const rectangle_t result = {right - left, top - bottom, {(left + right) / 2, (bottom + top) / 2}};
  return result;
}

void shibaev::scaleShapes(Shape* const* const shapes, std::size_t count, point_t center, double factor)
{
  for (std::size_t i = 0; i < count; ++i)
  {
    shapes[i]->scale(factor);
    const rectangle_t frame = shapes[i]->getFrameRect();
    const double new_x = center.x + (frame.pos.x - center.x) * factor;
    const double new_y = center.y + (frame.pos.y - center.y) * factor;
    shapes[i]->move(point_t{new_x, new_y});
  }
}
