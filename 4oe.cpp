#include <iostream>
#include <vector>
#include<tuple>
#include <algorithm>
#include<numeric>
#include<iomanip>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"Russian");
    std::vector < std::tuple<std::string,int,double>>students = {
        {"иван",25,4.5},
        {"мари€",22,4.8},
        {"петр",30,4.2},
        {"анна",20,4.9}
    
    };
    //самый старший
    auto oldest = std::max_element(students.begin(),students.end(),[](const auto& a,const auto& b){
        return std::get<1>(a) < std::get<1>(b);

    });
    std::cout << "самый старший:" << std::get<0>(*oldest)
              <<", "<< std::get<1>(*oldest) << "лет\n";
    //c лучшим баллом
    auto best = std::max_element(students.begin(),students.end(),[](const auto& a,const auto& b){
        return std::get<2>(a)<std::get<2>(b);
    });
    std::cout<< "лучший студент:" << std::get<0>(*best)<<",балл "<<std::get<2>(*best)<<"\n";

    //средний возраст
    int totalAge = std::accumulate(students.begin(),students.end(),0,[](int sum,const auto& s){
        return sum + std::get<1>(s);
       });
    std::cout<<std::fixed<<std::setprecision(1);
    std::cout << "средний возраст:"
              << static_cast<double>(totalAge)/students.size() << "\n";
    //сортировка по баллу
    std::sort(students.begin(),students.end(),[](const auto& a,const auto& b){
        return std::get<2>(a) > std::get<2>(b);
        });

    std::cout <<"\nѕо баллу:\n";
    for (const auto& [name,age,gpa] : students) {
        std::cout << name << ": " << gpa << "\n";
    }
    return 0;          
}
