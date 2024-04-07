#include "s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix& right) {
  S21Matrix result = S21Matrix(*this);
  result.SumMatrix(right);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& right) {
  S21Matrix result = S21Matrix(*this);
  result.SubMatrix(right);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& right) {
  S21Matrix result = S21Matrix(*this);
  result.MulMatrix(right);
  return result;
}

S21Matrix S21Matrix::operator*(const double right) {
  S21Matrix result = S21Matrix(*this);
  result.MulNumber(right);
  return result;
}

bool S21Matrix::operator==(const S21Matrix& right) { return EqMatrix(right); }

S21Matrix& S21Matrix::operator=(const S21Matrix& right) {
  if (this != &right) {
    freeMatrix();
    rows_ = right.rows_;
    cols_ = right.cols_;
    initMatrix(rows_, cols_);
    for (int i{}; i < rows_; i++) {
      for (int j{}; j < cols_; j++) {
        matrix_[i][j] = right.matrix_[i][j];
      }
    }
  }
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& right) {
  SumMatrix(right);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& right) {
  SubMatrix(right);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& right) {
  MulMatrix(right);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double right) {
  MulNumber(right);
  return *this;
}

double& S21Matrix::operator()(int i, int j) {
  if (i < 0 || j < 0 || i >= rows_ || j >= cols_)
    throw std::logic_error("Индекс за пределами матрицы.");
  return matrix_[i][j];
}
