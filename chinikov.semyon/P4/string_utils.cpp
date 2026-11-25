#include "string_utils.hpp"

#include <cctype>
#include <iostream>
#include <new>

namespace chinikov
{
  char* inputString(size_t& buffer, char*& str)
  {
    if (!str || buffer == 0)
    {
      return nullptr;
    }
    char ch = 0;
    size_t count = 0;
    while (std::cin.get(ch) && ch != '\n')
    {
      if (count >= buffer - 1)
      {
        buffer *= 2;
        char* const new_str = new (std::nothrow) char[buffer];
        if (!new_str)
        {
          delete[] str;
          str = nullptr;
          return nullptr;
        }
        for (size_t i = 0; i < count; ++i)
        {
          new_str[i] = str[i];
        }
        delete[] str;
        str = new_str;
      }
      str[count++] = ch;
    }

    if (count == 0 && !std::cin)
    {
      delete[] str;
      str = nullptr;
      return nullptr;
    }

    str[count] = '\0';
    return str;
  }

  size_t stringSize(const char* string)
  {
    if (!string)
    {
      return 0;
    }
    size_t size = 0;
    while (string[size] != '\0')
    {
      ++size;
    }
    return size;
  }

  char* formatString(const char* first_string, const char* second_string, char* new_string)
  {
    if (!first_string || !second_string || !new_string)
    {
      return nullptr;
    }
    constexpr size_t alphabet_size = 26;
    bool present[alphabet_size] = {false};

    for (size_t i = 0; first_string[i] != '\0'; ++i)
    {
      const unsigned char ch = static_cast< unsigned char >(first_string[i]);
      if (std::isalpha(ch))
      {
        const char lower = static_cast< char >(std::tolower(ch));
        present[lower - 'a'] = true;
      }
    }

    for (size_t i = 0; second_string[i] != '\0'; ++i)
    {
      const unsigned char ch = static_cast< unsigned char >(second_string[i]);
      if (std::isalpha(ch))
      {
        const char lower = static_cast< char >(std::tolower(ch));
        present[lower - 'a'] = true;
      }
    }

    size_t pos = 0;
    for (size_t i = 0; i < alphabet_size; ++i)
    {
      if (present[i])
      {
        new_string[pos++] = static_cast< char >('a' + i);
      }
    }
    new_string[pos] = '\0';

    return new_string;
  }
}
