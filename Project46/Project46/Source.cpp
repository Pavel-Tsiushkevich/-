#include "stdafx.h"
#include<iostream>

using namespace std;

struct item
{
	int data;
	item *next;
};
item *head, *tail;

bool isnull(void)
{
	return head == NULL;
}

void delet1()
{
	if (isnull())
		cout << "Очередь пуста" << endl;
	else
	{
		item *p = head;
		head = head->next;
		delete p;
	}
}

void fromhead()
{
	if (isnull())
		cout << "Очередь пуста" << endl;
	else
		cout << "Начало = " << head->data << endl;
}

void clrall()
{
	while (!isnull())   delet1();
}
void add(int x)
{
	item *p = new item;
	p->data = x;  p->next = NULL;
	item *v = new item;
	item *p1 = new item;
	item *p2 = new item;
	int i = 0;
	if (isnull()) head = tail = p;
	else
	{
		p2 = head;  p1 = head;
		while (p1 != NULL)
		{
			if (i == 1)
			{
				if (x <= p1->data)
				{
					v->data = x; v->next = p1;
					p2->next = v;   return;
				}
				p2 = p2->next;
			}
			else
			{
				if (x <= p1->data)
				{
					v->data = x;  v->next = p1;
					head = v; return;
				}
			}
			p1 = p1->next;   i = 1;
		}
		if (p1 == NULL)
		{
			tail->next = p;  tail = p;
		}
	}
}

void out()
{
	item *p = new item;
	if (isnull()) cout << "Очередь пуста" << endl;
	else {
		cout << "Очередь = ";
		p = head;
		while (!isnull())
		{
			if (p != NULL)
			{
				cout << p->data << " ";
				cout << "->";
				p = p->next;
			}
			else
			{
				cout << "NULL" << endl;
				return;
			}
		}
	}
}



int main()
{
	setlocale(LC_CTYPE, "Russian");
	int num = 1, z;
	head = NULL; tail = NULL;
	while (num != 0)
	{
		cout << "1 - добавить элемент" << endl;
		cout << "2 - получить элемент с начала" << endl;
		cout << "3 - извлечь элемент с начала" << endl;
		cout << "4 - вывести элементы" << endl;
		cout << "5 - очистить очередь" << endl;
		cout << "Выберите действие  ";
		cin >> num;
		switch (num)
		{
		case 1: cout << "Введите элемент:  ";
			cin >> z;  add(z);
			out(); break;
		case 2: fromhead(); break;
		case 3: delet1(); break;
		case 4: out(); break;
		case 5: clrall(); break;
		}
	} return 0;
}