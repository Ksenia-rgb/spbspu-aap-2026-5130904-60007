#include <iostream>
#include <cstddef>
#include <new>
#include <cctype>

char* readline(size_t* length)
{
  const size_t initial_capacity = 16;
  size_t capacity = initial_capacity;
  size_t size = 0;
  char* buf = new char[capacity];

  char c = 0;
  while (std::cin.get(c) && c != '\n') {
    if (size + 1 == capacity) {
      char* new_buf = nullptr;
      try {
        new_buf = new char[capacity * 2];
      } catch (const std::bad_alloc&) {
        delete[] buf;
        throw;
      }
      for (size_t i = 0; i < size; ++i) {
        new_buf[i] = buf[i];
      }
      delete[] buf;
      buf = new_buf;
      capacity *= 2;
    }
    buf[size] = c;
    ++size;
  }
  buf[size] = '\0';
  *length = size;
  return buf;
}

char* removeLatin(const char* src, char* dst) noexcept
{
  size_t j = 0;
  for (size_t i = 0; src[i] != '\0'; ++i) {
    if (!std::isalpha(static_cast< unsigned char >(src[i]))) {
      dst[j] = src[i];
      ++j;
    }
  }
  dst[j] = '\0';
  return dst;
}

int main()
{
  size_t len = 0;
  char* input = nullptr;
  try {
    input = readline(&len);
  } catch (const std::bad_alloc&) {
    std::cerr << "Not enough memory\n";
    return 1;
  }

  char* result = nullptr;
  try {
    result = new char[len + 1];
  } catch (const std::bad_alloc&) {
    delete[] input;
    std::cerr << "Not enough memory\n";
    return 1;
  }

  removeLatin(input, result);
  std::cout << result << "\n";

  delete[] result;
  delete[] input;
  return 0;
}
