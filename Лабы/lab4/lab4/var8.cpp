//Вы являетесь сотрудником коммерческого отдела компании, продающей различные товары через Интернет.
//Вашей задачей является отслеживание финансовой составляющей работы компании.
//Работа Вашей компании организована следующим образом : на Интернет - сайте компании представлены(выставлены на продажу) некоторые товары.
//Каждый из них имеет некоторое название, цену и единицу измерения(штуки, килограммы, литры).
//Для проведения исследований и оптимизации работы магазина Вы пытаетесь собирать данные с Ваших клиентов.
//При этом для Вас определяющее значение имеют стандартные анкетные данные, а также телефон и адрес электронной почты для связи.
//По каждому факту продажи Вы автоматически фиксируете клиента, товары, количество, дату продажи, дату доставки.


#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

// Перечисление единиц измерения товара
enum Unit
{
	PIECES,
	KILOGRAMS,
	LITERS
};

struct Product
{
	int id;
	string name;
	int price;
	Unit unit;
};

struct Client
{
	int id;
	string name;
	string surname;
	string phone;
	string email;
};

struct Sale
{
	int id;
	Product product;
	Client client;
	int count;
	string dateSale;
	string dateDelivery;
};

vector<Product> products;
vector<Client> clients;
vector<Sale> sales;

// Функция для добавления товара
void addProduct()
{
	Product product;
	cout << "Введите ID товара: ";
	cin >> product.id;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "ID товара должен быть числом!" << endl;
		cout << "Введите ID товара: ";
		cin >> product.id;
	}
	cout << "Введите название товара: ";
	cin >> product.name;
	cout << "Введите цену товара: ";
	cin >> product.price;
	cout << "Введите единицу измерения товара(0 - штуки, 1 - килограммы, 2 - литры): ";
	int unit;
	cin >> unit;
	product.unit = (Unit)unit;
	//product.id = products.size() + 1; // Устанавливаем id товара автоматически
	products.push_back(product);
	cout << "Товар успешно добавлен!" << endl;
}

// Функция для добавления клиента
void addClient()
{
	Client client;
	cout << "Введите ID клиента: ";
	cin >> client.id;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "ID клиента должен быть числом!" << endl;
		cout << "Введите ID клиента: ";
		cin >> client.id;
	}
	cout << "Введите имя клиента: ";
	cin >> client.name;
	cout << "Введите фамилию клиента: ";
	cin >> client.surname;
	cout << "Введите телефон клиента: ";
	cin >> client.phone;
	cout << "Введите email клиента: ";
	cin >> client.email;
	clients.push_back(client);
	cout << "Клиент успешно добавлен!" << endl;
}

// Функция для создания продажи
void createSale()
{
	if (products.empty() || clients.empty())
	{
		cout << "Нет товаров или клиентов!" << endl;
		return;
	}
	Sale sale;
	cout << "Выберите товар (номер): " << endl;
	for (int i = 0; i < products.size(); i++)
	{
		string unit;
		switch (products[i].unit)
		{
		case Unit::PIECES:
			unit = "штуки";
			break;
		case Unit::KILOGRAMS:
			unit = "килограммы";
			break;
		case Unit::LITERS:
			unit = "литры";
			break;
		}
		cout << i + 1 << ". " << products[i].name << " - " << products[i].price << " руб." << " - " << unit << endl;
	}
	int productNum;
	cin >> productNum;
	while (cin.fail() || productNum < 1 || productNum > products.size())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Неверный номер (либо не число, либо не в том диапазоне)!" << endl;
		cout << "Выберите товар (номер): " << endl;
		for (int i = 0; i < products.size(); i++)
		{
			cout << i + 1 << ". " << products[i].name << " - " << products[i].price << " руб." << " - " << products[i].unit << endl;
		}
		cin >> productNum;
	}
	sale.product = products[productNum - 1];
	cout << "Выберите клиента (номер): " << endl;
	for (int i = 0; i < clients.size(); i++)
	{
		cout << i + 1 << ". " << clients[i].name << " " << clients[i].surname << " - " << clients[i].phone << " - " << clients[i].email << endl;
	}
	int clientNum;
	cin >> clientNum;
	while (cin.fail() || clientNum < 1 || clientNum > clients.size())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Неверный номер (либо не число, либо не в том диапазоне)!" << endl;
		cout << "Выберите клиента (номер): " << endl;
		for (int i = 0; i < clients.size(); i++)
		{
			cout << i + 1 << ". " << clients[i].name << " " << clients[i].surname << " - " << clients[i].phone << " - " << clients[i].email << endl;
		}
		cin >> clientNum;
	}
	sale.client = clients[clientNum - 1];
	cout << "Введите количество товара: ";
	cin >> sale.count;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Количество товара должно быть числом!" << endl;
		cout << "Введите количество товара: ";
		cin >> sale.count;
	}
	cout << "Введите дату продажи (в формате ДД.ММ.ГГГГ): ";
	cin >> sale.dateSale;
	cout << "Введите дату доставки (в формате ДД.ММ.ГГГГ): ";
	cin >> sale.dateDelivery;
	sales.push_back(sale);
	cout << "Продажа успешно добавлена!" << endl;
}

