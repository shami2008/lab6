#include <iostream>
#include <vector>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"Russian");
    std::vector<std::vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int rows= matrix.size();
    int cols = matrix[0].size();

    std::vector<std::vector<int>> transposed(cols,std::vector<int>(rows));

    for (int i=0;i<rows;++i) {
        for (int j = 0;j<cols;++j){
            transposed[j][i] = matrix[i][j];
        }
    }
    //
    std::cout<<"исходная матрица:\n";
    for (const auto& row : matrix){
        for (int x : row) std::cout << x << " ";
        std::cout << "\n";
    }
    std::cout << "\nТранспонированная матрица:\n";
    for(const auto& row: transposed) {
        for (int x : row) std::cout << x << " ";
        std::cout << "\n";
    }

    return 0;
}