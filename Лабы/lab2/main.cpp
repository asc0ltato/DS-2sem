#include <iostream>
#include <Windows.h>

using namespace std;

int stateMenu;

void Menu() {
	cout << "Меню:" << endl
		<< "1) Добавить товар" << endl
		<< "2) Добавить клиента" << endl
		<< "3) Сделать продажу" << endl
		<< "4) Просмотреть список товаров" << endl
		<< "5) Просмотреть список клиентов" << endl
		<< "6) Просмотреть отчет о продажах" << endl
		<< "7) Просмотреть историю заказов" << endl
		<< "0) Выход из программы" << endl
		<< "Ваш выбор: ";
	cin >> stateMenu;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Menu();
	while (stateMenu != 0) {
		switch (stateMenu) {
		case 1:
			system("cls");
			cout << "Товар добавлен!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		case 2:
			system("cls");
			cout << "Клиент добавлен!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		case 3:
			system("cls");
			cout << "Продажа осуществлена!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		case 4:
			system("cls");
			cout << "Cписок товаров: " << endl;
			system("pause");
			system("cls");
			Menu();
			break;
			break;
		case 5:
			system("cls");
			cout << "Список всех клиентов: " << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		case 6:
			system("cls");
			cout << "Отчет о продажах: " << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		case 7:
			system("cls");
			cout << "История заказов: " << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		case 0:
			system("cls");
			cout << "Выход из программы" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		default:
			system("cls");
			cout << "Неверно введен номер действия!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		}
	}
	return 0;
}

//Добавить товар - добавление информации о товаре, его названии, цене и единице измерения;

//Добавить клиента - добавление информации о клиенте, включая имя, фамилию, телефон, адрес электронной почты и другие контактные данные;

//Сделать продажу - фиксация факта продажи, включая клиента, товары, количество, дату продажи и дату доставки;

//Просмотреть список товаров - просмотр списка всех товаров, выставленных на продажу, включая их цены и единицы измерения;

//Просмотреть список клиентов - просмотр списка всех клиентов, включая их контактные данные;

//Просмотреть отчет о продажах - отображение статистики продаж за определенный период, включая количество проданных товаров, выручку и другие финансовые показатели;

//Просмотреть историю заказов - просмотр истории заказов конкретного клиента или всех клиентов за определенный период, включая информацию о заказе и доставке;

//Выход из программы - завершение работы программы.	