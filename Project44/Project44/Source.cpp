#include <iostream>
#include <Windows.h>
using namespace std;
#define size 5

enum gender
{
	maskulan, femenum
};

struct date
{
	unsigned short day : 8;
	unsigned short month : 8;
	unsigned short year : 8;
};

struct peaples
{
	char last_name[12];
	char name[12];
	char second_name[12];
	date data;
	char adress[20];
	int gend;
};

struct peaples list_of_peaples[size];
struct peaples bad;
int current_size = 0; int choice;

void input_data();
void output_data();
void delete_data();
void search_data();

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "1 - запись" << endl;
	cout << "2 - просмотр" << endl;
	cout << "3 - удаление" << endl;
	cout << "4 - поиск" << endl;
	cout << "Ваш выбор: " << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1: input_data();
			break;
		case 2: output_data();
			break;
		case 3: delete_data();
			break;
		case 4: search_data();
			break;
		default:
			break;
		}
	} while (choice != 0);
}



void input_data()
{
	int amt;
	int t;
	cout << "Количество добавляемых позиций: ";
	cin >> amt;
	for (int i = current_size; i < current_size + amt; i++)
	{
		cout << "\nФ.И.О.:\n" << endl;
		cin >> list_of_peaples[i].last_name;
		cin >> list_of_peaples[i].name;
		cin >> list_of_peaples[i].second_name;
		cout << "Адрес: ";
		cin >> list_of_peaples[i].adress;
		cout << "Дата рождения:" << endl;
		cout << "день: "; cin >> t; list_of_peaples[i].data.day = t;
		cout << "месяц: "; cin >> t; list_of_peaples[i].data.month = t;
		cout << "год: "; cin >> t; list_of_peaples[i].data.year = t;
		cout << "Пол (0 - мужской, 1 - женский): ";
		cin >> list_of_peaples[i].gend;
	}
	current_size += amt;
	cout << "\nСледующий выбор: ";
	cin >> choice;
}

void output_data()
{
	for (int i = 0; i < current_size; i++)
	{
		cout << "\nФ.И.О: " << list_of_peaples[i].last_name << " " << list_of_peaples[i].name << " " << list_of_peaples[i].second_name << endl;
		cout << "Адрес: " << list_of_peaples[i].adress << endl;
		cout << "Дата рождения: " << list_of_peaples[i].data.day << "." << list_of_peaples[i].data.month << "." << list_of_peaples[i].data.year << endl;
		cout << "Пол: ";
		switch (list_of_peaples[i].gend)
		{
		case 1: cout << "женский";
		case 0: cout << "мужской";
		default:
			break;
		}
	}
	cout << "\nСледующий выбор: ";
	cin >> choice;
}

void delete_data()
{
	int client;
	cout << "Информацию о человеке под каким номером вы хотите удалить?" << endl;
	cout << "Выбор: ";
	cin >> client;
	for (int i = client - 1; i < current_size - 1; i++)
	{
		list_of_peaples[i] = list_of_peaples[i + 1];
		if (current_size - 1 == i)
		{
			list_of_peaples[i + 1] = bad;
			current_size--;
		}
	}
	cout << "\nСледующий выбор: ";
	cin >> choice;
}

void search_data()
{
	int q, w, e;
	cout << "Введите дату рождения:" << endl;
	cout << "День: "; cin >> q;
	cout << "Месяц: "; cin >> w;
	cout << "Год: "; cin >> e;
	for (int i = 0; i < current_size; i++)
	{
		if (q == list_of_peaples[i].data.day &&
			w == list_of_peaples[i].data.month &&
			e == list_of_peaples[i].data.year)
		{
			cout << "\nФ.И.О: " << list_of_peaples[i].last_name << " " << list_of_peaples[i].name << " " << list_of_peaples[i].second_name << endl;
			cout << "Адрес: " << list_of_peaples[i].adress << endl;
			cout << "Дата рождения: " << list_of_peaples[i].data.day << "." << list_of_peaples[i].data.month << "." << list_of_peaples[i].data.year << endl;
			cout << "Пол: ";
			switch (list_of_peaples[i].gend)
			{
			case 1: cout << "женский";
				break;
			case 0: cout << "мужской";
				break;
			default:
				break;
			}
		}
	}
	cout << "\nСледующий выбор: ";
	cin >> choice;
}
