//3.	Вы работаете в ломбарде.Вашей задачей является отслеживание финансовой стороны работы ломбарда.Деятельность Вашей компании организована следующим образом : к Вам обращаются различные лица
//с целью получения денежных средств под залог определенных товаров.У каждого из приходящих к Вам клиентов Вы запрашиваете фамилию, имя, отчество и другие паспортные данные.
//После оценивания стоимости принесенного в качестве залога товара Вы определяете сумму, которую готовы выдать на руки клиенту, а также свои комиссионные.Кроме того, определяете срок возврата денег.
//Если клиент согласен, то Ваши договоренности фиксируются в виде документа, деньги выдаются клиенту, а товар остается у Вас.В случае если в указанный срок не происходит возврата денег,
//товар переходит в Вашу собственность. После перехода прав собственности на товар, ломбард может продавать товары по цене, меньшей или большей, чем была заявлена при сдаче.

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

// Перечисление цены товара, за которую ломбард тебе отдает
enum Unit
{
	OneHUNDRED = 1,
	ThreeHUNDRED,
	FiveHUNDRED,
	SevenHUNDRED
};

struct Product
{
	int id;
	string name;
	Unit unit;
	string commisia;
};

struct Client
{
	int id;
	string name;
	string surname;
	string patronymic;
	string pasport;
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
	cout << "Введите цену товара(1 - 100, 2 - 300,  3 - 500, 4 - 700): ";
	int unit;
	cin >> unit;
	product.unit = (Unit)unit;
	cout << "Введите комиссионные, если человек не вовремя отдаст деньги: ";
	cin >> product.commisia;
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
	cout << "Введите фамилию клиента: ";
	cin >> client.surname;
	cout << "Введите имя клиента: ";
	cin >> client.name;
	cout << "Введите отчество клиента: ";
	cin >> client.patronymic;
	cout << "Введите паспорт клиента: ";
	cin >> client.pasport;
	clients.push_back(client);
	cout << "Клиент успешно добавлен!" << endl;
}

// Функция для создания залога
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
		case Unit::OneHUNDRED:
			unit = "100 рублей";
			break;
		case Unit::ThreeHUNDRED:
			unit = "300 рублей";
			break;
		case Unit::FiveHUNDRED:
			unit = "500 рублей";
			break;
		case Unit::SevenHUNDRED:
			unit = "700 рублей";
			break;
		}
		cout << i + 1 << ". " << products[i].name << " - " << unit << " - " << products[i].commisia << endl;
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
			cout << i + 1 << ". " << products[i].name << " - " << products[i].unit << products[i].commisia << endl;
		}
		cin >> productNum;
	}
	sale.product = products[productNum - 1];
	cout << "Выберите клиента (номер): " << endl;
	for (int i = 0; i < clients.size(); i++)
	{
		cout << i + 1 << ". " << clients[i].surname << " " << clients[i].name << " " << clients[i].patronymic << " - " << clients[i].pasport << endl;
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
			cout << i + 1 << ". " << clients[i].surname << " " << clients[i].name << " " << clients[i].patronymic << " - " << clients[i].pasport << endl;
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
	cout << "Введите дату срока возврата товара (в формате ДД.ММ.ГГГГ): ";
	cin >> sale.dateSale;
	cout << "Введите дату, когда клиент вернул деньги (в формате ДД.ММ.ГГГГ): ";
	cin >> sale.dateDelivery;
	sales.push_back(sale);
	cout << "Залог успешно добавлен!" << endl;
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
		case Unit::OneHUNDRED:
			unit = "100 рублей";
			break;
		case Unit::ThreeHUNDRED:
			unit = "300 рублей";
			break;
		case Unit::FiveHUNDRED:
			unit = "500 рублей";
			break;
		case Unit::SevenHUNDRED:
			unit = "700 рублей";
			break;
		}
		cout << "ID: " << products[i].id << ". " << products[i].name << " - " << unit << " - " << products[i].commisia << endl;
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
		cout << "ID: "  << clients[i].id << ". " << clients[i].surname << " " << clients[i].name << " " << clients[i].patronymic << " - " << clients[i].pasport << endl;
	}
}

