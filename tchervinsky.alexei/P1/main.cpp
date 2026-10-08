#include <iostream>
#include <cstddef>

#define ERROR_NOT_ENOUGH_DATA 2

int main()
{
  int a{0};
  int sum{0};
  std::size_t count{0};

  while ((std::cin >> a) && (a != 0))
  {
    ++count;
    sum += a;
  }

  if (!std::cin)
  {
    std::cerr << "Incorrect input" << '\n';
    return 1;
  }

  if (count == 0)
  {
    std::cerr << "Not enough data" << '\n';
    return ERROR_NOT_ENOUGH_DATA;
  }

  std::cout << (sum / static_cast< double >(count)) << '\n';
  return 0;
}
