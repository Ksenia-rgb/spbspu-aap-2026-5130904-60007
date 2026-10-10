#include <iostream>

int max(int a, int b)
{
  if (a >= b)
  {
    return a;
  }
  else
  {
    return b;
  }
}

void findCntMax(int& exit_code)
{
  int i = 0;
  if (!(std::cin >> i))
  {
    exit_code = 1;
    return;
  }

  int cnt = 0;

  if (i != 0)
  {
    cnt = 1;
  }
  else
  {
    std::cerr << "Error: not enough numbers" << "\n";
    exit_code = 2;
    return;
  }

  int i_past = i;
  while ((std::cin >> i) && (i != 0))
  {
    if (i == max(i, i_past))
    {
      cnt++;
    }

    if (max(i, i_past) > i_past)
    {
      i_past = max(i, i_past);
      cnt = 1;
    }
  }
  if (std::cin.fail() && !std::cin.eof())
  {
    exit_code = 1;
    return;
  }
  std::cout << cnt << "\n";
}

int main()
{
  int exit_code = 0;
  findCntMax(exit_code);

  if (exit_code == 1)
  {
    std::cerr << "Input data cannot be identified" << "\n";
    return 1;
  }
  else if (exit_code == 2)
  {
    return 2;
  }
  else
  {
    return 0;
  }
}
