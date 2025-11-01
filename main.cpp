#include <iostream>
#include <new>

int **make(int rows, int cols);
void output(const int *const *mtx, int rows, int cols);
void rm(int **mtx, int rows);
void input(int **mtx, int rows, int cols);

int main() {
  int rows = 0, cols = 0;
  std::cin >> rows >> cols;
  if (std::cin.fail()) {
    return 1;
  }
  int **mtx = nullptr;
  try {
    mtx = make(rows, cols);
  } catch (const std::bad_alloc &) {
    return 2;
  }
  input(mtx, rows, cols);
  output(mtx, rows, cols);
  rm(mtx, rows);
}
void rm(int **mtx, int rows) {
  for (size_t i = 0; i < rows; ++i) {
    delete[] mtx[i];
  }
  delete[] mtx;
}
int **make(int rows, int columns) {
  int **mtx = new int *[rows];
  for (size_t i = 0; i < rows; i++) {
    try {
      mtx[i] = new int[columns];
    } catch (const std::bad_alloc &) {
      rm(mtx, rows);
      throw;
    }
  }
  return mtx;
}
void input(int **mtx, int rows, int cols) {
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      std::cin >> mtx[i][j];
    }
  }
}
void output(int **mtx, int rows, int cols) {
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      std::cout << mtx[i][j];
    }
    std::cout << "\n";
  }
}
