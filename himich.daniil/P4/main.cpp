#include <cctype>
#include <cstddef>
#include <iostream>
#include <new>

namespace himich {
  char* getFrequentTop(char* dest, const char* src) noexcept
  {
    if (dest == nullptr) {
      return dest;
    }
    if (src == nullptr) {
      dest[0] = '\0';
      return dest;
    }

    std::size_t counts[256] = {};
    bool chosen[256] = {};

    while (*src != '\0') {
      const unsigned char ch = static_cast<unsigned char>(*src);
      if (!std::isspace(ch)) {
        ++counts[ch];
      }
      ++src;
    }

    for (int k = 0; k < 3; ++k) {
      std::size_t max_count = 0;
      int best = -1;
      for (int i = 0; i < 256; ++i) {
        if (counts[i] > max_count) {
          max_count = counts[i];
          best = i;
        }
      }
      if (best == -1) {
        break;
      }
      chosen[best] = true;
      counts[best] = 0;
    }

    std::size_t size = 0;
    for (int i = 0; i < 256; ++i) {
      if (chosen[i]) {
        dest[size++] = static_cast<char>(i);
      }
    }
    dest[size] = '\0';

    return dest;
  }

  char* readLine(std::istream& in)
  {
    constexpr std::size_t initial_capacity = 16;
    std::size_t capacity = initial_capacity;
    std::size_t size = 0;
    char* buffer = new char[capacity];

    char ch = '\0';
    while (in.get(ch)) {
      if (ch == '\n') {
        break;
      }

      if (size + 1 >= capacity) {
        const std::size_t new_capacity = capacity * 2;
        char* new_buffer = nullptr;
        try {
          new_buffer = new char[new_capacity];
        } catch (...) {
          delete[] buffer;
          throw;
        }

        for (std::size_t i = 0; i < size; ++i) {
          new_buffer[i] = buffer[i];
        }

        delete[] buffer;
        buffer = new_buffer;
        capacity = new_capacity;
      }

      buffer[size++] = ch;
    }

    buffer[size] = '\0';
    return buffer;
  }
}

int main()
{
  char* input_str = nullptr;

  try {
    input_str = himich::readLine(std::cin);
  } catch (const std::bad_alloc&) {
    std::cerr << "Unable to allocate dynamic memory\n";
    return 1;
  }

  char result[4] = {};
  himich::getFrequentTop(result, input_str);

  std::cout << result << '\n';

  delete[] input_str;
  return 0;
}
