//����������(�����, ��������, ������ ���������� - ����������� ����������, �����, �������� ���������, ������������� � ��� �����).
//����� ���� �� ��������.������ ���������� ����������� � ������� ������������.������ � ���� � ���������� ������������ � ������� ������� ����� �++.



#include <iostream>
#include <fstream>
using namespace std;
struct Library
{
	char autor[30];
	char title[30];
	char group[30];

};
int main()
{

	int s, i = 0;
	char a[100];
	setlocale(LC_ALL, "Russian");
	Library book1 = { "������","̸����� ����","����������� ����������" };
	Library book2 = { "����","������","�����" };
	Library book3 = { "�����","�������� ������","�������� ���������" };
	Library book4 = { "������","������� ������","�������������" };
	Library book5 = { "�������","���� � ������","��� ������" };
	Library book6 = { "����� ����","��� � �����","���������� ����������" };
	Library book7 = { "�������","��������","���������� ������������" };
	Library book8 = { "������","�� ����","����� �������" };


	do
	{

		cout << "�������� �����:" << endl << "(1-̸����� ����, 2-������,3-���������� ������, 4-������� ������, 5-���� � ������, 6-��� � �����, 7-��������, 8-�� ����)" << endl;
		cin >> s;
		ofstream file("f.txt");
		switch (s)
		{
		case 1: file << book1.autor << ": " << book1.title << ". ������ ���������� - " << book1.group; break;
		case 2: file << book2.autor << ": " << book2.title << ". ������ ���������� - " << book2.group; break;
		case 3: file << book3.autor << ": " << book3.title << ". ������ ���������� - " << book3.group; break;
		case 4: file << book4.autor << ": " << book4.title << ". ������ ���������� - " << book4.group; break;
		case 5: file << book5.autor << ": " << book5.title << ". ������ ���������� - " << book5.group; break;
		case 6: file << book6.autor << ": " << book6.title << ". ������ ���������� - " << book6.group; break;
		case 7: file << book7.autor << ": " << book7.title << ". ������ ���������� - " << book7.group; break;
		case 8: file << book8.autor << ": " << book8.title << ". ������ ���������� - " << book8.group; break;
		default: cout << "����� ����� ���."; break;
		}
		file.close();
		ifstream file1("f.txt");
		file1.getline(a, 100);
		file.close();
		cout << endl << a << endl;
		cout << endl << "������� ����������? " << endl << "(1 - ��, 0 - ���)" << endl;
		cin >> i;

	} while (i);
	system("pause");
}