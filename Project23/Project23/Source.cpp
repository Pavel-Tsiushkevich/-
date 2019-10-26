#include "stdafx.h"
#include <iostream>
#include<locale>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
using namespace std;

int main()
{
	int col, st, sch = 0, tmp, cst = 1;
	ifstream in("A.bin");
	fstream out("B.bin");
	in >> col;
	int* str = new int[col];
	setlocale(LC_CTYPE, "Russian");
	cout << "¬ведите номер строки" << endl;
	cin >> st;
	while (!in.eof())
	{
		in >> tmp; sch++;
		if (sch == 10)
			cst++;
		if (cst == st)
		{
			out << tmp << ' ';
			for (int i = 0; i < 8; i++)
			{
				in >> tmp;
				out << tmp << ' ';
			} sch = 0; cst++;
		}
	}
}
