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
	menu();

	double value;
	cout << "\ninput your choice: ";
	cin >> choice;

	while (choice != 0)
	{

		switch (choice)
		{
		case 1:
			cout << "value:";
			cin >> value;
			input_element(first, value);
			break;
		case 2:
			if (!IsEmpty(first))
			{
				cout << "input deleting value: ";
				cin >> value;
				if (delete_element(first, value))
					cout << "deleted value: " << value << endl;
				else
					cout << "value not foundet" << endl;
			}
			else
				cout << "list is clear" << endl;
			break;
		case 3:
			cout << "\ninput searching element: ";
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
			cout << "\nanswer: " << task_laba(first) << endl;
			break;
		default:
			break;
		}
		cout << "input your choice: ";
		cin >> choice;
	}

	return EXIT_FAILURE;
}

void menu(void)
{
	cout << "1 - input element" << endl;
	cout << "2 - delete element" << endl;
	cout << "3 - search element" << endl;
	cout << "4 - output in conole window" << endl;
	cout << "5 - write in file" << endl;
	cout << "6 - read out file" << endl;
	cout << "7 - task out laba" << endl;
	cout << "0 - exit" << endl;
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
		cout << "operation isn't complete" << endl;
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
		cout << "list clear" << endl;
	else
	{
		cout << "list:" << endl;
		while (p != NULL)
		{
			cout << "--> " << p->number << endl;
			p = p->next;
		}
		cout << "end list" << endl;
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
			cout << "this element in list from #" << count << endl;
			b = false;
		}
		p = p->next;
	}

	if (b)
		cout << "value not found in list";
}

void input_in_file(list* p)
{
	ofstream file("datafile.txt");
	if (!file)
	{
		cout << "FAIL" << endl;
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
		cout << "\nFAIL" << endl;
		exit(1);
	}
	while (!file.eof())
	{
		file >> buff;
		input_element(first, buff);
	}
	cout << "read is end" << endl;
}
