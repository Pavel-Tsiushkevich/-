#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	char b[100];
	int words = 0;
	ifstream F1("F1.txt");
	ofstream F2("F2.txt");

	if (!F1)
	{
		cout << "מרטבךא F1.txt" << endl;
		system("pause");
		return EXIT_FAILURE;
	}
	if (!F2)
	{
		cout << "מרטבךא F2.txt" << endl;
		system("pause");
		return EXIT_FAILURE;
	}

	while (F1.getline(b, 100))
	{
		if (b[0] == 'A')
		{
			F2 << b << endl;
			words++;
			for (int i = 0; i < 99; i++)
				if (b[i] == ' ' &&
					b[i + 1] != ' ')
					words++;
		}
	}
	F2 << "סכמג ג פאיכו: " << words;
	F1.close();
	F2.close();
	system("pause");
	return EXIT_FAILURE;
}
