
#include <iostream>
using namespace std;

float f1(float x)
{
	return exp(x) + x - 4;
}

float f2(float x)
{
	return x * x - 4;
}

float res(float(*fun) (float x), float a, float b, float e)
{
	float x;
	x = (a + b) / 2;
	while (abs(a - b) > 2 * e)
	{
		x = (a + b) / 2;
		if ((fun(x) * fun(a)) <= 0)
			b = x;
		else  a = x;
	}
	return x;
}


int main()
{
	setlocale(0, "");
	float a = 1, b = 2, e = 0.001;
	cout << "Корень уравнения 1 при а = " << a << ", b = " << b << " равен: " << res(f1, a, b, e) << endl;
	cout << "Корень уравнения 2 при a = " << a << ", b = " << a << " равен: " << res(f2, a, b, e) << endl;
	system("pause");

	return 0;
}
