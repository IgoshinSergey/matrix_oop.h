#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(EqMatrix, Test_normal_1) {
  S21Matrix m1(3, 3), m2(3, 3);
  EXPECT_EQ(true, m1.EqMatrix(m2));
  m1(0, 0) = 1;
  EXPECT_EQ(false, m1.EqMatrix(m2));
}

TEST(EqMatrix, Test_normal_2) {
  S21Matrix m1(3, 3), m2(3, 3);
  for (int i{}; i < 3; i++) {
    for (int j{}; j < 3; j++) {
      m1(i, j) = i * j;
      m2(i, j) = i * j;
    }
  }
  EXPECT_EQ(true, m1.EqMatrix(m2));
  m1(0, 0) = 1;
  EXPECT_EQ(false, m1.EqMatrix(m2));
}

TEST(EqMatrix, Test_normal_3) {
  S21Matrix m1(3, 2), m2(2, 3);
  EXPECT_EQ(false, m1.EqMatrix(m2));
}

TEST(SumMatrix, Test_normal_1) {
  S21Matrix m1(4, 4), m2(4, 4);
  for (int i{}; i < 4; i++) {
    for (int j{}; j < 4; j++) {
      m2(i, j) = i * j;
    }
  }
  m1.SumMatrix(m2);
  for (int i{}; i < 4; i++) {
    for (int j{}; j < 4; j++) {
      EXPECT_EQ(m1(i, j), i * j);
    }
  }
}

TEST(SumMatrix, Test_normal_2) {
  S21Matrix m1(3, 3), m2(3, 3);
  for (int i{}; i < 3; i++) {
    for (int j{}; j < 3; j++) {
      m1(i, j) = i;
      m2(i, j) = j;
    }
  }
  m1.SumMatrix(m2);
  for (int i{}; i < 3; i++) {
    for (int j{}; j < 3; j++) {
      EXPECT_EQ(m1(i, j), i + j);
    }
  }
}

TEST(SumMatrix, Test_error) {
  S21Matrix m1(3, 4), m2(4, 4);
  EXPECT_THROW(m1.SumMatrix(m2), std::logic_error);
}

TEST(SubMatrix, Test_normal_1) {
  S21Matrix m1(4, 4), m2(4, 4);
  for (int i{}; i < 4; i++) {
    for (int j{}; j < 4; j++) {
      m2(i, j) = i * j;
    }
  }
  m1.SubMatrix(m2);
  for (int i{}; i < 4; i++) {
    for (int j{}; j < 4; j++) {
      EXPECT_EQ(m1(i, j), -i * j);
    }
  }
}

TEST(SubMatrix, Test_normal_2) {
  S21Matrix m1(3, 3), m2(3, 3);
  for (int i{}; i < 3; i++) {
    for (int j{}; j < 3; j++) {
      m1(i, j) = i;
      m2(i, j) = j;
    }
  }
  m1.SubMatrix(m2);
  for (int i{}; i < 3; i++) {
    for (int j{}; j < 3; j++) {
      EXPECT_EQ(m1(i, j), i - j);
    }
  }
}

TEST(SubMatrix, Test_error) {
  S21Matrix m1(3, 4), m2(4, 4);
  EXPECT_THROW(m1.SubMatrix(m2), std::logic_error);
}

TEST(MulNumber, Test_normal) {
  S21Matrix m(4, 4);
  double num = 2.;
  for (int i{}; i < 4; i++) {
    for (int j{}; j < 4; j++) {
      m(i, j) = i * j;
    }
  }
  m.MulNumber(num);
  for (int i{}; i < 4; i++) {
    for (int j{}; j < 4; j++) {
      EXPECT_EQ(m(i, j), i * j * num);
    }
  }
}

