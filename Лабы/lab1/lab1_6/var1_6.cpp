/*Написать программу, в которой в начало двусвязного списка добавляется n элементов и вывести на экран.*/
#include <iostream>
#include <list>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int num = 0;
    list <int> newlist = { 5, 2, 6, 9, 7 };
    cout << "Список:";
    for (int n : newlist) {
        cout << n << " ";
    }
    cout << endl;
    cout << "Введите количество добавляемых чисел:";
    cin >> num;
    for (int i = 0; i < num; i++) {
        newlist.push_front(15 - i);
    }
    cout << "Новый список:";
    for (int n : newlist) {
        cout << n << " ";
    }
    return 0;
}