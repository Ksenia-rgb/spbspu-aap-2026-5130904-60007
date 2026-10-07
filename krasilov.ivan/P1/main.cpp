#include <iostream>
#include <limits>

int main()
{
  const int error_code_overflow = 2;

  int prev = 0;
  int cur = 0;
  bool is_first = true;
  unsigned long long count = 0;
  bool overflow = false;

  while (true)
  {
    if (!(std::cin >> cur))
    {
      std::cerr << "Error: input is not a sequence\n";
      return 1;
    }

    if (cur == 0)
    {
      break;
    }

    if (!is_first && cur > prev)
    {
      if (count == std::numeric_limits< unsigned long long >::max())
      {
        overflow = true;
      }
      else
      {
        ++count;
      }
    }

    prev = cur;
    is_first = false;
  }

  if (overflow)
  {
    std::cerr << "Error: sequence is too long\n";
    return error_code_overflow;
  }

  std::cout << count << '\n';
  return 0;
}