TEST(MulMatrix, Test_normal) {
  S21Matrix m1(2, 3), m2(3, 2);
  for (int k = 1, i{}; i < 2; i++) {
    for (int j{}; j < 3; j++) {
      m1(i, j) = k++;
    }
  }
  for (int k = 1, i{}; i < 3; i++) {
    for (int j{}; j < 2; j++) {
      m2(i, j) = k++;
    }
  }
  m1.MulMatrix(m2);
  EXPECT_EQ(m1.GetRows(), 2);
  EXPECT_EQ(m1.GetCols(), 2);
  EXPECT_EQ(m1(0, 0), 22);
  EXPECT_EQ(m1(0, 1), 28);
  EXPECT_EQ(m1(1, 0), 49);
  EXPECT_EQ(m1(1, 1), 64);
}

TEST(MulMatrix, Test_error) {
  S21Matrix m1(2, 3), m2(4, 5);
  EXPECT_THROW(m1.MulMatrix(m2), std::logic_error);
}

TEST(Transpose, Test_normal) {
  S21Matrix m1(2, 3);
  for (int k = 1, i{}; i < 2; i++) {
    for (int j{}; j < 3; j++) {
      m1(i, j) = k++;
    }
  }
  S21Matrix m2 = m1.Transpose();
  EXPECT_EQ(m2.GetRows(), 3);
  EXPECT_EQ(m2.GetCols(), 2);
  EXPECT_EQ(m2(0, 0), 1);
  EXPECT_EQ(m2(0, 1), 4);
  EXPECT_EQ(m2(1, 0), 2);
  EXPECT_EQ(m2(1, 1), 5);
  EXPECT_EQ(m2(2, 0), 3);
  EXPECT_EQ(m2(2, 1), 6);
}

TEST(CalcComplements, Test_normal) {
  S21Matrix m1(3, 3);
  for (int k = 1, i{}; i < 3; i++) {
    for (int j{}; j < 3; j++) {
      m1(i, j) = k++;
    }
  }
  S21Matrix m2 = m1.CalcComplements();
  EXPECT_EQ(m2(0, 0), -3);
  EXPECT_EQ(m2(0, 1), 6);
  EXPECT_EQ(m2(0, 2), -3);
  EXPECT_EQ(m2(1, 0), 6);
  EXPECT_EQ(m2(1, 1), -12);
  EXPECT_EQ(m2(1, 2), 6);
  EXPECT_EQ(m2(2, 0), -3);
  EXPECT_EQ(m2(2, 1), 6);
  EXPECT_EQ(m2(2, 2), -3);
}

TEST(CalcComplements, Test_error) {
  S21Matrix m1(4, 3);
  EXPECT_THROW(m1.CalcComplements(), std::logic_error);
}

TEST(Determinant, Test_normal_1) {
  S21Matrix m1(3, 3);
  for (int k = 1, i{}; i < 3; i++) {
    for (int j{}; j < 3; j++) {
      m1(i, j) = k++;
    }
  }
  double det = m1.Determinant();
  EXPECT_EQ(det, 0);
  m1(0, 0) = 5;
  m1(2, 2) = 5;
  det = m1.Determinant();
  EXPECT_EQ(det, -80);
}

TEST(Determinant, Test_normal_2) {
  S21Matrix m1(1, 1);
  m1(0, 0) = 1;
  double det = m1.Determinant();
  EXPECT_EQ(det, 1);
}

TEST(Determinant, Test_error) {
  S21Matrix m1(4, 3);
  EXPECT_THROW(m1.Determinant(), std::logic_error);
}

TEST(InverseMatrix, Test_normal) {
  S21Matrix m1(3, 3);
  for (int k = 1, i{}; i < 3; i++) {
    for (int j{}; j < 3; j++) {
      m1(i, j) = k++;
    }
  }
  m1(0, 0) = 5;
  m1(2, 2) = 5;
  S21Matrix m2 = m1.InverseMatrix();
}

TEST(InverseMatrix, Test_error) {
  S21Matrix m1(3, 3);
  for (int k = 1, i{}; i < 3; i++) {
    for (int j{}; j < 3; j++) {
      m1(i, j) = k++;
    }
  }
  EXPECT_THROW(m1.InverseMatrix(), std::logic_error);
}

