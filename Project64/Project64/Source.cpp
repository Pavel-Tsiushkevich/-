#include <iostream> 
using namespace std;

int fun1(int m, int n)
{
	int p = 0;
	if (m == 1 || n == 1)
	{
		return 1;
	}

	if (n == m)
	{
		return (fun1(m, m - 1) + 1);// 
	}

	if (n < m)
	{
		return (fun1(m, n - 1) + fun1(m - n, n));// 
	}
	if (n > m)
	{
		return fun1(m, m);
	}
}
void main()
{
	int  m, n;
	
	
	cout << "m = ";
	cin >> m;
	cout << "n = ";
	cin >> n;
	cout << "p(m,n) = " << fun1(m, n) << endl;
	system("pause");
}