// Функция для вывода товаров (Lab2)
void printProducts()
{
	if (products.empty())
	{
		cout << "Нет товаров!" << endl;
		return;
	}
	cout << "Список товаров: " << endl;
	for (int i = 0; i < products.size(); i++)
	{
		// Выводим единицу измерения в человекочитаемом виде
		string unit;
		switch (products[i].unit)
		{
		case Unit::PIECES:
			unit = "штуки";
			break;
		case Unit::KILOGRAMS:
			unit = "килограммы";
			break;
		case Unit::LITERS:
			unit = "литры";
			break;
		}
		cout << "ID: " << products[i].id << ". " << products[i].name << " - " << products[i].price << " руб." << " - " << unit << endl;
	}
}

// Функция для вывода клиентов (Lab2)
void printClients()
{
	if (clients.empty())
	{
		cout << "Нет клиентов!" << endl;
		return;
	}
	cout << "Список клиентов: " << endl;
	for (int i = 0; i < clients.size(); i++)
	{
		cout << clients[i].id << ". " << clients[i].name << " " << clients[i].surname << " - " << clients[i].phone << " - " << clients[i].email << endl;
	}
}

// Функция для вывода продаж (Lab2)
void printSales()
{
	if (sales.empty())
	{
		cout << "Нет продаж!" << endl;
		return;
	}
	cout << "Список продаж: " << endl;
	for (int i = 0; i < sales.size(); i++)
	{
		cout << sales[i].product.id << ". " << sales[i].product.name << " - " << sales[i].product.price << " руб." << " - " << (sales[i].product.unit == Unit::PIECES ? "штуки" : sales[i].product.unit == Unit::KILOGRAMS ? "килограммы" : "литры") << endl;
		cout << "Клиент: " << sales[i].client.name << " " << sales[i].client.surname << " - " << sales[i].client.phone << " - " << sales[i].client.email << endl;
		cout << "Количество: " << sales[i].count << endl;
		cout << "Дата продажи: " << sales[i].dateSale << endl;
		cout << "Дата доставки: " << sales[i].dateDelivery << endl;
	}
}

// Функция для сохранения продаж в файл(Lab3)
void createFile()
{
	string fileName;
	cout << "Введите название файла: ";
	cin >> fileName;

	ofstream file(fileName);
	if (file.is_open())
	{
		for (int i = 0; i < sales.size(); i++)
		{
			// На последней строке не должно быть переноса строки
			if (i == sales.size() - 1)
			{
				file << sales[i].product.id << " " << sales[i].product.name << " " << sales[i].product.price << " " << sales[i].product.unit << " " << sales[i].client.id << " " << sales[i].client.name << " " << sales[i].client.surname << " " << sales[i].client.phone << " " << sales[i].client.email << " " << sales[i].count << " " << sales[i].dateSale << " " << sales[i].dateDelivery;
			}
			else
			{
				file << sales[i].product.id << " " << sales[i].product.name << " " << sales[i].product.price << " " << sales[i].product.unit << " " << sales[i].client.id << " " << sales[i].client.name << " " << sales[i].client.surname << " " << sales[i].client.phone << " " << sales[i].client.email << " " << sales[i].count << " " << sales[i].dateSale << " " << sales[i].dateDelivery << endl;
			}
		}
	}
	else
	{
		cout << "Ошибка открытия файла" << endl;
	}
	system("cls");
	cout << "Данные успешно записаны в файл" << endl;
	file.close();
}