TEST(Constructors, default_constructor) {
  S21Matrix m1;
  EXPECT_EQ(m1.GetRows(), 1);
  EXPECT_EQ(m1.GetCols(), 1);
}

TEST(Constructors, parameters_constructor) {
  S21Matrix m1(2, 2);
  EXPECT_EQ(m1.GetRows(), 2);
  EXPECT_EQ(m1.GetCols(), 2);
  for (int i{}; i < m1.GetRows(); i++) {
    for (int j{}; j < m1.GetCols(); j++) {
      EXPECT_EQ(m1(i, j), 0);
    }
  }
  EXPECT_THROW(S21Matrix m2(-1, 0), std::logic_error);
}

TEST(Constructors, copy_constructor) {
  S21Matrix m1(2, 2);
  for (int i{}; i < m1.GetRows(); i++) {
    for (int j{}; j < m1.GetCols(); j++) {
      m1(i, j) = i + j;
    }
  }
  S21Matrix m2(m1);
  EXPECT_EQ(m1 == m2, true);
}

TEST(Constructors, move_constructor) {
  S21Matrix m1(2, 2);
  for (int i{}; i < m1.GetRows(); i++) {
    for (int j{}; j < m1.GetCols(); j++) {
      m1(i, j) = i + j;
    }
  }
  S21Matrix m2(std::move(m1));
  EXPECT_EQ(m2.GetRows(), 2);
  EXPECT_EQ(m2.GetCols(), 2);
  for (int i{}; i < m2.GetRows(); i++) {
    for (int j{}; j < m2.GetCols(); j++) {
      EXPECT_EQ(m2(i, j), i + j);
    }
  }
  EXPECT_EQ(m1.GetRows(), 0);
  EXPECT_EQ(m1.GetCols(), 0);
}

TEST(GetRows, Test_normal) {
  S21Matrix m1(2, 2), m2(3, 3);
  EXPECT_EQ(m1.GetRows(), 2);
  EXPECT_EQ(m2.GetRows(), 3);
}

TEST(GetCols, Test_normal) {
  S21Matrix m1(2, 2), m2(3, 3);
  EXPECT_EQ(m1.GetCols(), 2);
  EXPECT_EQ(m2.GetCols(), 3);
}

TEST(SetRows, Test_normal) {
  S21Matrix m1(2, 2);
  for (int i{}; i < m1.GetRows(); i++) {
    for (int j{}; j < m1.GetCols(); j++) {
      m1(i, j) = 1;
    }
  }
  m1.SetRows(5);
  EXPECT_EQ(m1.GetRows(), 5);
  for (int i = 2; i < m1.GetRows(); i++) {
    for (int j{}; j < m1.GetCols(); j++) {
      EXPECT_EQ(m1(i, j), 0);
    }
  }
}

TEST(SetRows, Test_error) {
  S21Matrix m1(2, 2);
  EXPECT_THROW(m1.SetRows(0), std::logic_error);
  EXPECT_THROW(m1.SetRows(-1), std::logic_error);
}

TEST(SetCols, Test_normal) {
  S21Matrix m1(2, 2);
  for (int i{}; i < m1.GetRows(); i++) {
    for (int j{}; j < m1.GetCols(); j++) {
      m1(i, j) = 1;
    }
  }
  m1.SetCols(5);
  EXPECT_EQ(m1.GetCols(), 5);
  for (int i{}; i < m1.GetRows(); i++) {
    for (int j = 2; j < m1.GetCols(); j++) {
      EXPECT_EQ(m1(i, j), 0);
    }
  }
}

TEST(SetCols, Test_error) {
  S21Matrix m1(2, 2);
  EXPECT_THROW(m1.SetCols(0), std::logic_error);
  EXPECT_THROW(m1.SetCols(-1), std::logic_error);
}

