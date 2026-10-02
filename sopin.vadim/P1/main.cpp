//1 Вариант - INC-SEQ
// Определить, сколько элементов последовательности больше предыдущего элемента
#include <iostream>
#include <cstddef>

int main()
{
  int a(0);
  int prev(0);
  bool hasPrev(false);
  std::size_t result(0);

  std::cin >> a;

  while (true)
  {
    if (std::cin.bad())
    {
      std::cerr << "Internal stream error\n";
      return 1;
    }
    else if (std::cin.fail())
    {
      if (std::cin.eof())
      {
        std::cerr << "Unexpected eof\n";
      }
      else
      {
        std::cerr << "Unexpected input\n";
      }
      return 1;
    }

    if (a == 0)
    {
      break;
    }

    if (hasPrev && (a > prev))
    {
      ++result;
    }
    prev = a;
    hasPrev = true;

    std::cin >> a;
  }

  std::cout << result << "\n";
  return 0;
}