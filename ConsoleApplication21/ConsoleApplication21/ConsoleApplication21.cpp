#include "pch.h"
#include <iostream>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	int a = 100, x, y, z, y1;
	while (a < 1000)
	{
		x = a / 100;
		y1 = a / 10;
		y = y1 % 10;
		z = a % 10;
		if (x != y && y != z && x != z)
		{
			cout << a << endl;
		}
		a++;
	}
}