// Функция для чтения продаж, товаров и клиентов из файла(Lab3)
void readFile()
{
	string fileName;
	cout << "Введите название файла: ";
	cin >> fileName;

	ifstream file(fileName);
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			// Считываем со строки товар, клиента и продажу (если они есть, то повторно не считываем)
			Product product;
			Client client;
			Sale sale;
			stringstream ss(line);
			// Преобразовать число в ENUM
			int unit;
			ss >> product.id >> product.name >> product.price >> unit >> client.id >> client.name >> client.surname >> client.phone >> client.email >> sale.count >> sale.dateSale >> sale.dateDelivery;
			product.unit = static_cast<Unit>(unit);
			sale.product = product;
			sale.client = client;
			// Проверяем, есть ли товар, клиент и продажа в векторах
			bool isProduct = false;
			bool isClient = false;
			bool isSale = false;
			for (int i = 0; i < products.size(); i++)
			{
				if (products[i].id == product.id)
				{
					isProduct = true;
					break;
				}
			}
			for (int i = 0; i < clients.size(); i++)
			{
				if (clients[i].id == client.id)
				{
					isClient = true;
					break;
				}
			}
			for (int i = 0; i < sales.size(); i++)
			{
				if (sales[i].product.id == sale.product.id && sales[i].client.id == sale.client.id && sales[i].count == sale.count && sales[i].dateSale == sale.dateSale && sales[i].dateDelivery == sale.dateDelivery)
				{
					isSale = true;
					break;
				}
			}
			// Если товара, клиента и продажи нет, то добавляем их в вектора
			if (!isProduct)
			{
				products.push_back(product);
			}
			if (!isClient)
			{
				clients.push_back(client);
			}
			if (!isSale)
			{
				sales.push_back(sale);
			}
		}
	}
	else
	{
		cout << "Ошибка открытия файла" << endl;
	}
	system("cls");
	cout << "Данные успешно считаны из файла" << endl;
	file.close();
}

// Функция для поиска товаров, клиентов и продаж (Lab4)
void searchAnything()
{
	cout << "Выберите, что вы хотите найти: " << endl;
	cout << "1. Товар" << endl;
	cout << "2. Клиента" << endl;
	cout << "3. Продажу" << endl;
	int choiceOfSearch;
	cin >> choiceOfSearch;
	while (cin.fail() || choiceOfSearch < 1 || choiceOfSearch > 3)
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Неверный номер (либо не число, либо не в том диапазоне)!" << endl;
		cout << "Выберите, что вы хотите найти: " << endl;
		cout << "1. Товар" << endl;
		cout << "2. Клиента" << endl;
		cout << "3. Продажу" << endl;
		cin >> choiceOfSearch;
	}
	if (choiceOfSearch == 1) {
		int p_num;
		cout << "Введите ID товара: ";
		cin >> p_num;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "ID товара должно быть числом!" << endl;
			cout << "Введите ID товара: ";
			cin >> p_num;
		}
		for (int i = 0; i < products.size(); i++)
		{
			if (products[i].id == p_num)
			{
				cout << "Товар найден!" << endl;
				cout << products[i].id << ". " << products[i].name << " - " << products[i].price << " руб." << " - " << (products[i].unit == Unit::PIECES ? "штуки" : products[i].unit == Unit::KILOGRAMS ? "килограммы" : "литры") << endl;
				return;
			}
		}
	}

	if (choiceOfSearch == 2)
	{
		int c_num;
		cout << "Введите ID клиента: ";
		cin >> c_num;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "ID клиента должно быть числом!" << endl;
			cout << "Введите ID клиента: ";
			cin >> c_num;
		}
		for (int i = 0; i < clients.size(); i++)
		{
			if (clients[i].id == c_num)
			{
				cout << "Клиент найден!" << endl;
				cout << clients[i].id << ". " << clients[i].name << " " << clients[i].surname << " - " << clients[i].phone << " - " << clients[i].email << endl;
				return;
			}
		}
	}

	if (choiceOfSearch == 3)
	{
		int s_num;
		cout << "Введите ID продажи: ";
		cin >> s_num;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "ID продажи должно быть числом!" << endl;
			cout << "Введите ID продажи: ";
			cin >> s_num;
		}
		for (int i = 0; i < sales.size(); i++)
		{
			if (sales[i].product.id == s_num)
			{
				cout << "Продажа найдена!" << endl;
				cout << sales[i].product.id << ". " << sales[i].product.name << " - " << sales[i].product.price << " руб." << " - " << (sales[i].product.unit == Unit::PIECES ? "штуки" : sales[i].product.unit == Unit::KILOGRAMS ? "килограммы" : "литры") << " - " << sales[i].client.name << " " << sales[i].client.surname << " - " << sales[i].client.phone << " - " << sales[i].client.email << " - " << sales[i].count << " - " << sales[i].dateSale << " - " << sales[i].dateDelivery << endl;
				return;
			}
		}
	}
}

