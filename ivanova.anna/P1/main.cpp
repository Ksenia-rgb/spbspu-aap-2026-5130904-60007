#include <iostream>
#include <limits>

#define ERROR_NOT_ENOUGH_DATA 2

int main()
{
  long long a = 0;
  long long max1 = std::numeric_limits< long long >::min();
  long long max2 = std::numeric_limits< long long >::min();

  int count = 0;

  while ((std::cin >> a) && (a != 0)) {
    ++count;

    if (a > max1) {
      max2 = max1;
      max1 = a;
    } else if (a > max2 && a != max1) {
      max2 = a;
    }
  }

  if (!std::cin) {
    std::cerr << "Incorrect input" << '\n';
    return 1;
  }

  if (count < 2 || max2 == std::numeric_limits< long long >::min()) {
    std::cerr << "Not enough data" << '\n';
    return ERROR_NOT_ENOUGH_DATA;
  }

  std::cout << max2 << '\n';
  return 0;
}
