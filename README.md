# matrix_oop

Реализация библиотеки s21_matrix_oop.h

## Операции над матрицами

Ниже представлено краткое описание операций над матрицами, которые реализованы в библиотеке. 

| Операция    | Описание   | Исключительные ситуации |
| ----------- | ----------- | ----------- |
| `bool EqMatrix(const S21Matrix& other)` | Проверяет матрицы на равенство между собой. |  |
| `void SumMatrix(const S21Matrix& other)` | Прибавляет вторую матрицы к текущей | различная размерность матриц. |
| `void SubMatrix(const S21Matrix& other)` | Вычитает из текущей матрицы другую | различная размерность матриц. |
| `void MulNumber(const double num)` | Умножает текущую матрицу на число. |  |
| `void MulMatrix(const S21Matrix& other)` | Умножает текущую матрицу на вторую. | число столбцов первой матрицы не равно числу строк второй матрицы. |
| `S21Matrix Transpose()` | Создает новую транспонированную матрицу из текущей и возвращает ее. |  |
| `S21Matrix CalcComplements()` | Вычисляет матрицу алгебраических дополнений текущей матрицы и возвращает ее. | Матрица не является квадратной. |
| `double Determinant()` | Вычисляет и возвращает определитель текущей матрицы. | Матрица не является квадратной. |
| `S21Matrix InverseMatrix()` | Вычисляет и возвращает обратную матрицу. | Определитель матрицы равен 0. |

Реализация конструкторово и деструктора:

| Метод    | Описание   |
| ----------- | ----------- |
| `S21Matrix()` | Базовый конструктор, инициализирующий матрицу некоторой заранее заданной размерностью. |  
| `S21Matrix(int rows, int cols)` | Параметризированный конструктор с количеством строк и столбцов. | 
| `S21Matrix(const S21Matrix& other)` | Конструктор копирования. |
| `S21Matrix(S21Matrix&& other)` | Конструктор переноса. |
| `~S21Matrix()` | Деструктор. |

Реализована перегрузка следующих операторов, частично соответствующие операциям выше:

| Оператор    | Описание   | Исключительные ситуации |
| ----------- | ----------- | ----------- |
| `+`      | Сложение двух матриц.  | Различная размерность матриц. |
| `-`   | Вычитание одной матрицы из другой. | Различная размерность матриц. |
| `*`  | Умножение матриц и умножение матрицы на число. | Число столбцов первой матрицы не равно числу строк второй матрицы. |
| `==`  | Проверка на равенство матриц (`EqMatrix`). | |
| `=`  | Присвоение матрице значений другой матрицы. | |
| `+=`  | Присвоение сложения (`SumMatrix`).   | Различная размерность матриц. |
| `-=`  | Присвоение разности (`SubMatrix`). | Различная размерность матриц. |
| `*=`  | Присвоение умножения (`MulMatrix`/`MulNumber`). | Число столбцов первой матрицы не равно числу строк второй матрицы. |
| `(int i, int j)`  | Индексация по элементам матрицы (строка, колонка). | Индекс за пределами матрицы. |

## Build

Сборка программы настроена с помощью Makefile

* `make s21_matrix_oop.a` - Компиляция статической библиотеки
* `make test` - Покрытие unit-тестами функций вычисления c помощью библиотеки GTest
* `make gcov_report` - Формирование отчёта gcov в виде html страницы
* `make leaks` - Проверка тестов на утечки памяти
* `make clang` - Проверка кода на Google style
* `make clean` - Удаление ненужных файлов

## Реализация функции библиотеки s21_matrix_oop.h

- Программа разработана на языке C++ стандарта C++17 с использованием компилятора gcc;
- Код программы находится в папке src;
- Матрица реализована в виде класса `S21Matrix`;
- Доступ к приватным полям `rows_` и `cols_` реализован через accessor и mutator. При увеличении размера матрица дополняется нулевыми элементами, при уменьшении - лишнее просто отбрасывается;
- Решение оформлено как статическая библиотека (с заголовочным файлом s21_matrix_oop.h);
- Полное покрытие unit-тестами функций библиотеки c помощью библиотеки GTest;