// Функция для изменения товаров, клиентов (Lab6)
void editAnything()
{
	cout << "Выберите, что вы хотите изменить: " << endl;
	cout << "1. Товар" << endl;
	cout << "2. Клиента" << endl;
	int choiceOfEdit;
	cin >> choiceOfEdit;
	while (cin.fail() || choiceOfEdit < 1 || choiceOfEdit > 2)
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Неверный номер (либо не число, либо не в том диапазоне)!" << endl;
		cout << "Выберите, что вы хотите изменить: " << endl;
		cout << "1. Товар" << endl;
		cout << "2. Клиента" << endl;
		cin >> choiceOfEdit;
	}
	if (choiceOfEdit == 1) // Изменение товара
	{
		int p_num;
		cout << "Введите ID товара: ";
		cin >> p_num;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "ID товара должно быть числом!" << endl;
			cout << "Введите ID товара: ";
			cin >> p_num;
		}
		for (int i = 0; i < products.size(); i++)
		{
			if (products[i].id == p_num)
			{
				cout << "Товар найден!" << endl;
				cout << products[i].id << ". " << products[i].name << " - " << products[i].price << " руб." << " - " << (products[i].unit == Unit::PIECES ? "штуки" : products[i].unit == Unit::KILOGRAMS ? "килограммы" : "литры") << endl;
				cout << "Введите новое название товара: ";
				cin >> products[i].name;
				cout << "Введите новую цену товара: ";
				cin >> products[i].price;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore(32767, '\n');
					cout << "Цена товара должна быть числом!" << endl;
					cout << "Введите новую цену товара: ";
					cin >> products[i].price;
				}
				cout << "Введите новую единицу измерения товара(0 - штуки, 1 - килограммы, 2 - литры): ";
				int unit;
				cin >> unit;
				products[i].unit = (Unit)unit;
				cout << "Товар успешно изменен!" << endl;
				return;
			}
		}
	}

	if (choiceOfEdit == 2) // Изменение клиента
	{
		int c_num;
		cout << "Введите ID клиента: ";
		cin >> c_num;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "ID клиента должно быть числом!" << endl;
			cout << "Введите ID клиента: ";
			cin >> c_num;
		}
		for (int i = 0; i < clients.size(); i++)
		{
			if (clients[i].id == c_num)
			{
				cout << "Клиент найден!" << endl;
				cout << clients[i].id << ". " << clients[i].name << " " << clients[i].surname << " - " << clients[i].phone << " - " << clients[i].email << endl;
				cout << "Введите новое имя клиента: ";
				cin >> clients[i].name;
				cout << "Введите новую фамилию клиента: ";
				cin >> clients[i].surname;
				cout << "Введите новый номер телефона клиента: ";
				cin >> clients[i].phone;
				cout << "Введите новый email клиента: ";
				cin >> clients[i].email;
				cout << "Клиент успешно изменен!" << endl;
				return;
			}
		}
	}
}

