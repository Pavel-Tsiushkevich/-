#include <iostream>
#include <fstream>

using namespace std;



struct list
{
	double number;
	list* next;
};
list* first = NULL;
int choice;

void menu(void);
void input_element(list*&, double);
int IsEmpty(list*);
double delete_element(list*&, double);
void printList(list*);
double task_laba(list*);
void search_value(list*, double);
void input_in_file(list* p);
void output_out_file(list*& p);


int main()
{

	setlocale(0, "");
	menu();

	double value;
	cout << "\n��� �����: ";
	cin >> choice;

	while (choice != 0)
	{

		switch (choice)
		{
		case 1:
			cout << "��������:";
			cin >> value;
			input_element(first, value);
			break;
		case 2:
			if (!IsEmpty(first))
			{
				cout << "������� ��������� ��������: ";
				cin >> value;
				if (delete_element(first, value))
					cout << "�������� ��������: " << value << endl;
				else
					cout << "�������� �� �������" << endl;
			}
			else
				cout << "list is clear" << endl;
			break;
		case 3:
			cout << "\n������� ������� �������: ";
			cin >> value;
			search_value(first, value);
			break;
		case 4:
			cout << endl;
			printList(first);
			break;
		case 5:
			input_in_file(first);
			break;
		case 6:
			output_out_file(first);
			break;
		case 7:
			cout << "\n�����: " << task_laba(first) << endl;
			break;
		default:
			break;
		}
		cout << "��� �����: ";
		cin >> choice;
	}

	return EXIT_FAILURE;
}

void menu(void)
{
	cout << "1 - ������ �������" << endl;
	cout << "2 - ������� �������" << endl;
	cout << "3 - ����� ��������" << endl;
	cout << "4 - �����" << endl;
	cout << "5 - ������ � ����" << endl;
	cout << "6 - ������ �� �����" << endl;
	cout << "7 - �������" << endl;
	cout << "0 - �����" << endl;
}

void input_element(list *&p, double value)
{
	list* newP = new list;
	if (newP != NULL)
	{
		newP->number = value;
		newP->next = p;
		p = newP;
	}
	else
		cout << "�������� �� ���������" << endl;
}

int IsEmpty(list* p)
{
	return p == NULL;
}

double delete_element(list*& p, double value)
{
	list* previous, *current, *temp;
	if (value == p->number)
	{
		temp = p;
		p = p->next;
		delete temp;
		return value;
	}
	else
	{
		previous = p;
		current = p->next;
		while (current != NULL && current->number != value)
		{
			previous = current;
			current = current->next;
		}
		if (current != NULL)
		{
			temp = current;
			previous->next = current->next;
			delete(temp);
			return value;
		}
	}
	return 0;
}

void printList(list* p)
{
	if (p == NULL)
		cout << "�������� ������" << endl;
	else
	{
		cout << "������:" << endl;
		while (p != NULL)
		{
			cout << "--> " << p->number << endl;
			p = p->next;
		}
		cout << "����� ������" << endl;
	}
}

double task_laba(list* p)
{
	int count = 0;
	double srednee_arifmet = 0;

	while (p != NULL)
	{
		if (p->number > 0)
		{
			srednee_arifmet += p->number;
			count++;
		}
		p = p->next;
	}

	return srednee_arifmet / count;
}

void search_value(list* p, double value)
{
	int count = 0;
	bool b = true;

	while (p != NULL)
	{
		count++;
		if (p->number == value)
		{
			cout << "������� � ������ #" << count << endl;
			b = false;
		}
		p = p->next;
	}

	if (b)
		cout << "�������� �� �������";
}

void input_in_file(list* p)
{
	ofstream file("datafile.txt");
	if (!file)
	{
		cout << "����" << endl;
		exit(1);
	}
	else
	{
		while (p != NULL)
		{
			file << p->number << endl;
			p = p->next;
		}
	}
	file.close();
}

void output_out_file(list*& p)
{
	double buff;
	ifstream file("datafile.txt");
	if (file.fail())
	{
		cout << "\n����" << endl;
		exit(1);
	}
	while (!file.eof())
	{
		file >> buff;
		input_element(first, buff);
	}
	cout << "������ ���������" << endl;
}
