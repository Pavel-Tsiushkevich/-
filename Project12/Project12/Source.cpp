#include<iostream>
#include<string>
#include<Windows.h>

using namespace std;

void zadanie_1()
{
	cout << "__________________________________________\nВыволнение задания 1\n";
	int *arr, size, min = 99999, mem_min, sum_abs_min = 0; bool b = false;
	cout << "Введите размер массива: "; cin >> size;
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
	cout << "\nИндекс минимального по модулу элемента: " << mem_min << endl;
	cout << "\nСумма минимальных элементов по модулю: " << abs(sum_abs_min) << endl;
	cout << "Выполнение завершено\n_________________________________________\n";
	delete[]arr;
}

void zadanie_2()
{
	cout << "__________________________________________\nВыволнение задания 2\n";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string str;
	cout << "Введите строку: ";
	cin.ignore(1);
	getline(cin, str);
	if (str.find('БГТУ'))
		cout << "Слово БГТУ в строке имеется\n";
	else
		cout << "Слова БГТУ нет в строке" << endl;
	cout << "Выполнение завершено\n_________________________________________\n";

}

int main()
{
	setlocale(0, "");
	int choice;
	do
	{
		cout << "Выберите номер задания:\nЗадание 1 - '1'\nЗадание 2 - '2'\nВыход - '3'\nВвод: ";
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
			cout << "\nКонец выполнения лабораторной\n__________________________________________\n";
		}
		}
	} while (choice != 3);
	system("pause");
}
