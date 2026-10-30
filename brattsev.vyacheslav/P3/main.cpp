#include <fstream>
#include <iostream>
#include <string>

namespace brattsev
{
  bool parse_num_arg(const std::string& arg, int& num)
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

  bool read_matrix(std::ifstream& fin, int* matrix, int rows, int cols)
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

  bool is_upper_triangular(const int* matrix, int rows, int cols)
  {
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

  void write_result(const std::string& filename, bool result)
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
  if (!brattsev::parse_num_arg(argv[1], num))
  {
    std::cerr << "error\n";
    return 1;
  }

  std::string input_file = argv[2];
  std::string output_file = argv[3];

  std::ifstream fin(input_file);
  if (!fin.is_open())
  {
    std::cerr << "error\n";
    return 2;
  }

  int rows = 0;
  int cols = 0;
  if (!(fin >> rows >> cols) || rows <= 0 || cols <= 0)
  {
    std::cerr << "error\n";
    return 2;
  }

  long long total_elements = static_cast<long long>(rows) * cols;
  if (total_elements > 2147483647)
  {
    std::cerr << "error\n";
    return 2;
  }

  if (num == 1 && total_elements > 10000)
  {
    std::cerr << "error\n";
    return 2;
  }

  int* matrix = nullptr;
  int stack_matrix[10000];

  if (num == 1)
  {
    matrix = stack_matrix;
  }
  else
  {
    matrix = new int[total_elements];
  }

  if (!brattsev::read_matrix(fin, matrix, rows, cols))
  {
    if (num == 2)
    {
      delete[] matrix;
    }
    std::cerr << "error\n";
    return 2;
  }

  bool is_upper = brattsev::is_upper_triangular(matrix, rows, cols);

  brattsev::write_result(output_file, is_upper);

  if (num == 2)
  {
    delete[] matrix;
  }

  return 0;
}