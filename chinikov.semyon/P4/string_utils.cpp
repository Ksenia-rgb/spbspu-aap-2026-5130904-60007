#include "string_utils.hpp"

#include <iostream>
#include <new>
#include <cctype>

namespace chinikov
{
  char* inputString(size_t& buffer, char*& str)
  {
    char ch = 0;
    size_t count = 0;
    while (std::cin.get(ch) && ch != '\n')
    {
      if (count >= buffer - 1)
      {
        buffer *= 2;
        char* new_str = new (std::nothrow) char[buffer];
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
    str[count] = '\0';
    return str;
  }

  size_t string_size(const char* string)
  {
    size_t size = 0;
    while (string[size] != '\0')
    {
      ++size;
    }
    return size;
  }

  char* formatString(const char* first_string, const char* second_string, char* new_string)
  {
    bool present[26] = {false};

    for (size_t i = 0; first_string[i] != '\0'; ++i)
    {
      unsigned char ch = static_cast< unsigned char >(first_string[i]);
      if (std::isalpha(ch))
      {
        char lower = static_cast< char >(std::tolower(ch));
        present[lower - 'a'] = true;
      }
    }

    for (size_t i = 0; second_string[i] != '\0'; ++i)
    {
      unsigned char ch = static_cast< unsigned char >(second_string[i]);
      if (std::isalpha(ch))
      {
        char lower = static_cast< char >(std::tolower(ch));
        present[lower - 'a'] = true;
      }
    }

    size_t pos = 0;
    for (int i = 0; i < 26; ++i)
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
