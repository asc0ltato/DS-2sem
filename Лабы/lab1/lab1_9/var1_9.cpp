/*Написать программу, в которой нужно найти сумму минимального и максимального элементов массива, с выводом на экран.*/
#include <iostream>
#include <array>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    array<int, 6> arr = { 5, 8, 3, 6, 9, 1 };
    cout << "Массив: ";
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }

    int max = arr[0];
    for (int i = 0; i < 6; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    cout << "\nМаксимальное число: " << max << endl;

    int min = arr[0];
    for (int i = 0; i < 6; i++) {
        if (arr[i] < max) {
            min = arr[i];
        }
    }
    cout << "Минимальное число: " << min << endl;

    cout << "Сумма минимального и максимального числа: " << min + max << endl;
    return 0;
}