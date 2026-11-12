#include <cstddef>
#include <cstring>
#include <iostream>
#include <new>

namespace kugushev {
  constexpr std::size_t capacity = 16;
  constexpr std::size_t coef = 2;
  constexpr int memerr = 1;
  constexpr int inputerr = 2;
  char* readline(std::size_t& length);
  char* uniteTwo(const char* a, const char* b, char* res) noexcept;
}

int main()
{
  const char* const second = "def ";

  std::size_t len = 0;
  char* input = nullptr;
  try {
    input = kugushev::readline(len);
  } catch (const std::bad_alloc&) {
    std::cerr << "Not enough memory\n";
    return kugushev::memerr;
  }

  if (len == 0) {
    delete[] input;
    std::cerr << "Empty input\n";
    return kugushev::inputerr;
  }

  char* result = nullptr;
  try {
    result = new char[len + std::strlen(second) + 1];
  } catch (const std::bad_alloc&) {
    delete[] input;
    std::cerr << "Not enough memory\n";
    return kugushev::memerr;
  }

  kugushev::uniteTwo(input, second, result);
  std::cout << result << "\n";

  delete[] result;
  delete[] input;
  return 0;
}

char* kugushev::readline(std::size_t& length)
{
  std::size_t cap = capacity;
  std::size_t size = 0;
  char* buf = new char[cap];

  char c = 0;
  while (std::cin.get(c) && c != '\n') {
    if (size + 1 == cap) {
      char* bigger = nullptr;
      try {
        bigger = new char[cap * coef];
      } catch (const std::bad_alloc&) {
        delete[] buf;
        throw;
      }
      for (std::size_t i = 0; i < size; ++i) {
        bigger[i] = buf[i];
      }
      delete[] buf;
      buf = bigger;
      cap = cap * coef;
    }
    buf[size] = c;
    size = size + 1;
  }
  buf[size] = '\0';
  length = size;
  return buf;
}

char* kugushev::uniteTwo(const char* a, const char* b, char* res) noexcept
{
  std::size_t i = 0;
  std::size_t j = 0;
  std::size_t k = 0;
  while (a[i] != '\0' || b[j] != '\0') {
    if (a[i] != '\0') {
      res[k] = a[i];
      k = k + 1;
      i = i + 1;
    }
    if (b[j] != '\0') {
      res[k] = b[j];
      k = k + 1;
      j = j + 1;
    }
  }
  res[k] = '\0';
  return res;
}
