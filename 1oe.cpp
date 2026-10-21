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
    std::cin >> n;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    std::vector<int> numbers(n);
    for (int& x : numbers) x = dist(gen);

    std::cout << "исходный список:";
    for (int x : numbers) std::cout << x << " ";
    std::cout << "\n";

    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "сумма:" << sum << "\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "среднее:" << static_cast<double>(sum) / n << "\n";
    std::cout << "минимум:" << *std::min_element(numbers.begin(), numbers.end()) << "\n";
    std::cout << "максимум:" << *std::max_element(numbers.begin(), numbers.end()) << "\n";

    std::sort(numbers.begin(), numbers.end());
    std::cout << "отсортированный:";
    for (int x : numbers) std::cout << x << " ";
    std::cout << "\n";

    numbers.erase(std::unique(numbers.begin(), numbers.end()), numbers.end());
    std::cout << "без дубликатов:";
    for (int x : numbers) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
