#ifndef CPP_S21_MATRIX_OOP_1
#define CPP_S21_MATRIX_OOP_1

#include <iostream>

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  S21Matrix operator+(const S21Matrix& right);
  S21Matrix operator-(const S21Matrix& right);
  S21Matrix operator*(const S21Matrix& right);
  S21Matrix operator*(const double right);
  bool operator==(const S21Matrix& right);
  S21Matrix& operator=(const S21Matrix& right);
  S21Matrix& operator+=(const S21Matrix& right);
  S21Matrix& operator-=(const S21Matrix& right);
  S21Matrix& operator*=(const S21Matrix& right);
  S21Matrix& operator*=(const double right);
  double& operator()(int i, int j);

  int GetRows();
  void SetRows(int rows);
  int GetCols();
  void SetCols(int cols);

 private:
  void initMatrix(int rows, int cols);
  void freeMatrix();
  S21Matrix GetMatrixForMinor(int row, int col);
};

#endif  // CPP_S21_MATRIX_OOP_1
