#include <iostream>
using namespace std;
int main()
{
	int n;
	double j[4] = { 9, 1.8, 15, -3 };
	double r = 4e-4, y, h, c = 2.1,m=1;
	for (n=1;n<=4;n++)
	{
		do
		{
			h = (10 * r - j[n]) / (pow(c, 2) + exp(-m));
			y = (h * m - pow(j[n], 2)) + pow(0.1*c, 2);
			m = m + 0.5;
			cout << "y = " << y << " j = " << j <<" m = "<<m<< endl;
		} 
		while (m < 2.5);
	}
	system("pause");
}