#include "s21_matrix_oop.h"

int S21Matrix::GetRows() { return rows_; }

int S21Matrix::GetCols() { return cols_; }

void S21Matrix::SetRows(int rows) {
  if (rows < 1) throw std::logic_error("Кол-во строк не может быть меньше 1");
  if (rows_ != rows) {
    S21Matrix tmp(*this);
    freeMatrix();
    rows_ = rows;
    initMatrix(rows_, cols_);
    for (int i{}; i < rows_; i++) {
      for (int j{}; j < cols_; j++) {
        if (i < tmp.rows_) {
          matrix_[i][j] = tmp(i, j);
        } else {
          matrix_[i][j] = 0;
        }
      }
    }
  }
}

void S21Matrix::SetCols(int cols) {
  if (cols < 1)
    throw std::logic_error("Кол-во столбцов не может быть меньше 1");
  if (cols_ != cols) {
    S21Matrix tmp(*this);
    freeMatrix();
    cols_ = cols;
    initMatrix(rows_, cols_);
    for (int i{}; i < rows_; i++) {
      for (int j{}; j < cols_; j++) {
        if (j < tmp.cols_) {
          matrix_[i][j] = tmp.matrix_[i][j];
        } else {
          matrix_[i][j] = 0.;
        }
      }
    }
  }
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool result = true;
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    result = false;
  }
  for (int i{}; (i < rows_) && result; i++) {
    for (int j{}; (j < cols_) && result; j++) {
      if (matrix_[i][j] - other.matrix_[i][j] > 1e-7) {
        result = false;
      }
    }
  }
  return result;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::logic_error("Размеры матриц отличаются.");
  for (int i{}; i < rows_; i++) {
    for (int j{}; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::logic_error("Размеры матриц отличаются.");
  for (int i{}; i < rows_; i++) {
    for (int j{}; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i{}; i < rows_; i++) {
    for (int j{}; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_)
    throw std::logic_error(
        "Кол-во столбцов 1й матрицы не равно кол-ву строк 2й матрицы");
  S21Matrix tmp{rows_, other.cols_};
  for (int i{}; i < rows_; i++) {
    for (int j{}; j < other.cols_; j++) {
      double elem = 0.;
      for (int k{}; k < cols_; k++) {
        elem += matrix_[i][k] * other.matrix_[k][j];
      }
      tmp.matrix_[i][j] = elem;
    }
  }
  freeMatrix();
  rows_ = tmp.rows_;
  cols_ = tmp.cols_;
  initMatrix(rows_, cols_);
  for (int i{}; i < rows_; i++) {
    for (int j{}; j < cols_; j++) {
      matrix_[i][j] = tmp.matrix_[i][j];
    }
  }
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix tmp{cols_, rows_};
  for (int i{}; i < rows_; i++) {
    for (int j{}; j < cols_; j++) {
      tmp.matrix_[j][i] = matrix_[i][j];
    }
  }
  return tmp;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) throw std::logic_error("Матрица не является квадратной.");
  S21Matrix tmp{rows_, cols_};
  for (int i{}; i < rows_; i++) {
    for (int j{}; j < cols_; j++) {
      double minor = GetMatrixForMinor(i, j).Determinant();
      bool SumIsEven = ((i + j) % 2) == 0;
      tmp.matrix_[i][j] = (SumIsEven) ? minor : -minor;
    }
  }
  return tmp;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) throw std::logic_error("Матрица не является квадратной.");
  double result = 0;
  if (rows_ == 1) {
    result = matrix_[0][0];
  } else if (rows_ == 2) {
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    int degree = 1;
    for (int j{}; j < cols_; j++) {
      S21Matrix minor = GetMatrixForMinor(0, j);
      result += degree * matrix_[0][j] * minor.Determinant();
      degree *= -1;
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  double det = Determinant();
  if (det == 0) throw std::logic_error("Определитель матрицы равен 0.");
  S21Matrix tmp = CalcComplements().Transpose();
  for (int i{}; i < rows_; i++) {
    for (int j{}; j < cols_; j++) {
      tmp.matrix_[i][j] *= (1 / det);
    }
  }
  return tmp;
}

void S21Matrix::initMatrix(int rows, int cols) {
  double** matrix = new double*[rows];
  for (int i{}; i < rows; i++) {
    matrix[i] = new double[cols]{};
  }
  matrix_ = matrix;
}

void S21Matrix::freeMatrix() {
  if (matrix_) {
    for (int i{}; i < rows_; i++) {
      if (matrix_[i]) {
        delete[] matrix_[i];
        matrix_[i] = nullptr;
      }
    }
    delete[] matrix_;
    matrix_ = nullptr;
  }
}

S21Matrix S21Matrix::GetMatrixForMinor(int row, int col) {
  S21Matrix tmp{rows_ - 1, cols_ - 1};
  for (int tmp_i{}, i{}; i < rows_; i++) {
    for (int tmp_j{}, j{}; j < cols_; j++) {
      if (i != row && j != col) {
        tmp.matrix_[tmp_i][tmp_j] = matrix_[i][j];
        tmp_j++;
      }
    }
    if (i != row) tmp_i++;
  }
  return tmp;
}
