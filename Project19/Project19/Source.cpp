/*1. ������� �� ������� ��� ��������, ����������� � ��� ����������� ���������. �������� � ������ ������� ��� �������� �� ���������, ������ �������� ��������������� �������. 
2. ����� ������ �� k ��������. ������������� ������ ��������� �������: ����������� ���-���� � �������� �������. */
#include <iostream>
using namespace std;
int main()
{
	const int k = 10;
	char c[k];
	for (int i = 0; i < k; i++)
		cin >> c[i];

	for (int i = 0; i < k / 2; i++)
	{
		char x = c[i];
		c[i] = c[k - 1 - i];
		c[k - 1 - i] = x;
	}

	for (int i = 0; i < k; i++)
		cout << c[i];
	system("pause");
}