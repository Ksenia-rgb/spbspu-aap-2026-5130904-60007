#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP

#include <cstddef>

namespace chinikov
{
  constexpr const char* second_string = "def_ghk";
  char* inputString(size_t& buffer, char*& str);
  size_t string_size(const char* string);
  char* formatString(const char* first_string, const char* second_string, char* new_string);
}

#endif
