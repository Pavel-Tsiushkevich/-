// вычеслить s=1/2x+1/3x+...+1/nx где n=4 x=2(2)10
#include "pch.h"
#include <iostream>
int main()
{
	using namespace std;
	setlocale(0, " ");
	float s = 0, x=2;
	do
	{
		x = 2;
		for(int n = 2; n <= 4; n++)
		{ 
		{
			
			x = x + 2;
			s = s + 1 / (x*n);
			
			cout << "s=" << s << "\t x=" << x << endl;
		} while (x < 10);

	}
}