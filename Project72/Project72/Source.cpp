#include <iostream>
#include <time.h>
using namespace std;
// сортировка подсчётом
void CountSort(int in[], int out[], int n)
{
	int i, j, count;
	for (i = 0; i < n; ++i)
	{
		for (count = 0, j = 0; j < n; ++j)
			if (in[j] < in[i] || (in[j] == in[i] && i < j))  count++;
		out[count] = in[i];
	}
}


// сортировка слиянием
void InsOrd(int m[], int sm, int em, int e)
{
	int buf; int i = sm;
	while (i <= em && m[i] < e)
	{
		if (i - 1 >= sm) m[i - 1] = m[i]; i++;
	};
	m[i - 1] = e;
}
int*  Merge(int m[], int sm, int cm, int em)   //процедура слияния
{
	int buf;  for (int i = 0; i <= sm; i++)
	{
		if (m[i] > m[cm + 1]) { buf = m[i]; m[i] = m[cm + 1]; InsOrd(m, cm + 1, em, buf); }
	}
	return m;
}
int* SortMerge(int m[], int lm, int sm = 0)
{
	if (lm > 1)
	{
		SortMerge(m, lm / 2, sm);
		SortMerge(m, lm - lm / 2, sm + lm / 2);
		Merge(m, sm, sm + lm / 2 - 1, sm + lm - 1);
	};
	return m;
};

void selectSort(int A[], int size) //Сортировка выбором
{
	int k, i, j;
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1, k = i; j < size; j++)
			if (A[j] < A[k])
				k = j;
		int c = A[k];
		A[k] = A[i];
		A[i] = c;
	}
}

void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	const int N = 50000;

	int i, j = 0, k = 0, sz1, sz2, sz3, A[N], B[N], T[N], C[N];
	cout << "Введите размер массива A - ";
	cin >> sz1;
	cout << "Массив А: " << endl;
	srand((unsigned)time(NULL));
	for (i = 0; i < sz1; i++)
	{
		A[i] = rand() % 200;
		cout << A[i] << " ";
	}
	cout << endl;
	cout << endl << "Введите размер массива B - ";
	cin >> sz2;
	cout << "Массив B: " << endl;
	srand((unsigned)time(NULL));
	for (k = 0; k < sz2; k++)
	{
		B[k] = rand() % 99;
		cout << B[k] << " ";
	}
	cout << endl << "Введите размер массива C - ";
	cin >> sz3;
	cout << "Массив C: " << endl;
	srand((unsigned)time(NULL));
	for (k = 0; k < sz3; k++)
	{
		C[k] = rand() % 99;
		cout << C[k] << " ";
	}

	clock_t t1 = clock();
	CountSort(A, T, sz1);
	clock_t t2 = clock();
	cout << endl;
	cout << "Время в миллисекундах сортировкой подсчётом: " << t2 - t1 << endl;
	cout << "Отсортированнный массив сортировкой подсчётом: ";
	for (j = 0; j < sz1; j++) cout << T[j] << " ";
	cout << endl;

	t1 = clock();
	SortMerge(B, sz2, 0);
	t2 = clock();
	cout << "Время в миллисекундах сортировкой слиянием: " << t2 - t1 << endl;
	cout << "Отсортированнный массив сортировкой слиянием: ";
	for (j = 0; j < sz2; j++) cout << B[j] << " ";
	cout << endl;

	t1 = clock();
	selectSort(C, sz3);
	t2 = clock();
	cout << "Время в миллисекундах cортировкой выбора: " << t2 - t1 << endl;
	cout << "Отсортированнный массив сортировкой выбора: ";
	for (j = 0; j < sz2; j++) cout << B[j] << " ";
	cout << endl;
	system("pause");
}
