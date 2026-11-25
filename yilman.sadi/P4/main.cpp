#include <cstddef>
#include <cstring>
#include <iostream>
#include <new>

namespace yilman {
  constexpr std::size_t initial_capacity = 16;
  constexpr std::size_t growth_factor = 2;

  char *readLine(std::istream &in);
  char *excludeSecond(char *dst, const char *src, const char *excluded) noexcept;
}

char *yilman::readLine(std::istream &in)
{
  std::size_t capacity = initial_capacity;
  std::size_t size = 0;
  char *buffer = new (std::nothrow) char[capacity];
  if (buffer == nullptr) {
    return nullptr;
  }
  char ch = '\0';
  while (in.get(ch) && ch != '\n') {
    if (size + 1 >= capacity) {
      const std::size_t new_capacity = capacity * growth_factor;
      char *const bigger = new (std::nothrow) char[new_capacity];
      if (bigger == nullptr) {
        delete[] buffer;
        return nullptr;
      }
      for (std::size_t i = 0; i < size; ++i) {
        bigger[i] = buffer[i];
      }
      delete[] buffer;
      buffer = bigger;
      capacity = new_capacity;
    }
    buffer[size] = ch;
    ++size;
  }
  buffer[size] = '\0';
  return buffer;
}

char *yilman::excludeSecond(char *dst, const char *src, const char *excluded) noexcept
{
  if (dst == nullptr || src == nullptr || excluded == nullptr) {
    return dst;
  }
  std::size_t j = 0;
  for (std::size_t i = 0; src[i] != '\0'; ++i) {
    if (std::strchr(excluded, src[i]) == nullptr) {
      dst[j] = src[i];
      ++j;
    }
  }
  dst[j] = '\0';
  return dst;
}

int main()
{
  const char *const second = "abc";

  char *const source = yilman::readLine(std::cin);
  if (source == nullptr) {
    std::cerr << "Error: cannot allocate memory for input string\n";
    return 1;
  }

  char *const result = new (std::nothrow) char[std::strlen(source) + 1];
  if (result == nullptr) {
    delete[] source;
    std::cerr << "Error: cannot allocate memory for result string\n";
    return 1;
  }

  yilman::excludeSecond(result, source, second);
  std::cout << result << "\n";

  delete[] result;
  delete[] source;
  return 0;
}
