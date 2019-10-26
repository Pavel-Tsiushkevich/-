#include <iostream>

#include <Windows.h>

#include <fstream>

using namespace std;

#define size 5



enum gender

{

	maskulan, femenum

};



//	Битовое поле

struct date

{

	unsigned short day : 8;

	unsigned short month : 8;

	unsigned short year : 8;

};



struct tovar

{

	char name_tovar[20];

	int cost;

	date data;

};



struct tovar list_of_tovar[size];



void main()

{

	int current_size = 0;

	SetConsoleCP(1251);

	SetConsoleOutputCP(1251);

	int amt;

	int t;



	cout << "Количество добавляемых позиций: ";

	cin >> amt;



	//	Ввод структуры

	for (int i = 0; i < amt; i++)

	{

		cout << "\nИмя товара:" << endl;

		cin >> list_of_tovar[i].name_tovar;

		cout << "Стоимость: ";

		cin >> list_of_tovar[i].cost;

		cout << "Дата поступления:" << endl;

		cout << "день: "; cin >> t; list_of_tovar[i].data.day = t;

		cout << "месяц: "; cin >> t; list_of_tovar[i].data.month = t;

		cout << "год: "; cin >> t; list_of_tovar[i].data.year = t;

	}

	current_size += amt;



	//	Запись в фвйл

	if (current_size != 0)

	{

		ofstream file_write("tovar.txt");

		if (!file_write)

			cout << "error open file tovar.txt" << endl;

		else

		{

			for (int i = 0; i < current_size; i++)

			{

				file_write << "Наименование товара: " << list_of_tovar[i].name_tovar << endl;

				file_write << "Стоимость: " << list_of_tovar[i].cost << endl;

				file_write << "Дата прибытия: " << list_of_tovar[i].data.day << "." << list_of_tovar[i].data.month << "." << list_of_tovar[i].data.year << endl;

			}

			cout << "Данные успешно записаны" << endl;

		}

		file_write.close();

	}

	else

		cout << "Информации для записи не найдено" << endl;



	//	Поиск товара

	char name_search[20];

	cout << "\nВведите имя товара для поиска:" << endl;

	cin >> name_search;

	for (int i = 0; i < current_size; i++)

	{

		if (strcmp(name_search, list_of_tovar[i].name_tovar))

		{

			cout << "Наименование товара: " << list_of_tovar[i].name_tovar << endl;

			cout << "Стоимость: " << list_of_tovar[i].cost << endl;

			cout << "Дата прибытия: " << list_of_tovar[i].data.day << "." << list_of_tovar[i].data.month << "." << list_of_tovar[i].data.year << endl;



		}

	}



	system("pause");

}