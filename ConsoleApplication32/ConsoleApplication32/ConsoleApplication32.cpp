#include "pch.h"
#include <iostream>
#include <ctime>
#include <locale>
using namespace std;
void main()
{
	float max, A[100], sum = 0, a, b; int n, cnt = 0;
	cout << "n="; cin >> n;
	cout << "a="; cin >> a;
	cout << "b="; cin >> b;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]="; cin >> A[i];
		if ((A[i] > a) && (A[i]) < b)
			cnt = cnt + 1;
	}
	cout << "\ncnt =" << cnt;
	max = A[0];
	for (int i = 1; i < n; i++)
	{
		if (max < A[i])
		{
			max = A[i];
			cnt = i;
		}
	}
	for (int i = cnt; i < n; i++)
	{
		sum = sum + A[i];
	}
	cout << "\ncnt=" << sum << "\n";
}
