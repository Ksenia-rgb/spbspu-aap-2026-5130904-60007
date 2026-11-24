#include <cstring>
#include <iostream>

namespace brattsev
{
  int countDistinctLatin(const char* str)
  {
    int counts[26] = {0};
    int result = 0;

    for (int i = 0; str[i] != '\0'; ++i)
    {
      char c = str[i];
      if (c >= 'a' && c <= 'z')
      {
        int index = c - 'a';
        if (counts[index] == 0)
        {
          counts[index] = 1;
          result++;
        }
      }
      else if (c >= 'A' && c <= 'Z')
      {
        int index = c - 'A';
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
  int capacity = 16;
  int length = 0;
  char* buffer = new char[capacity];

  char c;
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

  int result = brattsev::countDistinctLatin(buffer);

  std::cout << result << "\n";

  delete[] buffer;
  return 0;
}
