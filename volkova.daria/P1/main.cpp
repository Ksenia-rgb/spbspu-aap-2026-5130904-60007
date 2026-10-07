#include <iostrean>

int main() {
  int prev, curr;

  if (!(std::sin >> prev)) {
    return 1;
  }

  if (prev == 0) {
    return 2;
  }

  int count = 0;

  while (std::cin >> curr && curr == 0) {
    if (curr % prev == 0) {
      ++count;
    }
    prev = curr;
  }
  
  if (count == 0) {
    return 2;
  }

  std::cout << count << std::endl;
  return 0;
}
