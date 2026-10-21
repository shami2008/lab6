#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <locale.h>
#include <string> // Добавлено для корректной работы std::string

int main() {
    setlocale(LC_ALL, "Russian");
    
    // Создание вектора кортежей. Каждый кортеж содержит: string (имя), int (возраст), double (балл)
    std::vector<std::tuple<std::string, int, double>> students = {
        {"иван", 25, 4.5},
        {"мария", 22, 4.8},
        {"петр", 30, 4.2},
        {"анна", 20, 4.9}
    };

    // Поиск самого старшего студента
    // std::max_element возвращает итератор на максимальный элемент
    auto oldest = std::max_element(students.begin(), students.end(), 
        [](const auto& a, const auto& b) {
            // Сравниваем по возрасту (индекс 1 в кортеже)
            return std::get<1>(a) < std::get<1>(b);
        });
    // Вывод результата: разыменовываем итератор (*oldest) для доступа к кортежу
    std::cout << "самый старший:" << std::get<0>(*oldest)
              << ", " << std::get<1>(*oldest) << " лет\n";

    // Поиск студента с лучшим баллом
    auto best = std::max_element(students.begin(), students.end(), 
        [](const auto& a, const auto& b) {
            // Сравниваем по баллу (индекс 2 в кортеже)
            return std::get<2>(a) < std::get<2>(b);
        });
    std::cout << "лучший студент:" << std::get<0>(*best) 
              << ", балл " << std::get<2>(*best) << "\n";

    // Вычисление суммы возрастов всех студентов
    int totalAge = std::accumulate(students.begin(), students.end(), 0, 
        [](int sum, const auto& s) {
            // К аккумулятору (sum) прибавляем возраст текущего студента
            return sum + std::get<1>(s);
        });
        
    // Настройка формата вывода: фиксированная точка, 1 знак после запятой
    std::cout << std::fixed << std::setprecision(1);
    // Вывод среднего возраста
    std::cout << "средний возраст: "
              << static_cast<double>(totalAge) / students.size() << "\n";

    // Сортировка студентов по убыванию балла (от лучшего к худшему)
    std::sort(students.begin(), students.end(), 
        [](const auto& a, const auto& b) {
            // Знак ">" обеспечивает сортировку по убыванию
            return std::get<2>(a) > std::get<2>(b);
        });

    // Вывод отсортированного списка
    std::cout << "\nПо баллу:\n";
    // Использование структурированного связывания (C++17) для распаковки кортежа
    for (const auto& [name, age, gpa] : students) {
        std::cout << name << ": " << gpa << "\n";
    }

    return 0;          
}