// Функция для удаления товаров, клиентов (Lab6)
void deleteAnything()
{
	cout << "Выберите, что вы хотите удалить: " << endl;
	cout << "1. Товар" << endl;
	cout << "2. Клиента" << endl;
	int choiceOfDelete;
	cin >> choiceOfDelete;
	while (cin.fail() || choiceOfDelete < 1 || choiceOfDelete > 2)
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Неверный номер (либо не число, либо не в том диапазоне)!" << endl;
		cout << "Выберите, что вы хотите удалить: " << endl;
		cout << "1. Товар" << endl;
		cout << "2. Клиента" << endl;
		cin >> choiceOfDelete;
	}
	if (choiceOfDelete == 1) // Удаление товара
	{
		int p_num;
		cout << "Введите ID товара: ";
		cin >> p_num;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "ID товара должно быть числом!" << endl;
			cout << "Введите ID товара: ";
			cin >> p_num;
		}
		for (int i = 0; i < products.size(); i++)
		{
			if (products[i].id == p_num)
			{
				cout << "Товар найден!" << endl;
				cout << products[i].id << ". " << products[i].name << " - " << products[i].price << " руб." << " - " << (products[i].unit == Unit::PIECES ? "штуки" : products[i].unit == Unit::KILOGRAMS ? "килограммы" : "литры") << endl;
				cout << "Вы уверены, что хотите удалить товар? (1 - да, 0 - нет): ";
				int choice;
				cin >> choice;
				while (cin.fail() || choice < 0 || choice > 1)
				{
					cin.clear();
					cin.ignore(32767, '\n');
					cout << "Неверный номер (либо не число, либо не в том диапазоне)!" << endl;
					cout << "Вы уверены, что хотите удалить товар? (1 - да, 0 - нет): ";
				}
				if (choice == 1) {
					products.erase(products.begin() + i);
					cout << "Товар успешно удален" << endl;
					return;
				}
				else {
					cout << "Товар не был удален!" << endl;
					return;
				}
			}
		}
	}

	if (choiceOfDelete == 2) // Удаление клиента
	{
		int c_num;
		cout << "Введите ID клиента: ";
		cin >> c_num;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "ID клиента должно быть числом!" << endl;
			cout << "Введите ID клиента: ";
			cin >> c_num;
		}
		for (int i = 0; i < clients.size(); i++)
		{
			if (clients[i].id == c_num)
			{
				cout << "Клиент найден!" << endl;
				cout << clients[i].id << ". " << clients[i].name << " " << clients[i].surname << " - " << clients[i].phone << " - " << clients[i].email << endl;
				cout << "Вы уверены, что хотите удалить клиента? (1 - да, 0 - нет): ";
				int choice;
				cin >> choice;
				while (cin.fail() || choice < 0 || choice > 1)
				{
					cin.clear();
					cin.ignore(32767, '\n');
					cout << "Неверный номер (либо не число, либо не в том диапазоне)!" << endl;
					cout << "Вы уверены, что хотите удалить клиента? (1 - да, 0 - нет): ";
				}
				if (choice == 1) {
					clients.erase(clients.begin() + i);
					cout << "Клиент успешно удален" << endl;
					return;
				}
				else
				{
					cout << "Клиент не был удален!" << endl;
					return;
				}
			}
		}
	}
}

// Функция для полного удаления товаров, клиентов (Lab6)
void deleteAll()
{
	cout << "Выберите, что вы хотите удалить: " << endl;
	cout << "1. Товар" << endl;
	cout << "2. Клиента" << endl;
	int choiceOfDelete;
	cin >> choiceOfDelete;
	while (cin.fail() || choiceOfDelete < 1 || choiceOfDelete > 2)
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Неверный номер (либо не число, либо не в том диапазоне)!" << endl;
		cout << "Выберите, что вы хотите удалить: " << endl;
		cout << "1. Товар" << endl;
		cout << "2. Клиента" << endl;
		cin >> choiceOfDelete;
	}
	if (choiceOfDelete == 1) // Удаление товара
	{
		products.clear();
		cout << "Все товары успешно удалены!" << endl;
	}

	if (choiceOfDelete == 2) // Удаление клиента
	{
		clients.clear();
		cout << "Все клиенты успешно удалены!" << endl;
	}
}