TEST(Overload, SumMatrix_1) {
  S21Matrix m1(4, 4), m2(4, 4);
  for (int i{}; i < 4; i++) {
    for (int j{}; j < 4; j++) {
      m2(i, j) = i * j;
    }
  }
  S21Matrix m3 = m1 + m2;
  for (int i{}; i < 4; i++) {
    for (int j{}; j < 4; j++) {
      EXPECT_EQ(m3(i, j), i * j);
    }
  }
}

TEST(Overload, SumMatrix_2) {
  S21Matrix m1(3, 3), m2(3, 3);
  for (int i{}; i < 3; i++) {
    for (int j{}; j < 3; j++) {
      m1(i, j) = i;
      m2(i, j) = j;
    }
  }
  S21Matrix m3 = m1 + m2;
  for (int i{}; i < 3; i++) {
    for (int j{}; j < 3; j++) {
      EXPECT_EQ(m3(i, j), i + j);
    }
  }
}

TEST(Overload, SumMatrix_3) {
  S21Matrix m1(3, 4), m2(4, 4);
  EXPECT_THROW(m1 + m2, std::logic_error);
}

TEST(Overload, SubMatrix_1) {
  S21Matrix m1(4, 4), m2(4, 4);
  for (int i{}; i < 4; i++) {
    for (int j{}; j < 4; j++) {
      m2(i, j) = i * j;
    }
  }
  S21Matrix m3 = m1 - m2;
  for (int i{}; i < 4; i++) {
    for (int j{}; j < 4; j++) {
      EXPECT_EQ(m3(i, j), -i * j);
    }
  }
}

TEST(Overload, SubMatrix_2) {
  S21Matrix m1(3, 3), m2(3, 3);
  for (int i{}; i < 3; i++) {
    for (int j{}; j < 3; j++) {
      m1(i, j) = i;
      m2(i, j) = j;
    }
  }
  S21Matrix m3 = m1 - m2;
  for (int i{}; i < 3; i++) {
    for (int j{}; j < 3; j++) {
      EXPECT_EQ(m3(i, j), i - j);
    }
  }
}

TEST(Overload, SubMatrix_3) {
  S21Matrix m1(3, 4), m2(4, 4);
  EXPECT_THROW(m1 - m2, std::logic_error);
}

TEST(Overload, MulNumber_1) {
  S21Matrix m(4, 4);
  double num = 2.;
  for (int i{}; i < 4; i++) {
    for (int j{}; j < 4; j++) {
      m(i, j) = i * j;
    }
  }
  S21Matrix m1 = m * num;
  for (int i{}; i < 4; i++) {
    for (int j{}; j < 4; j++) {
      EXPECT_EQ(m1(i, j), i * j * num);
    }
  }
}

TEST(Overload, MulMatrix_1) {
  S21Matrix m1(2, 3), m2(3, 2);
  for (int k = 1, i{}; i < 2; i++) {
    for (int j{}; j < 3; j++) {
      m1(i, j) = k++;
    }
  }
  for (int k = 1, i{}; i < 3; i++) {
    for (int j{}; j < 2; j++) {
      m2(i, j) = k++;
    }
  }
  S21Matrix m3 = m1 * m2;
  EXPECT_EQ(m3.GetRows(), 2);
  EXPECT_EQ(m3.GetCols(), 2);
  EXPECT_EQ(m3(0, 0), 22);
  EXPECT_EQ(m3(0, 1), 28);
  EXPECT_EQ(m3(1, 0), 49);
  EXPECT_EQ(m3(1, 1), 64);
}

TEST(Overload, MulMatrix_2) {
  S21Matrix m1(2, 3), m2(4, 5);
  EXPECT_THROW(m1 * m2, std::logic_error);
}

TEST(Overload, EqMatrix_1) {
  S21Matrix m1(3, 3), m2(3, 3);
  EXPECT_EQ(true, m1 == m2);
  m1(0, 0) = 1;
  EXPECT_EQ(false, m1 == m2);
}

