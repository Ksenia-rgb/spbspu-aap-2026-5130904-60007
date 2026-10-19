#include <iostream>

int main()
{
  int prev{0};
  int cur{0};
  bool is_first{true};
  int count{0};

  while ((std::cin >> cur) && (cur != 0))
  {
    if (!is_first && (cur > prev))
    {
      ++count;
    }

    prev = cur;
    is_first = false;
  }

  if (!std::cin)
  {
    std::cerr << "Incorrect input" << '\n';
    return 1;
  }

  std::cout << count << '\n';
  return 0;
}
