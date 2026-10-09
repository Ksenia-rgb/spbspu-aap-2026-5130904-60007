#include <iostream>

struct SequenceTracker
{
  int first_max;
  int second_max;
  bool has_first;
  bool has_second;

  SequenceTracker():
    first_max(0),
    second_max(0),
    has_first(false),
    has_second(false)
  {}

  void process(int value)
  {
    if (!has_first)
    {
      first_max = value;
      has_first = true;
      return;
    }

    if (value > first_max)
    {
      second_max = first_max;
      first_max = value;
      has_second = true;
    }
    else if (!has_second || value > second_max)
    {
      second_max = value;
      has_second = true;
    }
  }

  bool canCalculate() const
  {
    return has_second;
  }

  int getResult() const
  {
    return second_max;
  }
};

int main()
{
  int value = 0;
  SequenceTracker tracker;

  while (std::cin >> value)
  {
    if (value == 0)
    {
      break;
    }
    tracker.process(value);
  }

  if (!std::cin)
  {
    std::cerr << "Invalid input data\n";
    return 1;
  }

  if (!tracker.canCalculate())
  {
    std::cerr << "Sequence is too short\n";
    return 2;
  }

  std::cout << tracker.getResult() << "\n";
  return 0;
}

