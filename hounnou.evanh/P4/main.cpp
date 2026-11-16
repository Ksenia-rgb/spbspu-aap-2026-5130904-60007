#include <iostream>

namespace hounnou
{
  const int MAX_CHARS = 256;

  int hasRepeatingChars(const char* str)
  {
    bool seen[MAX_CHARS] = {false};

    for (int i = 0; str[i] != '\0'; ++i)
    {
      const unsigned char c = static_cast< unsigned char >(str[i]);
      if (seen[c])
      {
        return 1;
      }
      seen[c] = true;
    }

    return 0;
  }
}

int main()
{
  const int buffer_size = 10000;
  char input[buffer_size];

  if (!std::cin.getline(input, buffer_size))
  {
    std::cerr << "Input error" << '\n';
    return 1;
  }

  const int result = hounnou::hasRepeatingChars(input);
  std::cout << result << '\n';

  return 0;
}
