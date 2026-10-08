#include <iostream>

unsigned maxNumberCounter();
int main()
{
  try {
    unsigned _res = maxNumberCounter();
    std::cout << _res << "\n";
    return 0;
  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << "\n";
    return 1;
  } catch (const std::length_error &e) {
    std::cerr << e.what() << "\n";
    std::clog << "можно было написать класс от std::logic_error и типы ошибок "
                 "на основе содержания, но это бы избыточно для таких масштабов"
              << "\n";
    return 2;
  }
}
unsigned maxNumberCounter()
{
  long long max{0LL};
  long long input{0LL};
  unsigned counter{0U};

  while ((std::cin >> input) && (input != 0)) {
    if (input < max) {
      ++counter;
    }
    if (max < input) {
      max = input;
      counter = 0;
    }
  }
  if (!std::cin) {
    throw std::invalid_argument("Incorrect input");
  }
  if (!max) {
    throw std::length_error("Not enought data");
  }
  return counter;
}
