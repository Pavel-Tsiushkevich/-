#include "pch.h"
#include <iostream>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	float m = 9999, x, n = 1;
	for (int i;i=1;i<6;i++)
	{
		cout << "Введите x" << i << endl;
		cin >> x;
		if(x<m)
		{
			m = x;
			n = i;
		}
	}
	cout << m << endl;
	cout << n << endl;

}