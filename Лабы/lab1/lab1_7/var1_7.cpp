/*Написать программу, в которой нужно найти максимальный элемент вектора и вывести на экран.*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    vector<int> vec = { 0, 5, 2, 8, 4, 22, 6 };
    cout << "Массив:";
    // Инициализируем переменную, которая будет хранить макс элемент
    int max_element = vec[0];

    // Ищем максимальный элемент в векторе
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
        if (vec[i] > max_element) {
            max_element = vec[i];
        }
    }
    cout << "\nМаксимальный элемент: " << max_element << endl;
    return 0;
}