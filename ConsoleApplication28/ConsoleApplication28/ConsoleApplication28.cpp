#include "pch.h"
#include <iostream>
int main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	float m = 9999, x, n;
	for (int i; i = 1; i < 6; i++)
	{
		cout << "Введите x" << n << endl;
		cin >> x;
		if (x < m)
		{
			m = x;
			n = i;
		}
	}
	cout << m << endl;
	cout << n << endl;
}