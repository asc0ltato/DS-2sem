/*Написать программу, в которой удалить n элемент из двусвязного списка и добавить такой же в начало, с выводом на экран.*/
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
    newlist.remove(6);
    newlist.push_front(6);
    cout << endl;
    cout << "Новый список:";
    for (int n : newlist) {
        cout << n << " ";
    }
}