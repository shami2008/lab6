#include <iostream>
#include <vector>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");
    // Создание двумерного вектора (матрицы 3x3) и его инициализация
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // Определение количества строк и столбцов
    int rows = matrix.size();       // Количество строк (размер внешнего вектора)
    int cols = matrix[0].size();    // Количество столбцов (размер первой строки)

    // Создание пустой матрицы для транспонирования: 
    // размерность меняется на cols x rows и заполняется нулями
    std::vector<std::vector<int>> transposed(cols, std::vector<int>(rows));

    // Заполнение транспонированной матрицы
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Меняем местами индексы строк и столбцов
            transposed[j][i] = matrix[i][j];
        }
    }

    // Вывод исходной матрицы на экран
    std::cout << "исходная матрица:\n";
    for (const auto& row : matrix) { // Проходим по каждой строке
        for (int x : row) std::cout << x << " "; // Выводим элементы строки
        std::cout << "\n"; // Переход на новую строку
    }
    
    // Вывод транспонированной матрицы на экран
    std::cout << "\nТранспонированная матрица:\n";
    for (const auto& row : transposed) {
        for (int x : row) std::cout << x << " ";
        std::cout << "\n";
    }

    return 0;
}