TEST(Overload, EqMatrix_2) {
  S21Matrix m1(3, 3), m2(3, 3);
  for (int i{}; i < 3; i++) {
    for (int j{}; j < 3; j++) {
      m1(i, j) = i * j;
      m2(i, j) = i * j;
    }
  }
  EXPECT_EQ(true, m1 == m2);
  m1(0, 0) = 1;
  EXPECT_EQ(false, m1 == m2);
}

TEST(Overload, EqMatrix_3) {
  S21Matrix m1(3, 2), m2(2, 3);
  EXPECT_EQ(false, m1 == m2);
}

TEST(Overload, Assignment_1) {
  S21Matrix m1(3, 3), m2(2, 5);
  for (int i{}; i < 2; i++) {
    for (int j{}; j < 5; j++) {
      m2(i, j) = i + j;
    }
  }
  m1 = m2;
  EXPECT_EQ(true, m1 == m2);
}

TEST(Overload, AssigningSum_1) {
  S21Matrix m1(3, 3), m2(3, 3);
  for (int i{}; i < 3; i++) {
    for (int j{}; j < 3; j++) {
      m1(i, j) = i;
      m2(i, j) = j;
    }
  }
  m1 += m2;
  for (int i{}; i < 3; i++) {
    for (int j{}; j < 3; j++) {
      EXPECT_EQ(m1(i, j), i + j);
    }
  }
}

TEST(Overload, AssigningSum_2) {
  S21Matrix m1(3, 3), m2(2, 4);
  EXPECT_THROW(m1 += m2, std::logic_error);
}

TEST(Overload, AssigningSub_1) {
  S21Matrix m1(3, 3), m2(3, 3);
  for (int i{}; i < 3; i++) {
    for (int j{}; j < 3; j++) {
      m1(i, j) = i;
      m2(i, j) = j;
    }
  }
  m1 -= m2;
  for (int i{}; i < 3; i++) {
    for (int j{}; j < 3; j++) {
      EXPECT_EQ(m1(i, j), i - j);
    }
  }
}

TEST(Overload, AssigningSub_2) {
  S21Matrix m1(3, 3), m2(2, 4);
  EXPECT_THROW(m1 -= m2, std::logic_error);
}

TEST(Overload, AssigningMulNumber) {
  S21Matrix m1(3, 3);
  double num = 2;
  for (int i{}; i < 3; i++) {
    for (int j{}; j < 3; j++) {
      m1(i, j) = i + j;
    }
  }
  m1 *= num;
  for (int i{}; i < 3; i++) {
    for (int j{}; j < 3; j++) {
      EXPECT_EQ(m1(i, j), (i + j) * 2);
    }
  }
}

TEST(Overload, AssigningMulMatrix_1) {
  S21Matrix m1(2, 3), m2(3, 2);
  for (int k = 1, i{}; i < 2; i++) {
    for (int j{}; j < 3; j++) {
      m1(i, j) = k;
      m2(j, i) = k++;
    }
  }
  m1 *= m2;
  EXPECT_EQ(m1.GetRows(), 2);
  EXPECT_EQ(m1.GetCols(), 2);

  EXPECT_EQ(m1(0, 0), 14);
  EXPECT_EQ(m1(0, 1), 32);
  EXPECT_EQ(m1(1, 0), 32);
  EXPECT_EQ(m1(1, 1), 77);
}

TEST(Overload, AssigningMulMatrix_2) {
  S21Matrix m1(2, 4), m2(3, 2);
  EXPECT_THROW(m1 *= m2, std::logic_error);
}

TEST(Overload, IndexElem_1) {
  S21Matrix m1(3, 3);
  for (int i{}; i < 2; i++) {
    for (int j{}; j < 3; j++) {
      m1(i, j) = i + j;
    }
  }
  for (int i{}; i < 2; i++) {
    for (int j{}; j < 3; j++) {
      EXPECT_EQ(m1(i, j), i + j);
    }
  }
}

TEST(Overload, IndexElem_2) {
  S21Matrix m1(2, 2);
  EXPECT_THROW(m1(-1, 3), std::logic_error);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}