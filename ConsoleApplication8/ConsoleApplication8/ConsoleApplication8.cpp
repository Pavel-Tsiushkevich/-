#include "pch.h"
#include <iostream>
#include <iomanip> 
using namespace std;
int main()
{
	{
		setlocale(LC_CTYPE, "Russian");
		char c, probel; probel = ' ';
		cout << "Введите символ "; cin >> c;
		cout << setw(39) << setfill(probel) << probel;
		cout << setw(2) << setfill(c) << c << endl;
		cout << setw(38) << setfill(probel) << probel;
		cout << setw(4) << setfill(c) << c << endl;
		cout << setw(37) << setfill(probel) << probel;
		cout << setw(6) << setfill(c) << c << endl;
		cout << setw(36) << setfill(probel) << probel;
		cout << setw(8) << setfill(c) << c << endl;
		cout << setw(35) << setfill(probel) << probel;
		cout << setw(10) << setfill(c) << c << endl;
		cout << setw(34) << setfill(probel) << probel;
		cout << setw(12) << setfill(c) << c << endl;
		cout << setw(33) << setfill(probel) << probel;
		cout << setw(14) << setfill(c) << c << endl;
	}
	setlocale(LC_CTYPE, "Russian");
	char b, pribel; probel = ' ';
	cout << "Введите символ"; cin >> b;
	cout << setw(32) << setfill(probel) << probel;
	cout << setw(12) << setfill(b) << b << endl;
}
