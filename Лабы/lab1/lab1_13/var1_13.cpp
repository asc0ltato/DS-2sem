/*Написать программу, в которой нужно удалить все элементы односвязного списка и добавить n новых, с выводом на экран.*/
#include <iostream>
#include <forward_list>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int num = 0;
    forward_list <int> newlist = { 5, 2, 6, 9, 7 };
    cout << "Список:";
    for (int n : newlist) {
        cout << n << " ";
    }
    cout << endl;
    newlist.clear();
    cout << "Введите количество добавляемых чисел:";
    cin >> num;
    for (int i = 0; i < num; i++) {
        newlist.emplace_front(10 - i);
    }
    cout << "Новый список:";
    for (int n : newlist) {
        cout << n << " ";
    }
}