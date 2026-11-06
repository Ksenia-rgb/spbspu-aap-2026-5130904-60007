#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
const int ARGC_EXACT = 4;
const int NUM_STATIC = 1;
const int NUM_DYNAMIC = 2;
const std::size_t MAX_NUMBER_OF_ELEMENTS = 10000;
bool readMatrix(std::ifstream &file, std::size_t rows, std::size_t cols,
                int *matrix) {
  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      file >> *(matrix + i * cols + j);
      if (!file) {
        return false;
      }
    }
  }
  return true;
}
void smoothMatrix(const int *matrix, std::size_t rows, std::size_t cols,
                  double *result) {
  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      double sum = 0.0;
      int count = 0;
      for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
          if (di == 0 && dj == 0)
            continue;

          const int ni = static_cast<int>(i) + di;
          const int nj = static_cast<int>(j) + dj;
          if (ni >= 0 && ni < static_cast<int>(rows) && nj >= 0 &&
              nj < static_cast<int>(cols)) {
            sum += matrix[ni * cols + nj];
            count++;
          }
        }
      }
      result[i * cols + j] = (count > 0) ? (sum / count) : 0.0;
    }
  }
}
void writeMatrix(std::ofstream &file, const double *matrix, std::size_t rows,
                 std::size_t cols) {
  file << rows << " " << cols << " ";
  file << std::fixed << std::setprecision(1);
  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      file << matrix[i * cols + j] << " ";
    }
  }
  file << "\n";
}
int main(int argc, char *argv[]) {
  if (argc < ARGC_EXACT) {
    std::cerr << "Not enough arguments" << '\n';
    return 1;
  } else if (argc > ARGC_EXACT) {
    std::cerr << "Too many arguments" << '\n';
    return 1;
  }
  std::string num_str = argv[1];
  int num{0};
  try {
    size_t pos = 0;
    num = std::stoi(num_str, &pos);
    if (pos != num_str.length()) {
      std::cerr << "First parameter is not a number" << '\n';
      return 1;
    }
  } catch (const std::exception &e) {
    std::cerr << "First parameter is not a number" << '\n';
    return 1;
  }
  if (num != NUM_STATIC && num != NUM_DYNAMIC) {
    std::cerr << "First parameter is out of range" << '\n';
    return 1;
  }
  std::ifstream ifs(argv[2]);
  if (!ifs) {
    std::cerr << "Input file not found" << '\n';
    return 1;
  }
  std::ofstream ofs(argv[3]);
  if (!ofs) {
    std::cerr << "Output file cannot be opened" << '\n';
    return 1;
  }
  std::size_t rows{0};
  ifs >> rows;
  if (!ifs) {
    std::cerr << "Input error in rows" << '\n';
    return 2;
  }
  std::size_t cols{0};
  ifs >> cols;
  if (!ifs) {
    std::cerr << "Input error in cols" << '\n';
    return 2;
  }
  if (num == NUM_STATIC && rows * cols > MAX_NUMBER_OF_ELEMENTS) {
    std::cerr << "Matrix exceeds 10000 elements for static array" << '\n';
    return 2;
  }
  int arr_static[MAX_NUMBER_OF_ELEMENTS]{0};
  double res_static[MAX_NUMBER_OF_ELEMENTS]{0.0};
  int *arr{nullptr};
  double *res{nullptr};
  if (num == NUM_STATIC) {
    arr = arr_static;
    res = res_static;
  } else {
    arr = new int[rows * cols];
    res = new double[rows * cols];
  }
  if (readMatrix(ifs, rows, cols, arr) == false) {
    if (num == NUM_DYNAMIC) {
      delete[] arr;
      delete[] res;
    }
    ifs.close();
    std::cerr << "Input error in data" << '\n';
    return 2;
  }
  ifs.close();

  smoothMatrix(arr, rows, cols, res);

  writeMatrix(ofs, res, rows, cols);
  ofs.close();
  if (num == NUM_DYNAMIC) {
    delete[] arr;
    delete[] res;
  }
  return 0;
}
