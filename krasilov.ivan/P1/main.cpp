#include <cerrno>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

bool parseInt(const std::string & s, int & out)
{
  errno = 0;
  char * end = nullptr;
  long value = std::strtol(s.c_str(), &end, 10);
  if (end == s.c_str() || *end != '\0' || errno == ERANGE)
  {
    return false;
  }
  if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
  {
    return false;
  }
  out = static_cast<int>(value);
  return true;
}

int main()
{
  int prev = 0;
  bool havePrev = false;
  unsigned long long count = 0;
  bool overflow = false;

  std::string token;
  while (true)
  {
    if (!(std::cin >> token))
    {
      std::cerr << "Error: sequence is not terminated by zero\n";
      return 1;
    }
    int cur = 0;
    if (!parseInt(token, cur))
    {
      std::cerr << "Error: input is not a valid sequence of integers\n";
      return 1;
    }
    if (cur == 0)
    {
      break;
    }
    if (havePrev && cur > prev)
    {
      if (count == std::numeric_limits<unsigned long long>::max())
      {
        overflow = true;
      }
      else
      {
        ++count;
      }
    }
    prev = cur;
    havePrev = true;
  }
  if (overflow)
  {
    std::cerr << "Error: sequence is too long, counter overflow\n";
    return 2;
  }
  std::cout << count << '\n';
  return 0;
}
