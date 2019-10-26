#include<iostream>
#include<stdio.h>
using namespace std;
void main()
{
	char s[100]; int A[100], q = 1;
	A[0] = 0;
	cout << "input string: "; gets_s(s);
	for (int i = 0; i < strlen(s); i++)
	{
		if (*(s + i) == ' ')
		{
			*(A + q) = i; q++;
		}
	}
	*(A + q) = strlen(s); q++;
	cout << "Answer: ";
	for (int i = 1; i < q; i++)
	{
		if (*(s + *(A + i) - 1) == '0' ||
			*(s + *(A + i) - 1) == '2' ||
			*(s + *(A + i) - 1) == '4' ||
			*(s + *(A + i) - 1) == '6' ||
			*(s + *(A + i) - 1) == '8')
		{
			for (int j = *(A + i - 1); j < *(A + i); j++)
				cout << *(s + j);
			cout << " ";
		}
	}
	system("pause");
}
