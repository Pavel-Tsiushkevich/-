#pragma once
#include "pch.h"
struct Stack
{
	int data;
	Stack* head;
	Stack* next;
};

void show(Stack* myStk);
int pop(Stack* myStk);
void push(int x, Stack* myStk);
int summ(Stack* myStk);
