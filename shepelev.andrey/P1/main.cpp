#include <iostream>

int main()
{
  int x, prev = 0;
  int cur = 0, best = 0;
  while (std::cin >> x && x != 0)
  {
    if (cur > 0 && x >= prev)
      cur++;
    else
      cur = 1;
    if (cur > best)
      best = cur;
    prev = x;
  }
  std::cout << best << std::endl;
  return 0;
}

