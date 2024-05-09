/*Написать программу, которая, в зависимости от выбора пользователя, в консоли должна выводить цвета радуги, с использованием перечислений.*/
#include <iostream>

using namespace std;

enum RainbowColors {
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    DARKBLUE,
    PURPLE
}; 

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;

    cout << "Выберите цвет радуги: " << endl;
    cout << "1. Красный" << endl;
    cout << "2. Оранжевый" << endl;
    cout << "3. Желтый" << endl;
    cout << "4. Зеленый" << endl;
    cout << "5. Голубой" << endl;
    cout << "6. Синий" << endl;
    cout << "7. Фиолетовый" << endl;

    cin >> choice;
    choice--;
    switch (choice) {
    case RED:
        cout << "Красный" << endl;
        break;
    case ORANGE:
        cout << "Оранжевый" << endl;
        break;
    case YELLOW:
        cout << "Желтый" << endl;
        break;
    case GREEN:
        cout << "Зеленый" << endl;
        break;
    case BLUE:
        cout << "Голубой" << endl;
        break;
    case DARKBLUE:
        cout << "Синий" << endl;
        break;
    case PURPLE:
        cout << "Фиолетовый" << endl;
        break;
    default:
        cout << "Неверный выбор" << endl;
        break;
    }
    return 0;
}