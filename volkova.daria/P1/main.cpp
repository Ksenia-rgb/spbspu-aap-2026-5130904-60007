#include <iostream>

int main() {
  const int kSpecialExitCode = 2;
  int prev = 0;
  int curr = 0;

  if (!(std::cin >> prev)) {
    return 1;
  }

  if (prev == 0) {
    return kSpecialExitCode;
  }

  int count = 0;

  while (std::cin >> curr && curr != 0) {
    if (curr % prev == 0) {
      ++count;
    }
    prev = curr;
  }

  if (count == 0) {
    return kSpecialExitCode;
  }

  std::cout << count << std::endl;
  return 0;
}
