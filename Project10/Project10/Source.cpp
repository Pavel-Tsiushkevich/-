#include <iostream>
using namespace std;
void main()
{
	char s[30], s1[30];
	int i, b = 0, k = 0, a, l = 0, t = 0;
	gets_s(s);
	for (i = 0; s[i] != '\0'; i++)
	{
		t++;
	}
	for (i = 0; i <= t + 1; i++)
	{
		k++;
		if (s[i] == ' ' || s[i] == '\0')
		{
			if (k > b)
			{
				b = (k - 1);
				a = i;
			}
			k = 0;
		}
	}
	for (i = (a - b); i < a; i++)
	{
		s1[l] = s[i];
		l++;
	}
	cout << s1 << endl;
	system("pause");
}