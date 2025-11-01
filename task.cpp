#include <iostream>

int **convert(const int *t, size_t n, const size_t *lns, size_t rows);
int **make(size_t rows, size_t cols);
void rm(int **mtx, int rows);
int main() {
  int t[] = {5, 5, 5, 5, 6, 6, 7, 7, 7, 7, 7, 8};
  size_t lns[] = {4, 2, 5, 1};
  size_t rows = 4;
  size_t n = 12;
}
void rm(int **mtx, int rows) {
  for (size_t i = 0; i < rows; ++i) {
    delete[] mtx[i];
  }
  delete[] mtx;
}

int **make(size_t rows, size_t *lns) {
  int **mtx = new int *[rows];
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < lns[rows]; ++j) {
      try {
        mtx[i] = new int[j];
      } catch (const std::bad_alloc &) {
        rm(mtx, rows);
        throw;
      }
    }
  }
  return mtx;
}

int **converts(const int *t, size_t n, const size_t *lns, size_t rows) {
  int **mtx = make(rows, *lns);
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < t[n]; j += lns[rows]) {
      for (int k = 0; k < lns[rows]; ++k) {
        mtx[rows][k] = t[k];
      }
    }
  }
  return mtx;
}
