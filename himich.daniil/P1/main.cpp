#include <iostream>

int main()
{
  int number = 0;
  int max = 0;
  int count_after = 0;
  bool has_elements = false;

  while ((std::cin >> number) && (number != 0))
  {
    if (!has_elements || (number > max))
    {
      max = number;
      count_after = 0;
      has_elements = true;
    }
    else
    {
      count_after++;
    }
  }

  if (std::cin.fail())
  {
    std::cerr << "Invalid input\n";
    return 1;
  }

  if (!has_elements)
  {
    std::cerr << "Sequence is too short\n";
    return 2;
  }

  std::cout << count_after << '\n';
  return 0;
}
