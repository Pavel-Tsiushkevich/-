#include <iostream>

#include <Windows.h>

#include <fstream>

using namespace std;

#define size 5



enum gender

{

	maskulan, femenum

};



//	������� ����

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



	cout << "���������� ����������� �������: ";

	cin >> amt;



	//	���� ���������

	for (int i = 0; i < amt; i++)

	{

		cout << "\n��� ������:" << endl;

		cin >> list_of_tovar[i].name_tovar;

		cout << "���������: ";

		cin >> list_of_tovar[i].cost;

		cout << "���� �����������:" << endl;

		cout << "����: "; cin >> t; list_of_tovar[i].data.day = t;

		cout << "�����: "; cin >> t; list_of_tovar[i].data.month = t;

		cout << "���: "; cin >> t; list_of_tovar[i].data.year = t;

	}

	current_size += amt;



	//	������ � ����

	if (current_size != 0)

	{

		ofstream file_write("tovar.txt");

		if (!file_write)

			cout << "error open file tovar.txt" << endl;

		else

		{

			for (int i = 0; i < current_size; i++)

			{

				file_write << "������������ ������: " << list_of_tovar[i].name_tovar << endl;

				file_write << "���������: " << list_of_tovar[i].cost << endl;

				file_write << "���� ��������: " << list_of_tovar[i].data.day << "." << list_of_tovar[i].data.month << "." << list_of_tovar[i].data.year << endl;

			}

			cout << "������ ������� ��������" << endl;

		}

		file_write.close();

	}

	else

		cout << "���������� ��� ������ �� �������" << endl;



	//	����� ������

	char name_search[20];

	cout << "\n������� ��� ������ ��� ������:" << endl;

	cin >> name_search;

	for (int i = 0; i < current_size; i++)

	{

		if (strcmp(name_search, list_of_tovar[i].name_tovar))

		{

			cout << "������������ ������: " << list_of_tovar[i].name_tovar << endl;

			cout << "���������: " << list_of_tovar[i].cost << endl;

			cout << "���� ��������: " << list_of_tovar[i].data.day << "." << list_of_tovar[i].data.month << "." << list_of_tovar[i].data.year << endl;



		}

	}



	system("pause");

}