// Функция сортировки по двум параметрам (Lab7)
void sort()
{
	cout << "Выберите, что вы хотите отсортировать: " << endl;
	cout << "1. Товар" << endl;
	cout << "2. Клиента" << endl;
	int choiceOfSort;
	cin >> choiceOfSort;
	while (cin.fail() || choiceOfSort < 1 || choiceOfSort > 2)
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Неверный номер (либо не число, либо не в том диапазоне)!" << endl;
		cout << "Выберите, что вы хотите отсортировать: " << endl;
		cout << "1. Товар" << endl;
		cout << "2. Клиента" << endl;
		cin >> choiceOfSort;
	}
	if (choiceOfSort == 1) // Сортировка товара
	{
		cout << "Выберите, по какому параметру вы хотите отсортировать товар: " << endl;
		cout << "1. По названию" << endl;
		cout << "2. По цене" << endl;
		int choiceOfSortParam1;
		cin >> choiceOfSortParam1;
		while (cin.fail() || choiceOfSortParam1 < 1 || choiceOfSortParam1 > 2)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Неверный номер (либо не число, либо не в том диапазоне)!" << endl;
			cout << "Выберите, по какому параметру вы хотите отсортировать товар: " << endl;
			cout << "1. По названию" << endl;
			cout << "2. По цене" << endl;
			cin >> choiceOfSortParam1;
		}
		if (choiceOfSortParam1 == 1) // Сортировка по названию
		{
			for (int i = 0; i < products.size() - 1; i++)
			{
				for (int j = 0; j < products.size() - i - 1; j++)
				{
					if (products[j].name > products[j + 1].name)
					{
						swap(products[j], products[j + 1]);
					}
				}
			}
			cout << "Товары успешно отсортированы по названию!" << endl;
		}
		if (choiceOfSortParam1 == 2) // Сортировка по цене
		{
			for (int i = 0; i < products.size() - 1; i++)
			{
				for (int j = 0; j < products.size() - i - 1; j++)
				{
					if (products[j].price > products[j + 1].price)
					{
						swap(products[j], products[j + 1]);
					}
				}
			}
			cout << "Товары успешно отсортированы по цене!" << endl;
		}

	}
	if (choiceOfSort == 2) // Сортировка клиентов
	{
		cout << "Выберите, по какому параметру вы хотите отсортировать клиента: " << endl;
		cout << "1. По имени" << endl;
		cout << "2. По фамилии" << endl;
		int choiceOfSortParam2;
		cin >> choiceOfSortParam2;
		while (cin.fail() || choiceOfSortParam2 < 1 || choiceOfSortParam2 > 2)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Неверный номер (либо не число, либо не в том диапазоне)!" << endl;
			cout << "Выберите, по какому параметру вы хотите отсортировать клиента: " << endl;
			cout << "1. По имени" << endl;
			cout << "2. По фамилии" << endl;
			cin >> choiceOfSortParam2;
		}
		if (choiceOfSortParam2 == 1) // Сортировка по имени
		{
			for (int i = 0; i < clients.size() - 1; i++)
			{
				for (int j = 0; j < clients.size() - i - 1; j++)
				{
					if (clients[j].name > clients[j + 1].name)
					{
						swap(clients[j], clients[j + 1]);
					}
				}
			}
			cout << "Клиенты успешно отсортированы по имени!" << endl;
		}
		if (choiceOfSortParam2 == 2) // Сортировка по фамилии
		{
			for (int i = 0; i < clients.size() - 1; i++)
			{
				for (int j = 0; j < clients.size() - i - 1; j++)
				{
					if (clients[j].surname > clients[j + 1].surname)
					{
						swap(clients[j], clients[j + 1]);
					}
				}
			}
			cout << "Клиенты успешно отсортированы по фамилии!" << endl;
		}
	}
}

