#include "pch.h"
#include <iostream>
void main()
{
	using namespace std;
	int b = 4, n = 200, i = 1;
	double a = 1, h, x, s1 = 0, s2 = 0, z;
	h = (b - a) / (2 * n);
	x = a + 2 * h;
	for (i; i < n; i++)
	{
		s2 += pow(x, 4) + 4;
		x += h;
		s1 += pow(x, 4) + 4;
		x += h;
	}
	z = (pow(a, 4) + 4 + 4 * (pow(a + h, 4) + 4) + 4 * s1 + 2 * s2 + pow(b, 4) + 4)*h / 3;
	cout << "z = " << z << endl;
}
