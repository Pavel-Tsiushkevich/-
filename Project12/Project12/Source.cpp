#include<iostream>
#include<string>
#include<Windows.h>

using namespace std;

void zadanie_1()
{
	cout << "__________________________________________\n���������� ������� 1\n";
	int *arr, size, min = 99999, mem_min, sum_abs_min = 0; bool b = false;
	cout << "������� ������ �������: "; cin >> size;
	arr = new int[size];
	cout << "Array: ";
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 20 - 11;
		cout << arr[i] << " ";
		if (abs(arr[i]) < min)
		{
			min = abs(arr[i]);
			mem_min = i + 1;
		}
		if (arr[i] < 0);
		b = true;
		if (b == true)
			sum_abs_min += arr[i];
	}
	cout << "\n������ ������������ �� ������ ��������: " << mem_min << endl;
	cout << "\n����� ����������� ��������� �� ������: " << abs(sum_abs_min) << endl;
	cout << "���������� ���������\n_________________________________________\n";
	delete[]arr;
}

void zadanie_2()
{
	cout << "__________________________________________\n���������� ������� 2\n";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string str;
	cout << "������� ������: ";
	cin.ignore(1);
	getline(cin, str);
	if (str.find('����'))
		cout << "����� ���� � ������ �������\n";
	else
		cout << "����� ���� ��� � ������" << endl;
	cout << "���������� ���������\n_________________________________________\n";

}

int main()
{
	setlocale(0, "");
	int choice;
	do
	{
		cout << "�������� ����� �������:\n������� 1 - '1'\n������� 2 - '2'\n����� - '3'\n����: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			zadanie_1();
		}
		case 2:
		{
			zadanie_2();
		}
		case 3:
		{
			cout << "\n����� ���������� ������������\n__________________________________________\n";
		}
		}
	} while (choice != 3);
	system("pause");
}
