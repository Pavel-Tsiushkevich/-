#include "pch.h"
#include <iostream>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	char c;
	cout << "Введите символ";
	cin >> c;
	cout << " " <<" "<<" "<< c << endl;
	cout << " "<<" "<< c << c << c << endl;
	cout << " " << c << c << c << c << c << endl;
	cout << " " <<" "<< c << c << c << endl;
	cout << " " <<" "<<" "<< c << endl;
}