// Функция сортировки вставками клиентов по электронной почте по возрастанию (Lab7 доп)
void InsertionSortClientsByEmail()
{
	for (int i = 1; i < clients.size(); i++)
	{
		Client temp = clients[i];
		int j = i - 1;
		while (j >= 0 && clients[j].email > temp.email)
		{
			clients[j + 1] = clients[j];
			j--;
		}
		clients[j + 1] = temp;
	}
	cout << "Клиенты успешно отсортированы по электронной почте!" << endl;
}


// Функция поиск подстроки в фамилии (Lab8)
void SearchSubstringInSurname()
{
	// Ввод подстроки
	string substring;
	cout << "Введите подстроку, которую вы хотите найти в фамилии: ";
	cin >> substring;

	// Поиск подстроки в фамилии
	// Если фамилий несколько, то выводим все
	int count = 0;
	for (int i = 0; i < clients.size(); i++)
	{
		if (clients[i].surname.find(substring) != string::npos)
		{
			cout << "Фамилия: " << clients[i].surname << endl;
			count++;
		}
	}
	if (count == 0)
	{
		cout << "Подстрока не найдена!" << endl;
	}
}

// Реализовать алгоритм интерпретирующего поиска индекса в вашем массиве структур (Lab9)
void InterpretingSearchBySurname()
{
	// Ввод фамилии
	string surname;
	cout << "Введите фамилию, которую вы хотите найти: ";
	cin >> surname;

	// Сортировка клиентов по фамилии
	for (int i = 0; i < clients.size() - 1; i++)
	{
		for (int j = 0; j < clients.size() - i - 1; j++)
		{
			// Сравнение фамилий клиентов и обмен их местами, если нужно
			if (clients[j].surname > clients[j + 1].surname)
			{
				swap(clients[j], clients[j + 1]);
			}
		}
	}

	// Интерпретирующий поиск (с указанием ячейки)
	int left = 0;
	int right = clients.size() - 1;
	int middle = 0;
	// Пока левый и правый указатели не указывают на клиента с нужной фамилией, выполняем следующие действия
	while (clients[left].surname != surname && clients[right].surname != surname)
	{
		// Расчет средней позиции между левым и правым указателями
		middle = left + (right - left) * (surname[0] - clients[left].surname[0]) / (clients[right].surname[0] - clients[left].surname[0]);
		if (clients[middle].surname < surname) // Если фамилия клиента средней позиции меньше, чем нужная фамилия, смещаем левый указатель на среднюю позицию + 1
		{
			left = middle + 1;
		}
		else // Иначе смещаем правый указатель на среднюю позицию - 1
		{
			right = middle - 1;
		}
	}
	if (clients[left].surname == surname) // Если левый указатель указывает на клиента с нужной фамилией, выводим информацию о нем
	{
		cout << "Номер ячейки: " << left << endl;
		cout << "Фамилия: " << clients[left].surname << endl;
		cout << "Имя: " << clients[left].name << endl;
		cout << "Номер: " << clients[left].phone << endl;
		cout << "Электронная почта: " << clients[left].email << endl;
	}
	else if (clients[right].surname == surname) // Иначе, если правый указатель указывает на клиента с нужной фамилией, выводим информацию о нем
	{
		cout << "Номер ячейки: " << right << endl;
		cout << "Фамилия: " << clients[right].surname << endl;
		cout << "Имя: " << clients[right].name << endl;
		cout << "Номер: " << clients[right].phone << endl;
		cout << "Электронная почта: " << clients[right].email << endl;
	}
}

