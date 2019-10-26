#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int arr[3][3], vec[3];
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			cout << "arr[" << i << "][" << j << "] = ";
			cin >> arr[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		cout << "vec[" << i << "] = ";
		cin >> vec[i];
	}
	cout << "array:" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << "\t" << arr[i][j];
		cout << endl;
	}

	cout << "vector:" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << vec[i];
		cout << endl;
	}
	cout << "ANSWER:" << endl;
	int buf;

	ofstream file("answer.txt");
	for (int i = 0; i < 3; i++)
	{
		buf = 0;
		for (int j = 0; j < 3; j++)
		{
			buf += arr[i][j] * vec[j];
		}
		cout << buf << endl;
		file << buf << endl;
	}
	file.close();
	system("pause");
}