//Библиотека(автор, название, раздел библиотеки - специальная литература, хобби, домашнее хозяйство, беллетристика и так далее).
//Выбор книг по названию.Раздел библиотеки реализовать с помощью перечисления.Запись в файл и считывание организовать с помощью средств языка С++.



#include <iostream>
#include <fstream>
using namespace std;
struct Library
{
	char autor[30];
	char title[30];
	char group[30];

};
int main()
{

	int s, i = 0;
	char a[100];
	setlocale(LC_ALL, "Russian");
	Library book1 = { "Гоголь","Мёртвые души","Специальная литература" };
	Library book2 = { "Фифа","Футбол","Хобби" };
	Library book3 = { "Конор","Чудесная уборка","Домашнее хозяйство" };
	Library book4 = { "Пушкин","Еввений Онегин","Беллетристика" };
	Library book5 = { "Соболев","Путь к успеху","Хит продаж" };
	Library book6 = { "Абулт свим","Рик и Морти","Зарубежная литература" };
	Library book7 = { "Сыендук","Линтяиус","Набирающее популярность" };
	Library book8 = { "Портер","Не дыши","Новое издание" };


	do
	{

		cout << "Выберите книгу:" << endl << "(1-Мёртвые души, 2-Футбол,3-Магическая уборка, 4-Евгений Онегин, 5-Путь к успеху, 6-Рик и Морти, 7-Линтяиус, 8-Не дыши)" << endl;
		cin >> s;
		ofstream file("f.txt");
		switch (s)
		{
		case 1: file << book1.autor << ": " << book1.title << ". Раздел библиотеки - " << book1.group; break;
		case 2: file << book2.autor << ": " << book2.title << ". Раздел библиотеки - " << book2.group; break;
		case 3: file << book3.autor << ": " << book3.title << ". Раздел библиотеки - " << book3.group; break;
		case 4: file << book4.autor << ": " << book4.title << ". Раздел библиотеки - " << book4.group; break;
		case 5: file << book5.autor << ": " << book5.title << ". Раздел библиотеки - " << book5.group; break;
		case 6: file << book6.autor << ": " << book6.title << ". Раздел библиотеки - " << book6.group; break;
		case 7: file << book7.autor << ": " << book7.title << ". Раздел библиотеки - " << book7.group; break;
		case 8: file << book8.autor << ": " << book8.title << ". Раздел библиотеки - " << book8.group; break;
		default: cout << "Такой книги нет."; break;
		}
		file.close();
		ifstream file1("f.txt");
		file1.getline(a, 100);
		file.close();
		cout << endl << a << endl;
		cout << endl << "Желаете продолжить? " << endl << "(1 - Да, 0 - Нет)" << endl;
		cin >> i;

	} while (i);
	system("pause");
}