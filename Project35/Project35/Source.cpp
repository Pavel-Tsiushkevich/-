# include <iostream>                    


int r;
const int k = 5;
const int kol = 3;
const int zap = 4;
using namespace std;

struct student
{
	char name[kol];
	int cl;
	char sub1[20], sub2[20], sub3[20], sub4[20], sub5[20];
	int m[k];
	int sr;
};

struct student Stud[zap];

struct student bad;

int sch = 0;

void enter_new()
{
	cout << "���� ����������" << endl;
	if (sch < zap)
	{
		cout << "������ �";
		cout << sch + 1;
		cout << endl << "������� " << endl;
		cin >> Stud[sch].name;
		cout << "����� " << endl;
		cin >> Stud[sch].cl;
		cout << "�������� " << endl;
		cin >> Stud[sch].sub1;
		cin >> Stud[sch].sub2;
		cin >> Stud[sch].sub3;
		cin >> Stud[sch].sub4;
		cin >> Stud[sch].sub5;
		cout << "������ " << endl;
		for (int j = 1; j <= k; j++)
		{
			cin >> Stud[sch].m[j];
		}
		cout << "������� ���� " << endl;
		cin >> Stud[sch].sr;
		sch++;
	}
	else
		cout << "������� ������������ ���-�� ����-���";
	cout << "��� ������?" << endl;
	cin >> r;
}

void del()
{
	int d;
	cout << "\n����� ������, ������� ���� �������" << endl;
	cout << "���� ���� ������� ��� ������, ������� '99'" << endl;
	cin >> d;
	if (d != 99)
	{
		for (int de_1 = (d - 1); de_1 < sch; de_1++)
			Stud[de_1] = Stud[de_1 + 1];
		sch = sch - 1;
	}
	if (d == 99)
		for (int i = 0; i < zap; i++)
			Stud[i] = bad;
	cout << "��� ������?" << endl;
	cin >> r;
}

void out()
{
	int sw, o;
	cout << endl << "�������: " << endl;
	cout << "1-����� ����� ������" << endl;
	cout << "2-����� ���� �������" << endl;      cin >> sw;
	if (sw == 1)
	{
		cout << "������� ����� ������, ������� ����� �������" << endl;
		cin >> o;  cout << endl;
		cout << "������� ";
		cout << Stud[o - 1].name << endl;
		cout << "����� ";
		cout << Stud[o - 1].cl << endl;
		cout << "�������� ";
		cout << Stud[o - 1].sub1 << " ";
		cout << Stud[o - 1].sub2 << " ";
		cout << Stud[o - 1].sub3 << " ";
		cout << Stud[o - 1].sub4 << " ";
		cout << Stud[o - 1].sub5 << endl;
		cout << "������ ";
		for (int j = 1; j <= k; j++)
		{
			cout << Stud[o - 1].m[j] << " ";
		}
		cout << endl;
		cout << "������� ���� ";
		cout << Stud[o - 1].sr << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < sch; i++) {
			cout << "������� ";
			cout << Stud[i].name << endl;
			cout << "����� ";
			cout << Stud[i].cl << endl;
			cout << "�������� ";
			cout << Stud[i].sub1 << " ";
			cout << Stud[i].sub2 << " ";
			cout << Stud[i].sub3 << " ";
			cout << Stud[i].sub4 << " ";
			cout << Stud[i].sub5 << endl;
			cout << "������ ";
			for (int j = 1; j <= k; j++)
			{
				cout << Stud[i].m[j] << " ";
			}
			cout << endl;
			cout << "������� ���� ";
			cout << Stud[i].sr << endl;
		}
	}
	cout << "��� ������ ������?" << endl;
	cin >> r;
}

void vibor() {
	/* ����� �� ����� */
	bool isExists = false;
	char name[30];
	std::cout << "������� ���: " << std::endl;
	std::cin >> name;

	for (int i = 0; i < zap; i++) {

		if (strcmp(Stud[i].name, name) == 0) {
			/* ������� ������ �� ����� */
			isExists = true;
			break;
		}
	}

	if (!isExists) { std::cout << "��������� ����� � ���� ������ ���! " << std::endl; }

	/*����� �� �������� ����� */
	isExists = false;
	double middleMark;
	std::cout << "������� ������� ����: " << std::endl;
	std::cin >> middleMark;

	for (int i = 0; i < zap; i++) {

		if (Stud[i].sr == middleMark) {
			/* ������� ������ �� ����� */
			isExists = true;
		}
	}

	if (!isExists) { std::cout << "�������� � �������� ������� ������ �� �������! " << std::endl; }

}



int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "������� ���� ���" << endl;
	cout << "�������:" << endl;
	cout << "1-��� �������� ������" << endl;
	cout << "2-��� ����� ����� ������" << endl;
	cout << "3-��� ������ ������(��)" << endl;
	cout << "4-��� ������ ������(��)" << endl;
	cout << "5-��� ������" << endl;
	cin >> r;
	do
	{
		switch (r)
		{
		case 1:  del();     break;
		case 2:  enter_new();     break;
		case 3:  out();     break;
		case 4: vibor(); break;
		}
	} while (r != 5);
}
