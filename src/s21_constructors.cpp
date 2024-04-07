#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  rows_ = cols_ = 1;
  initMatrix(1, 1);
}

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows < 1 || cols < 1)
    throw std::logic_error("Некорректный размер матрицы.");
  rows_ = rows;
  cols_ = cols;
  initMatrix(rows_, cols_);
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : S21Matrix(other.rows_, other.cols_) {
  for (int i{}; i < rows_; i++) {
    for (int j{}; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) : S21Matrix(other.rows_, other.cols_) {
  for (int i{}; i < rows_; i++) {
    for (int j{}; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
  other.freeMatrix();
  other.rows_ = other.cols_ = 0;
}
