#include <iostream>
#include <cstddef>
int main()
{
  int x;
  int cur{0};
  int mx{0};
  int count{0};
  bool found_zero = false;
  while (std::cin >> x)
  {
    if (x == 0)
    {
      found_zero = true;
      break;
    }
    count++;

    if (x != 0 && x % 2 == 0)
    {
      cur++;
    }
    else
    {
      if (cur > mx)
      {
        mx = cur;
      }
    cur = 0;
    }
  }
  if (std::cin.fail() && !std::cin.eof())
  {
    std::cerr << "Incorrect data" << "\n";
    std::cin.clear();
    return 1;
  }
  if (!found_zero)
  {
    std::cerr << "Incorrect data AGAIN" << "\n";
    return 1;
  }
  if (count == 0)
  {
    std::cerr << "Empty sequence" << "\n";
    std::cout << 0 << "\n";
    return 2;
  }
  if (cur > mx)
  {
    mx = cur;
  }
  std::cout << mx << "\n";
  return 0;
}
