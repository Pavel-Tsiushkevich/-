#include "pch.h"
#include <iostream>
void main()
{
	using namespace std;
	int j = 6, i = 3, n;
	double a[3] = { 0.1,-1, 3 }, b = 2.4, y, t;
	for (n = 0; n < 3; n++);
	{ do
	{
		y = (a[n]) / (b + exp(b)) / (1 + (j*i));
		t = cos(y + 1) / sqrt(abs(-2 * j));
		cout << "y = " << y << " t = " << t << endl;
		b = b + 0.2;
	} while (b < 2.9);
	}
}