#include <iostream>
#include <cstddef>

int main()
{
  int current{0};
  std::size_t count{0};
  std::size_t count_num{0};

  while ((std::cin >> current) && (current != 0)) {
    if (current % 2 == 0) {
      count += 1;
      if (count > count_num) {
        count_num = count;
      }
    } else {
      if (count > count_num) {
        count_num = count;
      }
      count = 0;
    }
  }

  if (std::cin.fail() && !std::cin.eof()) {
    std::cerr << "Incorrect data" << "\n";
    std::cin.clear();
    return 1;
  }

  if (count > count_num) {
    count_num = count;
  }

  std::cout << count_num << "\n";
  return 0;
}