// Реализовать бинарный поиск по любому из типов данных (например string, по фамилии) (Lab9)
void BinarySearchBySurname()
{
	// Ввод фамилии
	string surname;
	cout << "Введите фамилию, которую вы хотите найти: ";
	cin >> surname;

	// Сортировка клиентов по фамилии (пузырьковая)
	for (int i = 0; i < clients.size() - 1; i++)
	{
		for (int j = 0; j < clients.size() - i - 1; j++)
		{
			if (clients[j].surname > clients[j + 1].surname)
			{
				swap(clients[j], clients[j + 1]);
			}
		}
	}

	// Бинарный поиск (с указанием ячейки)
	int left = 0;
	int right = clients.size() - 1;
	int middle;
	while (left <= right) // Начало бинарного поиска с проверкой, что left не превышает right
	{
		middle = (left + right) / 2; // Вычисление средней позиции в списке клиентов
		if (clients[middle].surname == surname) // Если фамилия клиента в средней позиции списка соответствует введенной пользователем фамилии
		{
			cout << "Клиент найден!" << endl;
			cout << "Номер ячейки: " << middle << endl;
			cout << "Фамилия: " << clients[middle].surname << endl;
			cout << "Имя: " << clients[middle].name << endl;
			cout << "Номер: " << clients[middle].phone << endl;
			cout << "Электронная почта: " << clients[middle].email << endl;
			break;
		}// > или < фамилия клиента в средней позиции списка, чем введенная пользователем, границы интервала поиска сужаются до левой или правой половины от текущей средней позиции
		else if (clients[middle].surname < surname) 
		{
			left = middle + 1;
		}
		else
		{
			right = middle - 1;
		}
	} //Если границы интервала поиска сузились до того, что left стал больше, чем right, то это означает, что клиент с введенной фамилией в списке отсутствует
	if (left > right)
	{
		cout << "Клиент не найден!" << endl;
	}
}

// Функция меню
void Menu()
{
	cout << "Выберите действие: " << endl;
	cout << "1. Добавить товар (Lab2)" << endl;
	cout << "2. Добавить клиента (Lab2)" << endl;
	cout << "3. Создать продажу (Lab2)" << endl;
	cout << "4. Просмотреть список товаров (Lab2)" << endl;
	cout << "5. Просмотреть список клиентов (Lab2)" << endl;
	cout << "6. Просмотреть список продаж (Lab2)" << endl;
	cout << "7. Сохранение продаж в файл (Lab5)" << endl;
	cout << "8. Загрузка продаж из файла (Lab5)" << endl;
	cout << "9. Поиск товара или клиента  (Lab4)" << endl;
	cout << "10. Изменение товара или клиента (Lab6)" << endl;
	cout << "11. Удаление товара или клиента (Lab6)" << endl;
	cout << "12. Удаление всех товаров или клиентов (Lab6)" << endl;
	cout << "13. Сортировка товаров или клиентов (Lab7)" << endl;
	cout << "14. Сортировка клиентов по электронной почте (Lab7 доп)" << endl;
	cout << "15. Поиск подстроки в фамилии (Lab8)" << endl;
	cout << "16. Интерпретирующий поиск по фамилии (Lab9)" << endl;
	cout << "17. Бинарный поиск по фамилии (Lab9)" << endl;
	cout << "0. Выход" << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true)
	{
		Menu();
		int choice;
		cin >> choice;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Неверный номер!" << endl;
			cin >> choice;
		}
		switch (choice)
		{
		case 0:
			system("cls");
			cout << "Выход" << endl;
			return 0;
		case 1:
			addProduct();
			break;
		case 2:
			addClient();
			break;
		case 3:
			createSale();
			break;
		case 4:
			printProducts();
			break;
		case 5:
			printClients();
			break;
		case 6:
			printSales();
			break;
		case 7:
			createFile();
			break;
		case 8:
			readFile();
			break;
		case 9:
			searchAnything();
			break;
		case 10:
			editAnything();
			break;
		case 11:
			deleteAnything();
			break;
		case 12:
			deleteAll();
			break;
		case 13:
			sort();
			break;
		case 14:
			InsertionSortClientsByEmail();
			break;
		case 15:
			SearchSubstringInSurname();
			break;
		case 16:
			InterpretingSearchBySurname();
			break;
		case 17:
			BinarySearchBySurname();
			break;
		default:
			cout << "Неверный номер!" << endl;
			break;
		}
	}
}