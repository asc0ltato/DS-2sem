//Написать функции :
//1.	Создание и запись данных в файл, название которого вводится с клавиатуры;
//2.	Чтение файла(название файла не нужно вводить с клавиатуры);
//3.	Удаление содержимого в файле;
//4.	Удаление файла.

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

// функция для создания и записи данных в файл
void createFile() {
    string filename;
    cout << "Введите имя файла: ";
    cin >> filename;

    ofstream file;
    file.open(filename);

    if (file.is_open()) {
        string line;
        cout << "Введите текст для записи в файл. Для завершения ввода введите пустой пробел.\n";
        while (getline(cin, line) && line != " ") {
            file << line << endl;
        }
        file.close();
        cout << "Данные успешно записаны в файл.\n";
    } else {
        cout << "Не удалось открыть файл для записи.\n";
    }
}

// функция для чтения файла
void readFile() {
    string filename = "txt.txt";
    
    ifstream file;
    file.open(filename);

    if (file.is_open()) {
        string line;
        cout << "Содержимое файла:\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Не удалось открыть файл для чтения.\n";
    }
}

// функция для удаления содержимого в файле
void clearFile() {
    string filename;
    cout << "Введите имя файла: ";
    cin >> filename;

    ofstream file;
    file.open(filename, ios::trunc); // открыть файл и удалить содержимое

    if (file.is_open()) {
        file.close();
        cout << "Содержимое файла успешно удалено.\n";
    } else {
        cout << "Не удалось открыть файл для удаления содержимого.\n";
    }
}

// функция для удаления файла
void deleteFile() {
    string filename;
    cout << "Введите имя файла: ";
    cin >> filename;

    if (remove(filename.c_str()) == 0) {
        cout << "Файл успешно удален.\n";
    } else {
        cout << "Не удалось удалить файл.\n";
    }
}

// функция для вывода меню и вызова соответствующих функций
void main() {
    int choice;
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    do {
        cout << "Меню:\n";
        cout << "1. Создание и запись данных в файл\n";
        cout << "2. Чтение файла\n";
        cout << "3. Удаление содержимого в файле\n";
        cout << "4. Удаление файла\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            createFile();
            break;
        case 2:
            readFile();
            break;
        case 3:
            clearFile();
            break;
        case 4:
            deleteFile();
            break;
        case 0:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Некорректный выбор.\n";
            break;
        }
    } while (choice != 0);
}