// Функция для вывода продаж (Lab2)
void printSales()
{
	if (sales.empty())
	{
		cout << "Нет залогов!" << endl;
		return;
	}
	cout << "Список залогов: " << endl;
	for (int i = 0; i < sales.size(); i++)
	{
		cout << sales[i].product.id << ". " << sales[i].product.name << " - " << (sales[i].product.unit == Unit::OneHUNDRED ? "100 рублей" : sales[i].product.unit == Unit::ThreeHUNDRED ? "300 рублей" : sales[i].product.unit == Unit::FiveHUNDRED ? " 500 рублей" : "400 рублей") << " - " << sales[i].product.commisia << endl;
		cout << "Клиент: " << sales[i].client.surname << " " << sales[i].client.name << " " << sales[i].client.patronymic << " - " << sales[i].client.pasport << endl;
		cout << "Количество: " << sales[i].count << endl;
		cout << "Дата, когда клиент должен возвратить деньги ломбарду: " << sales[i].dateSale << endl;
		cout << "Дата возврата денег: " << sales[i].dateDelivery << endl;
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
				file << sales[i].product.id << " " << sales[i].product.name << " " << sales[i].product.unit << " " << sales[i].product.commisia << " " << sales[i].client.id << " " << sales[i].client.surname << " " << sales[i].client.name << " " << sales[i].client.patronymic << " " << sales[i].client.pasport << " " << sales[i].count << " " << sales[i].dateSale << " " << sales[i].dateDelivery;
			}
			else
			{
				file << sales[i].product.id << " " << sales[i].product.name << " " << sales[i].product.unit << " " << sales[i].product.commisia << " " << sales[i].client.id << " " << sales[i].client.surname << " " << sales[i].client.name << " " << sales[i].client.patronymic << " " << sales[i].client.pasport << " " << sales[i].count << " " << sales[i].dateSale << " " << sales[i].dateDelivery << endl;
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
			ss >> product.id >> product.name >> unit >> product.commisia >> client.id >> client.surname >> client.name >> client.patronymic >> client.pasport >> sale.count >> sale.dateSale >> sale.dateDelivery;
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
	cout << "3. Залог" << endl;
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
		cout << "3. Залог" << endl;
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
				cout << "Залог найден!" << endl;
				cout << products[i].id << ". " << products[i].name << " - " << (products[i].unit == Unit::OneHUNDRED ? "100 рублей" : products[i].unit == Unit::ThreeHUNDRED ? "300 рублей" : products[i].unit == Unit::FiveHUNDRED ? "500 рублей" : "700 рублей") << " - " << products[i].commisia << endl;
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
				cout << clients[i].id << ". " << clients[i].surname << " " << clients[i].name << " " << clients[i].patronymic << " - " << clients[i].pasport << endl;
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
				cout << "Залог найден!" << endl;
				cout << sales[i].product.id << ". " << sales[i].product.name << " - "  << (sales[i].product.unit == Unit::OneHUNDRED ? "рублей" : sales[i].product.unit == Unit::ThreeHUNDRED ? "рублей" : sales[i].product.unit == Unit::FiveHUNDRED ? "рублей" : "рублей") << " - " << sales[i].product.commisia << " - " << sales[i].client.surname << " " << sales[i].client.name << " " << sales[i].client.patronymic << " - " << sales[i].client.pasport << " - " << sales[i].count << " - " << sales[i].dateSale << " - " << sales[i].dateDelivery << endl;
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
				cout << products[i].id << ". " << products[i].name << " - " << (products[i].unit == Unit::OneHUNDRED ? "100 рублей" : products[i].unit == Unit::ThreeHUNDRED ? "300 рублей" : products[i].unit == Unit::FiveHUNDRED ? "500 рублей" : "700 рублей") << " - " << products[i].commisia << endl;
				cout << "Введите новое название товара: ";
				cin >> products[i].name;
				cout << "Введите новую цену товара( 1 -100, 2 - 300, 3 - 500, 4 - 700): ";
				int unit;
				cin >> unit;
				products[i].unit = (Unit)unit;
				cout << "Введите новые комиссионные: ";
				cin >> products[i].commisia;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore(32767, '\n');
					cout << "Комиссионные товара должны быть числом!" << endl;
					cout << "Введите новые комиссионные: ";
					cin >> products[i].commisia;
				}
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
				cout << clients[i].id << ". " << clients[i].surname << " " << clients[i].name << " " << clients[i].patronymic << " - " << clients[i].pasport << endl;
				cout << "Введите новую фамилию клиента: ";
				cin >> clients[i].surname;
				cout << "Введите новое имя клиента: ";
				cin >> clients[i].name;
				cout << "Введите новое отчество клиента: ";
				cin >> clients[i].patronymic;
				cout << "Введите новый паспорт клиента: ";
				cin >> clients[i].pasport;
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
				cout << products[i].id << ". " << products[i].name << " - " << (products[i].unit == Unit::OneHUNDRED ? "рублей" : products[i].unit == Unit::ThreeHUNDRED ? "рублей" : products[i].unit == Unit::FiveHUNDRED ? "рублей" : "рублей") << " - "  << products[i].commisia << endl;
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
				cout << clients[i].id << ". " << clients[i].surname << " " << clients[i].name << " " << clients[i].patronymic << " - " << clients[i].pasport << endl;
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

// Функция меню
void Menu()
{
	cout << "Выберите действие: " << endl;
	cout << "1. Добавить товар (Lab2)" << endl;
	cout << "2. Добавить клиента (Lab2)" << endl;
	cout << "3. Создать залог (Lab2)" << endl;
	cout << "4. Просмотреть список товаров (Lab2)" << endl;
	cout << "5. Просмотреть список клиентов (Lab2)" << endl;
	cout << "6. Просмотреть список залогов (Lab2)" << endl;
	cout << "7. Сохранение залогов в файл (Lab5)" << endl;
	cout << "8. Загрузка залогов из файла (Lab5)" << endl;
	cout << "9. Поиск товара или клиента  (Lab4)" << endl;
	cout << "10. Изменение товара или клиента (Lab6)" << endl;
	cout << "11. Удаление товара или клиента (Lab6)" << endl;
	cout << "12. Удаление всех товаров или клиентов (Lab6)" << endl;
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
		default:
			cout << "Неверный номер!" << endl;
			break;
		}
	}
}