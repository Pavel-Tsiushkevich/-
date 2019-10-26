#include<iostream>
using namespace std;
void main()
{
	float x, y = 0, max = -999999;
	for (int i = 0; i < 5; i++)
	{
		cout << "x" << i + 1 << "= "; cin >> x;
		if (x > max)
			max = x;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << "x" << i + 1 << "= "; cin >> x;
		y = y + (x*x+(max + 1));
	}
	cout << "\n" << "answer: " << y << "\n";
	system("pause");
}