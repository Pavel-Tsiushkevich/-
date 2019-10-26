//Сформировать очередь, записи в которой содержат ключевое поле int.Написать функцию удаления из нее элементов, встречающихся два и более раз.


#include<iostream> 
#include<Windows.h>
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
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Number* begin = NULL, *end, *t;
	t = new Number;
	int p, size;
	cout << "\nВвидите размер очереди = ";  cin >> size;
	int *arr = new int[size];
	cout << "Ввидите номер = ";       cin >> p;
	t->info = p;
	t->next = NULL;
	begin = end = t;
	for (int i = 1; i < size; i++)
	{
		cout << "Ввидите номер = ";    cin >> p;
		create(&begin, &end, p);
	}
	if (begin == NULL)
		cout << "Ошибка" << endl;
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
		cout << "Ошибка\n";
		return;
	}
	else
		while (t != NULL)
		{
			cout << t->info << endl;
			arr[i] = t->info; i++;
			t = t->next;
		}
	cout << "Ответ" << endl;
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
		if (arr_buff[i] >= 2)
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
		cout << "Ошибка\n";
		return;
	}
	else
		for (int i = 0; i < size - count_sec; i++)
		{
			cout << t->info << endl;
			t = t->next;
		}
}
