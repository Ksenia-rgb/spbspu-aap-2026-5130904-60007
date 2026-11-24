#include <cstring>
#include <iostream>

namespace brattsev
{
  constexpr int INITIAL_CAPACITY = 16;
  constexpr int ALPHABET_SIZE = 26;

  int countDistinctLatin(const char* str)
  {
    int counts[ALPHABET_SIZE] = {0};
    int result = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
      const char c = str[i];
      if (c >= 'a' && c <= 'z')
      {
        const int index = c - 'a';
        if (counts[index] == 0)
        {
          counts[index] = 1;
          result++;
        }
      }
      else if (c >= 'A' && c <= 'Z')
      {
        const int index = c - 'A';
        if (counts[index] == 0)
        {
          counts[index] = 1;
          result++;
        }
      }
    }
    return result;
  }
}

int main()
{
  int capacity = brattsev::INITIAL_CAPACITY;
  int length = 0;
  char* buffer = new char[capacity];
  char c = 0;
  while (std::cin.get(c) && c != '\n')
  {
    if (length + 1 >= capacity)
    {
      capacity *= 2;
      char* new_buffer = new char[capacity];
      for (int i = 0; i < length; ++i)
      {
        new_buffer[i] = buffer[i];
      }
      delete[] buffer;
      buffer = new_buffer;
    }
    buffer[length] = c;
    length++;
  }
  buffer[length] = '\0';
  const int result = brattsev::countDistinctLatin(buffer);
  std::cout << result << "\n";
  delete[] buffer;
  return 0;
}
