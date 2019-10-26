#include<iostream> 
#include<stdio.h> 
#include<Windows.h> 

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE *f1, *f2, *f3;
	errno_t error_file_1, error_file_2, error_file_3;
	int count_file_1 = 0, count_file_2 = 0, count_file_3 = 0, column;
	float buff_1, buff_2;
	const char space = ' ';
	bool b1 = false, b2 = false;

	error_file_1 = fopen_s(&f1, "fA.txt", "r+");
	error_file_2 = fopen_s(&f2, "fB.txt", "r+");
	if (error_file_1 != 0 ||
		error_file_2 != 0)
	{
		cout << "Ошибка" << endl;
		system("pause");
		return EXIT_FAILURE;
	}

	while (b2 != true &&
		b1 != true)
	{
		if (fscanf_s(f1, "%f", &buff_1) != -1)
			count_file_1++;
		else
			b1 = true;
		if (fscanf_s(f2, "%f", &buff_2) != -1)
			count_file_2++;
		else
			b2 = true;
	}
	count_file_2++;
	fseek(f1, 0L, SEEK_SET);
	fseek(f2, 0L, SEEK_SET);
	fscanf_s(f1, "%f", &buff_1);
	fscanf_s(f2, "%f", &buff_2);
	column = buff_1;

	if (count_file_1 != count_file_2 &&
		buff_1 != buff_2)
	{
		cout << "Несоответские условий" << endl;
		system("pause");
		return EXIT_FAILURE;
	}
	fseek(f1, 0L, SEEK_SET);
	fseek(f2, 0L, SEEK_SET);

	error_file_3 = fopen_s(&f3, "fC.txt", "w");
	if (error_file_3 != 0)
	{
		cout << "Ошибка" << endl;
		system("pause");
		return EXIT_FAILURE;
	}

	while (count_file_3 != count_file_1)
	{
		fscanf_s(f1, "%f", &buff_1);
		fscanf_s(f2, "%f", &buff_2);
		if (fprintf_s(f3, "%f", buff_1 + buff_2))
			count_file_3++;
		if (count_file_3 % column != 0)
			fprintf_s(f3, "%c", space);
		else
			fprintf_s(f3, "\n");

	}

	fclose(f1);
	fclose(f2);
	fclose(f3);
	cout << "Программа завершена" << endl;
	system("pause");
	return EXIT_FAILURE;
}