#include <algorithm>
#include <iostream>
#include <locale.h>
#include <random>
#include <iomanip>
#include <vector>
#include <numeric>

int main() {
    setlocale(LC_ALL, "Russian");
    
    int n;
    std::cout << "введите N:";
    std::cin >> n; // Считываем количество элементов, которое введет пользователь
    
    // Инициализация генератора случайных чисел
    std::random_device rd;  
    std::mt19937 gen(rd()); // Генератор псевдослучайных чисел
    std::uniform_int_distribution<> dist(1, 100); // Распределение от 1 до 100

    // Создаем вектор размером n и заполняем его случайными числами
    std::vector<int> numbers(n);
    for (int& x : numbers) x = dist(gen);

    // Вывод исходного списка
    std::cout << "исходный список:";
    for (int x : numbers) std::cout << x << " ";
    std::cout << "\n";

    // Вычисление суммы всех элементов (начальное значение 0)
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "сумма:" << sum << "\n";
    
    // Настройка вывода дробных чисел: фиксированная точка, 2 знака после запятой
    std::cout << std::fixed << std::setprecision(2);
    // Вывод среднего арифметического
    std::cout << "среднее:" << static_cast<double>(sum) / n << "\n";
    
    // Поиск минимального и максимального элементов
    std::cout << "минимум:" << *std::min_element(numbers.begin(), numbers.end()) << "\n";
    std::cout << "максимум:" << *std::max_element(numbers.begin(), numbers.end()) << "\n";

    // Сортировка вектора по возрастанию
    std::sort(numbers.begin(), numbers.end());
    std::cout << "отсортированный:";
    for (int x : numbers) std::cout << x << " ";
    std::cout << "\n";

    // Удаление дубликатов: unique сдвигает уникальные элементы в начало и удаляет неуникальные
    numbers.erase(std::unique(numbers.begin(), numbers.end()), numbers.end());
    std::cout << "без дубликатов:";
    for (int x : numbers) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
