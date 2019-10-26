
#include "Hash_ Twin_Chain.h"
#include <iostream>
#include <string>
using namespace std;
struct ROW
{
	char* number;
	char* name;
	ROW(char*z, char*n)

	{
		number = z;
		name = n;
	}
	ROW()
	{
		number = (char*)""; name = (char*) "";
	}
};

char* getkeyfromROW(void* d)
// ������� ��������� ����� �� �-�� �� ������������ ������
{
	ROW* f = (ROW*)d; // ����������� �-�� �� ������������ ������ d � �-�� f �� ��������� ROW 
	return f->number; // ���������� ���� ��������� ROW �� ��������� f
}

void ROW_print(listx::Element* e) // ������� ������ 1 �-� ������ �� �-�� �� ���� �-�
{
	cout << '\t' << ((ROW*)e->Data)->number << " - " << ((ROW*)e->Data)->name << endl;
}

int _tmain(int argc, TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	system("chcp 1251");
	int current_size;	// ������ ���-������� (���������� ������� � ���)
	cout << "������� ������ ���-�������" << endl;
	cin >> current_size;
	hashTC::Object H = hashTC::Create(current_size, getkeyfromROW);
	int choise;
	char k[100];
	for (;;)
	{
		cout << "����:" << endl;
		cout << "1 - ����� ����� ������ ����������� ���� " << endl;
		cout << "2 - ���������� ������ ������������ �����" << endl;
		cout << "3 - �������� ������������ �����" << endl;
		cout << "4 - ����� �� ������������ �����" << endl;
		cout << "0 - �����" << endl;
		cout << "�������� �����" << endl; cin >> choise;
		switch (choise) {
		case 0: exit(0);
		case 1: H.Scan(ROW_print);  break;
		case 2:
		{
			char *str = new char[20];
			char *nstr = new char[200];
			cout << "������� ����� �����" << endl;
			cin >> str;
			cout << "������� ��� ���������" << endl;
			cin >> nstr;
			ROW *a = new ROW(str, nstr);
			H.Insert(a);
		}  break;
		case 3: {
			cout << "������� ����� ����� ��� ��������" << endl;
			cin >> k;
			H.Delete(k); } break;
		case 4: {cout << "������� ����� ����� ��� ������" << endl;
			cin >> k;
			if (H.Search(k) == NULL)
				cout << "������� �� ������" << endl;
			else  ROW_print(H.Search(k)); }
				break;
		}
	}
	return 0;
}
