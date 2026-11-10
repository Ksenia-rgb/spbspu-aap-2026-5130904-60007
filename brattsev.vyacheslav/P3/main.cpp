#include <fstream>
#include <iostream>
#include <string>

namespace brattsev
{
  constexpr int MAX_ELEMENTS = 2147483647;
  constexpr int MAX_STACK_SIZE = 10000;

  bool parseNumArg(const std::string& arg, int& num)
  {
    if (arg == "1")
    {
      num = 1;
      return true;
    }
    if (arg == "2")
    {
      num = 2;
      return true;
    }
    return false;
  }

  bool readMatrix(std::ifstream& fin, int* matrix, int rows, int cols)
  {
    for (int i = 0; i < rows; ++i)
    {
      for (int j = 0; j < cols; ++j)
      {
        if (!(fin >> matrix[i * cols + j]))
        {
          return false;
        }
      }
    }
    return true;
  }

  bool isUpperTriangular(const int* matrix, int rows, int cols)
  {
    if (rows <= 0 || cols <= 0)
    {
      return false;
    }
    for (int i = 0; i < rows; ++i)
    {
      for (int j = 0; j < cols; ++j)
      {
        if (i > j && matrix[i * cols + j] != 0)
        {
          return false;
        }
      }
    }
    return true;
  }

  void writeResult(const std::string& filename, bool result)
  {
    std::ofstream fout(filename);
    if (fout.is_open())
    {
      if (result)
      {
        fout << "true\n";
      }
      else
      {
        fout << "false\n";
      }
    }
  }
}

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "error\n";
    return 1;
  }

  int num = 0;
  if (!brattsev::parseNumArg(argv[1], num))
  {
    std::cerr << "error\n";
    return 1;
  }

  const std::string input_file = argv[2];
  const std::string output_file = argv[3];

  std::ifstream fin(input_file);
  if (!fin.is_open())
  {
    std::cerr << "error\n";
    return 2;
  }

  int rows = 0;
  int cols = 0;
  if (!(fin >> rows >> cols))
  {
    std::cerr << "error\n";
    return 2;
  }

  const long long total_elements = 1LL * rows * cols;

  if (total_elements > brattsev::MAX_ELEMENTS)
  {
    std::cerr << "error\n";
    return 2;
  }

  if (num == 1 && total_elements > brattsev::MAX_STACK_SIZE)
  {
    std::cerr << "error\n";
    return 2;
  }

  int* matrix = nullptr;
  int stack_matrix[brattsev::MAX_STACK_SIZE];

  if (num == 1)
  {
    matrix = stack_matrix;
  }
  else
  {
    matrix = new int[total_elements];
  }

  if (!brattsev::readMatrix(fin, matrix, rows, cols))
  {
    if (num == 2)
    {
      delete[] matrix;
    }
    std::cerr << "error\n";
    return 2;
  }

  const bool is_upper = brattsev::isUpperTriangular(matrix, rows, cols);

  brattsev::writeResult(output_file, is_upper);

  if (num == 2)
  {
    delete[] matrix;
  }

  return 0;
}
