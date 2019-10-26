#include <iostream>
void main()
{
	using namespace std;
	int b = 2, j = 6, n;
	int i[4] = { 7,4,2,6 };
	double a = 1.5e8, y, t;
	for (n = 0; n < 4; n++)
	{
		y = a / (b + exp(b)) / (1 + j * i[n]);
		t = cos(y + 1) / sqrt(abs(-2 * j));
		cout << "y = " << y << " t = " << t << endl;
	}
	system("pause");
}
