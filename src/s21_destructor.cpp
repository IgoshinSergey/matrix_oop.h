#include "s21_matrix_oop.h"

S21Matrix::~S21Matrix() {
  freeMatrix();
  rows_ = cols_ = 0;
}
