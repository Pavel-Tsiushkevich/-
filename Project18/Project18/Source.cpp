#include <iostream>
using namespace std;
int main()
{
	int m = 7, n;
	double r = 4e-4, y, h, c = 2.1, j[3] = { 4.2,0.3,1.7 };
	for (n = 1; n <= 3; n++)
	{
		h = (10 * r - j[n]) / (pow(c, 2) + exp(-m));
		y = (h * m - pow(j[n], 2)) + pow(0.1*c, 2);
		cout << "y = " << y << " j = " << j << endl;
	}
	system("pause");
}

