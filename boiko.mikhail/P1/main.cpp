#include <iostream>
#define INCORRECT_INPUT 1
#define NOT_ENOUGH_DATA 2

int main()
{
  long long input{0};
  long long max{0};
  unsigned counter{0};

  while ((std::cin >> input) && (input != 0))
  {
    if (input < max)
    {
      ++counter;
    }
    if (max < input)
    {
      max = input;
      counter = 0;
    }
  }
  if (!std::cin)
  {
    std::cerr << "Incorrect input" << '\n';
    return INCORRECT_INPUT;
  }
  if (!max)
  {
    std::cerr << "Not enough data" << '\n';
    return NOT_ENOUGH_DATA;
  }
  std::cout << "Count:" << counter;
  return 0;
}
