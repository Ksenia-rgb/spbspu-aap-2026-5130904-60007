#include <iostream>

int main()
{
  const int start_length = 1;

  int number = 0;
  int previous = 0;
  int current_length = 0;
  int max_length = 0;

  while ((std::cin >> number) && (number != 0))
  {
    if ((current_length > 0) && (number >= previous))
    {
      current_length++;
    }
    else
    {
      current_length = start_length;
    }

    if (current_length > max_length)
    {
      max_length = current_length;
    }

    previous = number;
  }

  if (std::cin.fail() && !std::cin.eof())
  {
    std::cerr << "Invalid input\n";
    return 1;
  }

  std::cout << max_length << '\n';
  return 0;
}
