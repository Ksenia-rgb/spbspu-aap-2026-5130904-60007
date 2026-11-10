#include <iostream>
#include <new>

namespace baskakov {
  char* replaceSymbol(char* dest, const char* src, char old_char, char new_char) noexcept
  {
    if (dest == nullptr || src == nullptr) {
      return dest;
    }

    char* target = dest;
    while (*src != '\0') {
      if (*src == old_char) {
        *target = new_char;
      } else {
        *target = *src;
      }
      ++src;
      ++target;
    }
    *target = '\0';

    return dest;
  }

  size_t getLength(const char* str) noexcept
  {
    if (str == nullptr) {
      return 0;
    }
    size_t length = 0;
    while (str[length] != '\0') {
      ++length;
    }
    return length;
  }

  char* readLine(std::istream& in)
  {
    constexpr size_t initial_capacity = 16;
    size_t capacity = initial_capacity;
    size_t size = 0;
    char* buffer = new char[capacity];

    char ch = '\0';
    while (in.get(ch)) {
      if (ch == '\n') {
        break;
      }

      if (size + 1 >= capacity) {
        const size_t new_capacity = capacity * 2;
        char* new_buffer = nullptr;
        try {
          new_buffer = new char[new_capacity];
        } catch (...) {
          delete[] buffer;
          throw;
        }

        for (size_t i = 0; i < size; ++i) {
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
  const char target_char = 'c';
  const char replacement_char = 'b';

  char* input_str = nullptr;
  char* result_str = nullptr;

  try {
    input_str = baskakov::readLine(std::cin);

    if (input_str[0] == '\0') {
      delete[] input_str;
      std::cerr << "Empty input\n";
      return 1;
    }

    const size_t length = baskakov::getLength(input_str);
    result_str = new char[length + 1];

    baskakov::replaceSymbol(result_str, input_str, target_char, replacement_char);

    std::cout << result_str << '\n';

    delete[] input_str;
    delete[] result_str;
    return 0;
  } catch (const std::bad_alloc&) {
    delete[] input_str;
    delete[] result_str;
    std::cerr << "Unable to allocate dynamic memory\n";
    return 1;
  }
}
