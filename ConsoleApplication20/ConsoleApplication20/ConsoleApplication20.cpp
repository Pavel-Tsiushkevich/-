#include "pch.h"
#include <iostream>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	int n = 0;
	double s = 5.2, x[4] = { 5, 0.4, -2.1, 6 }, j = 10.4*exp(4), v;
	while (n < 4)
	{
		if (2 * s > x[n] * j) v = (cos(j*x[n]))*exp(2);
		else if (2 * s < x[n] * j) v = 2 * tan(j*x[n]);
		else v = 5 - exp(x[n] / 2);
		n++;
		cout << "v = " << v << endl;
	}
}