/*Написать программу, которая, в зависимости от выбора пользователя, в консоли должна выводить дни недели, с использованием перечислений.*/
#include <iostream>

using namespace std;

enum DayOfWeek {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;

    cout << "Введите число от 1 до 7 дня недели: ";
    cin >> choice;
    choice--;

    switch (choice) {
    case MONDAY:
        cout << "Понедельник" << endl;
        break;
    case TUESDAY:
        cout << "Вторник" << endl;
        break;
    case WEDNESDAY:
        cout << "Среда" << endl;
        break;
    case THURSDAY:
        cout << "Четверг" << endl;
        break;
    case FRIDAY:
        cout << "Пятница" << endl;
        break;
    case SATURDAY:
        cout << "Суббота" << endl;
        break;
    case SUNDAY:
        cout << "Воскресенье" << endl;
        break;
    default:
        cout << "Неверный выбор" << endl;
        break;
    }
    return 0;
}