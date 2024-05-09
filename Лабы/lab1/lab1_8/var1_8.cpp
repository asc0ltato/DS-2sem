/*Написать программу, в которой нужно найти минимальный элемент дэки и добавить его в начало, с выводом на экран .*/
#include <iostream>
#include <deque>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    deque<int> mydeque = { 3, 1, 4, 8, 5, 9, 2, 6 }; // создаем дек из целых чисел
    cout << "Массив: ";

    int min_element = mydeque[0];

    for (int i = 0; i < mydeque.size(); i++) {
        cout << mydeque[i] << " ";
        if (mydeque[i] < min_element) {
            min_element = mydeque[i];
        }
    }

    cout << "\nМинимальный элемент: " << min_element << endl;

    mydeque.push_front(min_element);

    cout << "Новый массив: ";
    for (int i = 0; i < mydeque.size(); ++i) {
        cout << mydeque[i] << " ";
    }
    return 0;
}