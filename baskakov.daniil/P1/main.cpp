#include <iostream>
#include <cstddef>

namespace baskakov {
  constexpr int err_no_data = 2;
  constexpr std::size_t window = 3;
  struct Result {
    int value;
    int status;
  };

  Result countLocalMin()
  {
    int prev = 0;
    int curr = 0;
    int next = 0;
    std::size_t total = 0;
    int cnt = 0;

    while (std::cin >> next && next != 0) {
      ++total;
      if (total >= window) {
        if (curr < next && curr < prev) {
          ++cnt;
        }
      }
      prev = curr;
      curr = next;
    }

    if (!std::cin) {
      return {0, 1};
    }

    if (total == 0) {
      return {0, err_no_data};
    }

    return {cnt, 0};
  }
}

int main()
{
  const baskakov::Result res = baskakov::countLocalMin();

  if (res.status == 1) {
    std::cerr << "Invalid input\n";
    return 1;
  }

  if (res.status == baskakov::err_no_data) {
    std::cerr << "No data\n";
    return baskakov::err_no_data;
  }

  std::cout << res.value << "\n";
  return 0;
}
