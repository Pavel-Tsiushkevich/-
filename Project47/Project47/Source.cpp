#include<iostream> 
using namespace std;

struct Number
{
	int info;
	Number* next;
};

void create(Number** begin, Number** end, int p);
void view(Number* begin, int *);
void answer(Number* begin, int* arr, int size);


int main()
{
	Number* begin = NULL, *end, *t;
	t = new Number;
	int p, size;
	cout << "\nEnter size queue = ";  cin >> size;
	int *arr = new int[size];
	cout << "Enter number = ";       cin >> p;
	t->info = p;
	t->next = NULL;
	begin = end = t;
	for (int i = 1; i < size; i++)
	{
		cout << "Enter number = ";    cin >> p;
		create(&begin, &end, p);
	}
	if (begin == NULL)
		cout << "No elements" << endl;
	else
		view(begin, arr);

	answer(begin, arr, size);
	system("pause");
	delete[]arr;
	return 0;
}

void create(Number * *begin, Number * *end, int p)
{
	Number* t = new Number;
	t->next = NULL;
	if (*begin == NULL)
		* begin = *end = t;
	else
	{
		t->info = p;
		(*end)->next = t;
		*end = t;
	}
}

void view(Number * begin, int *arr)
{
	int i = 0;
	Number* t = begin;
	if (t == NULL)
	{
		cout << "Number is empty\n";
		return;
	}
	else
		while (t != NULL)
		{
			cout << t->info << endl;
			arr[i] = t->info; i++;
			t = t->next;
		}
	cout << "end view" << endl;
}


void answer(Number* begin, int* arr, int size)
{
	int* arr_buff = new int[size];
	int count;

	for (int i = 0; i < size; i++)
	{
		count = 0;
		for (int j = 0; j < size; j++)
			if (arr[i] == arr[j])
				count++;
		arr_buff[i] = count;
	}
	Number* t;
	int count_sec = 0;
	for (int i = 0; i < size; i++)
	{
		t = begin;
		count = 0;
		if (arr_buff[i] >= 3)
		{
			count_sec++;
			while (t != NULL)
			{
				count++;
				if (t->info == arr[i])
				{
					while (t->next != NULL)
					{
						t->info = t->next->info;
						t = t->next;
					}
					delete t->next;
					t = NULL;
					break;
				}
				t = t->next;
			}
		}
	}
	t = begin;
	if (size - count_sec == 0)
	{
		cout << "Number is empty\n";
		return;
	}
	else
		for (int i = 0; i < size - count_sec; i++)
		{
			cout << t->info << endl;
			t = t->next;
		}
}
