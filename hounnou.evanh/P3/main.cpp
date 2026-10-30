#include <iostream>
#include <fstream>
#include <cstring>

namespace hounnou {
  int processMatrix(int argc, char* argv[])
  {
    if (argc != 4)
    {
      std::cerr << "Invalid number of arguments" << '\n';
      return 1;
    }

    int num{0};
    if (std::strcmp(argv[1], "1") == 0)
    {
      num = 1;
    }
    else if (std::strcmp(argv[1], "2") == 0)
    {
      num = 2;
    }
    else
    {
      std::cerr << "First argument must be 1 or 2" << '\n';
      return 1;
    }

    std::ifstream in(argv[2]);
    if (!in)
    {
      std::cerr << "Cannot open input file" << '\n';
      return 2;
    }

    int rows{0};
    int cols{0};
    if (!(in >> rows >> cols) || rows < 0 || cols < 0)
    {
      std::cerr << "Cannot read matrix size" << '\n';
      return 2;
    }

    std::ofstream out(argv[3]);
    if (!out)
    {
      std::cerr << "Cannot open output file" << '\n';
      return 2;
    }

    if (rows == 0 || cols == 0)
    {
      out << 0 << '\n';
      return 0;
    }

    int* matrix{nullptr};
    int fixed_matrix[10000];

    if (num == 1)
    {
      if (rows * cols > 10000)
      {
        std::cerr << "Matrix too large for fixed size" << '\n';
        return 2;
      }
      matrix = fixed_matrix;
    }
    else
    {
      matrix = new int[rows * cols];
    }

    for (int i = 0; i < rows * cols; ++i)
    {
      if (!(in >> matrix[i]))
      {
        if (num == 2)
        {
          delete[] matrix;
        }
        std::cerr << "Invalid matrix data" << '\n';
        return 2;
      }
    }

    int best_row{1};
    int max_len{0};

    for (int r = 0; r < rows; ++r)
    {
      int row_max{1};
      int current_len{1};
      for (int c = 1; c < cols; ++c)
      {
        if (matrix[r * cols + c] == matrix[r * cols + c - 1])
        {
          ++current_len;
        }
        else
        {
          if (current_len > row_max)
          {
            row_max = current_len;
          }
          current_len = 1;
        }
      }
      if (current_len > row_max)
      {
        row_max = current_len;
      }

      if (row_max > max_len)
      {
        max_len = row_max;
        best_row = r + 1;
      }
    }

    if (num == 2)
    {
      delete[] matrix;
    }

    out << best_row << '\n';
    return 0;
  }
}

int main(int argc, char* argv[])
{
  return hounnou::processMatrix(argc, argv);
}
