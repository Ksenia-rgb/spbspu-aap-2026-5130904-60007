#include "diamond.hpp"
#include "elipse.hpp"
#include "rectangle.hpp"
#include <iostream>
#include <cstddef>
#include <stdexcept>

namespace shibaev
{
  void resultCout(const Rectangle& rectangle, const Diamond& diamond, const Elipse& elipse);
  rectangle_t generalFrameRect(const Shape* const* shapes, std::size_t count);
  void scaleShapes(Shape* const* shapes, std::size_t count, point_t center, double factor);
}

int main()
{
  shibaev::Rectangle rectangle{3., 6., {-1., 7.}};
  shibaev::Diamond diamond{5., 2., {5., 8.}};
  shibaev::Elipse elipse{1., 4., {2., -3.}};

  std::cout << "---Before--- " << '\n';
  shibaev::resultCout(rectangle, diamond, elipse);

  std::cout << '\n';
  std::cout << "Enter the scaling point (x y) and scale factor: ";
  double x, y, s;
  if (!(std::cin >> x >> y >> s))
  {
    std::cerr << "Invalid input\n";
    return 1;
  }

  shibaev::Shape* shapes[] = {&rectangle, &diamond, &elipse};
  try
  {
    shibaev::scaleShapes(shapes, 3, {x, y}, s);
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }

  std::cout << '\n';
  std::cout << "---After--- " << '\n';
  shibaev::resultCout(rectangle, diamond, elipse);
}

void shibaev::resultCout(const Rectangle& rectangle, const Diamond& diamond, const Elipse& elipse)
{
  std::cout << "Area:" << '\n';
  std::cout << "  Rectangle: " << rectangle.getArea() << '\n';
  std::cout << "  Diamond: " << diamond.getArea() << '\n';
  std::cout << "  Elipse: " << elipse.getArea() << '\n';

  std::cout << "Sum Area: " << rectangle.getArea() + diamond.getArea() + elipse.getArea() << '\n';

  std::cout << "Frame Rectangle:" << '\n';
  rectangle_t frame_rectangle = rectangle.getFrameRect();
  std::cout << "  Rectangle: " << frame_rectangle.width << ' ' << frame_rectangle.height << "; "
            << frame_rectangle.pos.x << ' ' << frame_rectangle.pos.y << '\n';
  rectangle_t frame_diamonnd = diamond.getFrameRect();
  std::cout << "  Diamond: " << frame_diamonnd.width << ' ' << frame_diamonnd.height << "; " << frame_diamonnd.pos.x
            << ' ' << frame_diamonnd.pos.y << '\n';
  rectangle_t frame_elipse = elipse.getFrameRect();
  std::cout << "  Elipse: " << frame_elipse.width << ' ' << frame_elipse.height << "; " << frame_elipse.pos.x << ' '
            << frame_elipse.pos.y << '\n';

  const Shape* shapes[] = {&rectangle, &diamond, &elipse};
  rectangle_t general_frame = generalFrameRect(shapes, 3);
  std::cout << "General Frame Rectangle: " << general_frame.width << ' ' << general_frame.height << "; "
            << general_frame.pos.x << ' ' << general_frame.pos.y << '\n';
}

shibaev::rectangle_t shibaev::generalFrameRect(const Shape* const* shapes, std::size_t count)
{
  rectangle_t frame_rectangle = shapes[0]->getFrameRect();
  double left = frame_rectangle.pos.x - frame_rectangle.width / 2;
  double right = frame_rectangle.pos.x + frame_rectangle.width / 2;
  double top = frame_rectangle.pos.y + frame_rectangle.height / 2;
  double bottom = frame_rectangle.pos.y - frame_rectangle.height / 2;
  for (std::size_t i = 1; i < count; ++i)
  {
    frame_rectangle = shapes[i]->getFrameRect();
    double left_temp = frame_rectangle.pos.x - frame_rectangle.width / 2;
    if (left > left_temp)
    {
      left = left_temp;
    }
    double right_temp = frame_rectangle.pos.x + frame_rectangle.width / 2;
    if (right < right_temp)
    {
      right = right_temp;
    }
    double top_temp = frame_rectangle.pos.y + frame_rectangle.height / 2;
    if (top < top_temp)
    {
      top = top_temp;
    }
    double bottom_temp = frame_rectangle.pos.y - frame_rectangle.height / 2;
    if (bottom > bottom_temp)
    {
      bottom = bottom_temp;
    }
  }
  rectangle_t result = {right - left, top - bottom, {(left + right) / 2, (bottom + top) / 2}};
  return result;
}

void shibaev::scaleShapes(Shape* const* shapes, std::size_t count, point_t center, double factor)
{
  for (std::size_t i = 0; i < count; ++i)
  {
    shapes[i]->scale(factor);
    rectangle_t frame = shapes[i]->getFrameRect();
    double new_x = center.x + (frame.pos.x - center.x) * factor;
    double new_y = center.y + (frame.pos.y - center.y) * factor;
    shapes[i]->move(point_t{new_x, new_y});
  }
}
