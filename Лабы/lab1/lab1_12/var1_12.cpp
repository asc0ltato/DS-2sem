/*Написать программу, в которой нужно найти произведение всех элементов деки и вывести его на экран.*/
#include <iostream>
#include <deque>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    deque<int> mydeque = { 1, 2, 3, 4, 3 };
    int product = 1;
    cout << "Массив: ";
    for (int i = 0; i < mydeque.size(); i++) {
        cout << mydeque[i] << " ";
    }

    for (int i = 0; i < mydeque.size(); i++) {
        product *= mydeque[i];
    }

    cout << "\nПроизведение элементов деки: " << product << endl;
    return 0;
}