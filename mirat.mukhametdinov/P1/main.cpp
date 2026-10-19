#include <iostream>

int main()
{
  int n = 0;
  std::cin >> n;
  if (!std::cin)
  {
    std::cerr << "Wrong input\n";
    return 1;
  }

  int count = 0;
  int step = 0;
  int a = 0;
  int b = 0;
  int c = 0;

  while (n != 0)
  {
    a = b;
    b = c;
    c = n;
    step++;

    if (step >= 3)
    {
      if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
      {
        ++count;
      }
    }

    std::cin >> n;
    if (!std::cin)
    {
      std::cerr << "Wrong input\n";
      return 1;
    }
  }

  std::cout << count << "\n";
  return 0;
}
