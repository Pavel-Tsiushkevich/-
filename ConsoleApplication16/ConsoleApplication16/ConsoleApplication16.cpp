#include "pch.h"
#include <iostream>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	int A, B, C, O;
	cout << "Количество сбитых игроком сомалётов A" << endl;
	cin >> A;
	cout << "Количество сбитых игроком ракет B" << endl;
	cin >> B;
	cout << "Количество сбитых игроком спутников C" << endl;
	cin >> C;
	A = A * 50;
	B = B * 100;
	C = C * 200;
	O = A + B + C;
	cout << "Очки игрока" << O;
}