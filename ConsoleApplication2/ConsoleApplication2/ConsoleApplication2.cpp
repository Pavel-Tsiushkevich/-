#include "pch.h"
#include <iostream> 
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	double p, y, x = 3, b = 5;
	while (x <= 4)
	{
		p = 2 * b*exp(x + 1) + sin(x)*sin(x);
		y = p + pow(x, (float)1 / 3);
		cout << "x =" << x << endl;
		cout << "y =" << y << endl;
		x = x + 0.1;
	}