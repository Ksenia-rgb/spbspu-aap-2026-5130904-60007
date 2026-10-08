#include <iostream>

int main()
{
  int current = 0;
  int previous = 0;
  int count = 0;
  int max_count = 0;

  std::cin >> previous;

  if (previous == 0)
  {
    std::cout << 0 << '\n';
    return 0;
  }

  count = 1;

  while (true)
  {
    std::cin >> current;

    if (current == 0)
    {
      break;
    }

    if (current == previous)
    {
      ++count;
    }
    else
    {
      count = 1;
    }

    if (count > max_count)
    {
      max_count = count;
    }

    previous = current;
  }

  if (max_count == 0)
  {
    max_count = count;
  }

  std::cout << max_count << '\n';

  return 0;
}
