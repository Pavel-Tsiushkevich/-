#include<iostream>
#include<fstream>

using namespace std;
void func1(ofstream &f2);

int main()
{
	ofstream file1("File1.txt"), file2("File2.txt");
	char b[100];
	if (!file1 &&
		!file2)
	{
		cout << "ошибка открытия файла File1.txt или File2.txt" << endl;
		system("pause");
		return EXIT_FAILURE;
	}
	cout << "input 1 or 0: ";
	cin >> b;
	for (int i = 0; i < strlen(b); i++)
	{
		if (b[i] != '1' &&
			b[i] != '0')
		{
			cout << "строка не опредлена." << endl;
			system("pause");
			file1.close();
			file2.close();
			return EXIT_FAILURE;
		}
	}
	file1 << b;
	file1.close();

	func1(file2);

	file2.close();
}

void func1(ofstream &f2)
{
	ifstream f1("File1.txt");
	char b[100];
	f1.getline(b, 100);
	int b_int[100][2], count = 0, len = 1;
	if (b[0] == '1')
		b_int[count][0] = 1;
	else
		b_int[count][0] = 0;
	for (int i = 1; i < strlen(b); i++)
	{
		if (b[i] == b[i - 1])
		{
			len++;
			if (i == (strlen(b) - 1))
			{
				b_int[count][1] = len;
				count++;
			}
		}
		else
		{
			b_int[count][1] = len;
			len = 1;
			count++;
			if (b_int[count - 1][0] == 1)
				b_int[count][0] = 0;
			else
				b_int[count][0] = 1;
			b_int[count][1] = len;
		}
	}
	int max_len = b_int[0][1], index = 0;
	for (int i = 1; i < count; i++)
		if (b_int[i][1] > max_len)
		{
			max_len = b_int[i][1];
			index = i;
		}
	for (int i = 0; i < max_len; i++)
		f2 << b_int[index][0];
	f1.close();
}
