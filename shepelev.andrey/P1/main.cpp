#include <iostream>

int main()
{
  const int startLength = 1;

  int number = 0;
  int previous = 0;
  int currentLength = 0;
  int maxLength = 0;

  while ((std::cin >> number) && (number != 0))
  {
    if ((currentLength > 0) && (number >= previous))
    {
      currentLength++;
    }
    else
    {
      currentLength = startLength;
    }

    if (currentLength > maxLength)
    {
      maxLength = currentLength;
    }

    previous = number;
  }

  if (std::cin.fail() && !std::cin.eof())
  {
    std::cerr << "Invalid input\n";
    return 1;
  }

  std::cout << maxLength << '\n';
  return 0;
}
