#include "pch.h"
#include <iostream>
#include <ctime>
#include <locale>
using namespace std;
void main()
{
	int i, j, n = 0;
	double x[100], y[90];
	srand((unsigned)time(NULL));
	for (i = 0; i < 100; i++)
	{
		*(x + i) = rand() % 200;
	}
	for (j = 0; j < 90; j++)
	{
		*(y + j) = rand() % 100;
	}
	for (i = 0; i < 100; i++)
	{
		j = 0;
		for (j; j < 90; j++)
		{
			if (*(x + i) == *(y + j))
			{
				n++;
				break;
			}
		}
	}
	cout << n << endl;
}