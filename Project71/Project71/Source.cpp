
#include <iostream>
#include <time.h>
using namespace std;
int i, j, count, key;
//Сортировка разделением
int GetHoarBorder(int m[], int sm, int em)
{
	int i = sm - 1, j = em + 1;
	int brd = m[sm];
	int buf;
	while (i < j)
	{
		while (m[--j] > brd);
		while (m[++i] < brd);
		if (i < j)
		{
			buf = m[j]; m[j] = m[i]; m[i] = buf;
		}
	}
	return j;
};
int* SortHoar(int m[], int sm, int em)
{
	if (sm < em)
	{
		int hb = GetHoarBorder(m, sm, em);
		SortHoar(m, sm, hb);
		SortHoar(m, hb + 1, em);
	}
	return m;
};
//Сортировка пузырьком
void BubbleSort(int a[], int n)
{
	int i, j, t;
	for (i = 1; i < n; i++)
		for (j = n - 1; j >= i; j--)
			if (a[j - 1] > a[j])
			{
				t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;
			}
}

void main()
{
	setlocale(LC_ALL, "Rus");
	srand((unsigned)time(NULL));
	int N;
	cout << "Колич. элементов: "; cin >> N;
	int *B = new int[N];
	int *C = new int[N];

	for (i = 0; i < N; i++)
	{
		int r = rand() % 20001 - 10000;
		B[i] = r; C[i] = r;
	}
	cout << "Mассив B: ";
	for (i = 0; i < N; i++) cout << B[i] << " ";

	cout << "Mассив B: ";
	for (i = 0; i < N; i++) cout << C[i] << " ";

	clock_t  t1 = 0, t2 = 0;

	cout << "Результирующий массив: ";
	for (i = 0; i < N; i++) cout << B[i] << " ";
	t1 = clock();
	BubbleSort(B, N);
	t2 = clock();
	cout << "Время в миллисекундах сортировкой пузырьком: " << t2 - t1 << endl;
	t1 = clock();
	SortHoar(C, 0, N - 1);
	t2 = clock();
	cout << "Время в миллисекундах сортировкой разделением: " << t2 - t1 << endl;
	system("pause");
}
