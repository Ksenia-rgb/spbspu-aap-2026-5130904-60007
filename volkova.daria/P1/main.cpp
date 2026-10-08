#include <iostream>

int main()
{
  const int k_special_exit_code = 2;
  int prev = 0;
  int curr = 0;

  while (std::cin >> curr && curr != 0) {
    if (prev != 0 && curr % prev == 0) {
      ++count;
    }
    prev = curr;
  }

  if (count == 0) {
    return k_special_exit_code;
  }

  std::cout << count << std::endl;
  return 0;
}
