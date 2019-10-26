#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

int compress(char * text);//объ€вление функции
const int strsize = 40;//размер строки

int main()
{
	SetConsoleCP(1251);//кодировка ввода
	SetConsoleOutputCP(1251);//кодировка вывода

	char text[strsize] = "текст с пробелами был";//исходный текст
	int size = compress(text);//вызываем функцию котора€ возвращает сжатый текст
	cout << endl;//перевод строки
	for (int i = 0; i < size; i++)//затем до конца строки без пробелов
	{
		cout << text[i];//выводим на экран
	}
	_getch();
	return 0;
}

int compress(char * text)
{
	char * buf = new char[strlen(text)];//получив строку, создаем такую же
	int b = 0;// мчетчик символов в новой строке
	for (int i = 0; i < strlen(text); i++)//по всем символам строки text
	{
		if (text[i] == ' ')//если пробел
			continue;//то пропускаем всЄ
		else//иначе
		{
			buf[b] = text[i];//записываем в новую строку
			b++;//и ставим позицию ввода на следующий символ
		}
	}
	strcpy(text, buf);//после отсеивани€ всех пробелов копируем полученную строку в исходную
	return b;//возвращаем длину
}