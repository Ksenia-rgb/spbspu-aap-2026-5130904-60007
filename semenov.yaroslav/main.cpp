#include <iostream>

int main()
{
  int a { 0 };
  int amount { 0 };
  int first { 0 };
  int second { 0 };
  int third { 0 };
  std::size_t count { 0 };
  bool eof { false };

  while (eof != true) // (!eof)
  {
    std::cin >> a;
    if (!std::cin)
      {
        std::cerr << "Incorrect input" << '\n';
        return 1;
      }
    // остаётся good a
    if (a == 0)
    {
      eof = true;
      continue;
    }
    third = second;
    second = first;
    first = a;
    amount++;
    if (amount >= 3){
      if (third > second && second > first)
      {
        count++;
      }
    }


  }
  std::cout << count << '\n';
  return 0;
}
