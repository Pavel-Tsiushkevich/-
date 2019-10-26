
#include "Hash_ Twin_Chain.h"
#include <iostream>
#include <string>
using namespace std;
struct ROW
{
	char* number;
	char* name;
	ROW(char*z, char*n)

	{
		number = z;
		name = n;
	}
	ROW()
	{
		number = (char*)""; name = (char*) "";
	}
};

char* getkeyfromROW(void* d)
// функция получения ключа по У-лю на произвольные данные
{
	ROW* f = (ROW*)d; // преобразуем У-ль на произвольные данные d в У-ль f на структуру ROW 
	return f->number; // возвращаем ключ структуры ROW по указателю f
}

void ROW_print(listx::Element* e) // функция вывода 1 Э-а списка по У-лю на этот Э-т
{
	cout << '\t' << ((ROW*)e->Data)->number << " - " << ((ROW*)e->Data)->name << endl;
}

int _tmain(int argc, TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	system("chcp 1251");
	int current_size;	// размер хэш-таблицы (количество списков в ней)
	cout << "Введите размер хэш-таблицы" << endl;
	cin >> current_size;
	hashTC::Object H = hashTC::Create(current_size, getkeyfromROW);
	int choise;
	char k[100];
	for (;;)
	{
		cout << "Меню:" << endl;
		cout << "1 - Вывод всего списка парковочных мест " << endl;
		cout << "2 - Добавление нового парковочного места" << endl;
		cout << "3 - Удаление парковочного места" << endl;
		cout << "4 - Поиск по парковочному месту" << endl;
		cout << "0 - Выход" << endl;
		cout << "сделайте выбор" << endl; cin >> choise;
		switch (choise) {
		case 0: exit(0);
		case 1: H.Scan(ROW_print);  break;
		case 2:
		{
			char *str = new char[20];
			char *nstr = new char[200];
			cout << "Введите номер места" << endl;
			cin >> str;
			cout << "Введите имя владельца" << endl;
			cin >> nstr;
			ROW *a = new ROW(str, nstr);
			H.Insert(a);
		}  break;
		case 3: {
			cout << "Введите номер места для удаления" << endl;
			cin >> k;
			H.Delete(k); } break;
		case 4: {cout << "Введите номер места для поиска" << endl;
			cin >> k;
			if (H.Search(k) == NULL)
				cout << "Элемент не найден" << endl;
			else  ROW_print(H.Search(k)); }
				break;
		}
	}
	return 0;
}
