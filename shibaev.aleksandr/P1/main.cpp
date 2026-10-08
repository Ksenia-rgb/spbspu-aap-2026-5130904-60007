#include <cstddef>
#include <iostream>

namespace shibaev {
int signChanges() {
  int a = {0};
  char last_sign = {'?'};
  char sign = {' '};
  std::size_t max_count = {0};
  bool eof = {false};

  while (eof == false) {
    std::cin >> a;
    if (!std::cin) {
      std::cerr << "Incorrect input" << '\n';
      return 1;
    } else if (a == 0) {
      eof = true;
      continue;
    }

    if (a < 0) {
      sign = '-';
    } else {
      sign = '+';
    }

    if (last_sign == sign) {
      continue;
    } else if (last_sign == '?') {
      last_sign = sign;
      continue;
    } else {
      max_count++;
    }
    last_sign = sign;
  }

  std::cout << max_count << '\n';
  return 0;
}
} // namespace shibaev

int main() { return shibaev::signChanges(); }
