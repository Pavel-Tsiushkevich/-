#include "pch.h"
#include <iostream>
void main()
{
	using namespace std;
	int n;
	double x = 0;
	for (n = 1; n < 1000; n++)
	{
		if (n % 2 == 0)
		{
			x += n;
		}
	}
	cout << x << endl;
}