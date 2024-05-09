/*Написать программу, в которой нужно найти сумму всех элементов вектора и вывести ее на экран.*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    vector<int> vec = { 3, 6, 10, 4, 7 }; 
    int sum = 0; // инициализируем переменную для суммы

    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i]; 
    }

    cout << "Сумма всех элементов вектора: " << sum << endl; 
    return 0;
}