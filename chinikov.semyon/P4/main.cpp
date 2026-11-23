#include "string_utils.hpp"

#include <iostream>
#include <new>

int main()
{
  size_t buffer = 1024;
  char* string = new (std::nothrow) char[buffer];
  if (!string)
  {
    std::cerr << "Unable to allocate dynamic memory\n";
    return 1;
  }

  if (!chinikov::inputString(buffer, string))
  {
    std::cerr << "Unable to allocate dynamic memory\n";
    return 1;
  }

  constexpr size_t max_alphabet_size = 27;
  char* new_string = new (std::nothrow) char[max_alphabet_size];
  if (!new_string)
  {
    delete[] string;
    std::cerr << "Unable to allocate memory\n";
    return 1;
  }

  std::cout << chinikov::formatString(string, chinikov::second_string, new_string) << '\n';

  delete[] string;
  delete[] new_string;
  return 0;
}
