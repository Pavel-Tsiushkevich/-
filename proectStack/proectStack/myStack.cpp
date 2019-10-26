#include "pch.h"
#include <iostream>
#include "myStack.h"
using namespace std;
void push(int x, Stack* myStk)
{
	Stack* e = new Stack;
	e->data = x;
	e->next = myStk->head;
	myStk->head = e;
}
int pop(Stack* myStk)
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;
	}
	else
	{
		Stack* e = myStk->head;
		int a = myStk->head->data;
		myStk->head = myStk->head->next;
		delete e;
		return a;
	}
}
void show(Stack* myStk)
{
	Stack* e = myStk->head;
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->data;
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}

int summ(Stack* myStk)
{
	Stack* e = myStk->head;
	int sum = 0, a;
	if (e == NULL)
		return sum;
	while (e != NULL)
	{
		a = e->data;
		if (a > 0)
			sum += a;
		e = e->next;
	}
	return sum;
}
