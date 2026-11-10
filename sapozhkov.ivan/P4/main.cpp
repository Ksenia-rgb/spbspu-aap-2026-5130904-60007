#include <iostream>
#include <new>

namespace sapozhkov
{
  int hasSame(const char* a, const char* b);
  char* readLine(size_t& size);
}

int main()
{
  const char* const second = "abs";
  size_t size = 0;
  char* str = nullptr;
  try
  {
    str = sapozhkov::readLine(size);
  }
  catch (const std::bad_alloc&)
  {
    std::cerr << "Not enough memory" << '\n';
    return 1;
  }
  if (size == 0 && std::cin.eof())
  {
    delete[] str;
    std::cerr << "No input\n";
    return 1;
  }
  std::cout << sapozhkov::hasSame(str, second) << '\n';
  delete[] str;
}

int sapozhkov::hasSame(const char* a, const char* b)
{
  if (a == nullptr || b == nullptr)
  {
    return 0;
  }
  for (size_t i = 0; a[i] != '\0'; ++i)
  {
    for (size_t j = 0; b[j] != '\0'; ++j)
    {
      if (a[i] == b[j])
      {
        return 1;
      }
    }
  }
  return 0;
}

char* sapozhkov::readLine(size_t& size)
{
  size_t cap = 10;
  char* str = new char[cap];
  char c = 0;
  std::cin >> std::noskipws;
  while (std::cin >> c && c != '\n')
  {
    if (size + 1 == cap)
    {
      char* const bigger = new char[cap * 2];
      for (size_t i = 0; i < size; ++i)
      {
        bigger[i] = str[i];
      }
      delete[] str;
      str = bigger;
      cap *= 2;
    }
    str[size] = c;
    ++size;
  }
  str[size] = '\0';
  return str;
}
