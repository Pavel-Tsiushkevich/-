#include "pch.h"
#include <iostream>
int main()
{
	using namespace std;
	float y1, x2, y2, mn;
	cin >> y1;
	cin >> x2;
	cin >> y2;
	if (y1 + x2 * y2 > y1 + x2 + y2)
		mn = y1 + x2 + y2;
	else
	{
		if (y1 + x2 * y2 > y2)
			mn = y2;
		else
			mn = y1 + x2 * y2;

	}
	mn = mn + 5;
	cout << mn;
}