#include <cctype>
#include <iostream>
#include <new>

namespace digits
{
  int hasRepeatingDigits(const char *str);
}

int main()
{
  const int INITIAL_CAPACITY = 16;
  int cap = INITIAL_CAPACITY;
  char *buffer = new (std::nothrow) char[cap];
  if (buffer == nullptr)
  {
    std::cerr << "Out of memory!" << '\n';
    return 1;
  }
  int k = 0;
  char g{};
  while (std::cin.get(g) && g != '\n')
  {
    if (k == cap - 1)
    {
      cap *= 2;
      char *const new_buffer = new (std::nothrow) char[cap];
      if (new_buffer == nullptr)
      {
        std::cerr << "Out of memory!" << '\n';
        delete[] buffer;
        return 1;
      }
      for (int i = 0; i < k; i++)
      {
        new_buffer[i] = buffer[i];
      }
      delete[] buffer;
      buffer = new_buffer;
    }
    buffer[k] = g;
    k++;
  }
  if (k == 0)
  {
    std::cerr << "Empty input!" << '\n';
    delete[] buffer;
    return 1;
  }
  buffer[k] = '\0';
  std::cout << digits::hasRepeatingDigits(buffer) << '\n';
  delete[] buffer;
  return 0;
}

int digits::hasRepeatingDigits(const char *str)
{
  if (str == nullptr)
  {
    std::cerr << "Null pointer!" << '\n';
    return 0;
  }
  int blok[10]{};
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (std::isdigit(str[i]))
    {
      const int d = str[i] - '0';
      if (blok[d])
      {
        return 1;
      }
      blok[d] = 1;
    }
  }
  return 0;
}
