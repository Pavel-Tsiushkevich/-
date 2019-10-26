#include <iostream>
#include <Windows.h>
#define size 5
using namespace std;

struct vokzal
{
	int nomer;
	char point[20];
	char dni[5];
	char time[5];
	char time_start[5];
};

struct vokzal list[size];
struct vokzal bad;

int current_size = 0;
int choice;

void input_data();
void output();
void delete_data();
void search_data();

void main()
{
	cout << "1 - input data" << endl;
	cout << "2 - output data" << endl;
	cout << "3 - delete data" << endl;
	cout << "4 - search" << endl;
	cout << "choice - " << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:	input_data();
			break;
		case 2:	output();
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
	cout << "amt position: ";
	cin >> amt;
	for (int i = current_size; i < current_size + amt; i++)
	{
		cout << "\nnomer: ";
		cin >> list[i].nomer;
		cout << "point: ";
		cin >> list[i].point;
		cout << "dni: ";
		cin >> list[i].dni;
		cout << "time end: ";
		cin >> list[i].time;
		cout << "sime start: ";
		cin >> list[i].time_start;
	}
	current_size += amt;
	cout << "\nnext: ";
	cin >> choice;
}

void output()
{
	for (int i = 0; i < current_size; i++)
	{
		cout << "\nnomer: " << list[i].nomer << endl;
		cout << "point: " << list[i].point << endl;
		cout << "dni: " << list[i].dni << endl;
		cout << "time end: " << list[i].time << endl;
		cout << "sime start: " << list[i].time_start << endl;
	}
	cout << "\nnext: ";
	cin >> choice;
}

void delete_data()
{
	int client;
	cout << "Информацию о поезде?" << endl;
	cout << "Выбор: ";
	cin >> client;
	for (int i = client - 1; i < current_size - 1; i++)
	{
		list[i] = list[i + 1];
		if (current_size - 1 == i)
		{
			list[i + 1] = bad;
			current_size--;
		}
	}
	cout << "\nnext: ";
	cin >> choice;
}

void search_data()
{
	char buff[20];
	cout << "input search point: ";
	cin >> buff;
	for (int i = 0; i < current_size; i++)
	{
		if (strcmp(buff, list[i].point))
		{
			cout << "\nnomer: " << list[i - 1].nomer << endl;
			cout << "point: " << list[i - 1].point << endl;
			cout << "dni: " << list[i - 1].dni << endl;
			cout << "time end: " << list[i - 1].time << endl;
			cout << "sime start: " << list[i - 1].time_start << endl;
		}
	}
	cout << "\nnext: ";
	cin >> choice;
}
