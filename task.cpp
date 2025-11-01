#include <iostream>

int **convert(const int *t, size_t n, const size_t *lns, size_t rows);
int **make(size_t rows, const size_t *lns);
void rm(int **mtx, size_t rows);
void output(const int *const *mtx, size_t rows, const size_t *lns);
int main() {
  int t[] = {5, 5, 5, 5, 6, 6, 7, 7, 7, 7, 7, 8};
  size_t lns[] = {4, 2, 5, 1};
  size_t rows = 4;
  size_t n = 12;
  int **mtx = convert(t, n, lns, rows);
  output(mtx, rows, lns);
  rm(mtx, rows);
}
void rm(int **mtx, size_t rows) {
  for (size_t i = 0; i < rows; ++i) {
    delete[] mtx[i];
  }
  delete[] mtx;
}

int **make(size_t rows, const size_t *lns) {
  int **mtx = new int *[rows];
  for (size_t i = 0; i < rows; i++) {
    try {
      mtx[i] = new int[lns[i]];
    } catch (const std::bad_alloc &) {
      rm(mtx, rows);
      throw;
    }
  }
  return mtx;
}

int **convert(const int *t, size_t n, const size_t *lns, size_t rows) {
  int **mtx = make(rows, lns);
  size_t index = 0;
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < lns[i]; ++j) {
      mtx[i][j] = t[index++];
    }
  }
  return mtx;
}

void output(const int *const *mtx, size_t rows, const size_t *lns) {
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < lns[i]; j++) {
      std::cout << mtx[i][j];
    }
    std::cout << "\n";
  }
}
