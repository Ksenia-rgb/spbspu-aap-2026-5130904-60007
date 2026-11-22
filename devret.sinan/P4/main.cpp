#include <cctype>
#include <cstddef>
#include <iostream>
#include <new>

namespace devret
{
  const size_t top_count = 3;
  const size_t alphabet_size = 256;
  const size_t initial_capacity = 16;

  char *topFrequent(char *dest, const char *src)
  {
    size_t counts[alphabet_size] = {};
    for (const char *p = src; *p != '\0'; ++p)
    {
      const unsigned char symbol = static_cast< unsigned char >(*p);
      if (!std::isspace(symbol))
      {
        ++counts[symbol];
      }
    }

    bool chosen[alphabet_size] = {};
    for (size_t k = 0; k < top_count; ++k)
    {
      size_t best = 0;
      size_t best_count = 0;
      for (size_t i = 0; i < alphabet_size; ++i)
      {
        if (!chosen[i] && counts[i] > best_count)
        {
          best = i;
          best_count = counts[i];
        }
      }
      if (best_count > 0)
      {
        chosen[best] = true;
      }
    }

    size_t length = 0;
    for (size_t i = 0; i < alphabet_size; ++i)
    {
      if (chosen[i])
      {
        dest[length++] = static_cast< char >(i);
      }
    }
    dest[length] = '\0';
    return dest;
  }

  char *readLine(std::istream &in)
  {
    size_t capacity = initial_capacity;
    size_t length = 0;
    char *buffer = new (std::nothrow) char[capacity];
    if (buffer == nullptr)
    {
      return nullptr;
    }

    char symbol = '\0';
    while (in.get(symbol) && symbol != '\n')
    {
      if (length + 1 == capacity)
      {
        char *const bigger = new (std::nothrow) char[capacity * 2];
        if (bigger == nullptr)
        {
          delete[] buffer;
          return nullptr;
        }
        for (size_t i = 0; i < length; ++i)
        {
          bigger[i] = buffer[i];
        }
        delete[] buffer;
        buffer = bigger;
        capacity *= 2;
      }
      buffer[length++] = symbol;
    }
    buffer[length] = '\0';
    return buffer;
  }
}

int main()
{
  std::cin.peek();
  if (std::cin.eof())
  {
    std::cerr << "Error: empty input\n";
    return 1;
  }

  char *const line = devret::readLine(std::cin);
  if (line == nullptr)
  {
    std::cerr << "Error: not enough memory\n";
    return 1;
  }

  char *const result = new (std::nothrow) char[devret::top_count + 1];
  if (result == nullptr)
  {
    delete[] line;
    std::cerr << "Error: not enough memory\n";
    return 1;
  }

  devret::topFrequent(result, line);
  std::cout << result << "\n";

  delete[] result;
  delete[] line;
  return 0;
}
