#include <iostream>
using namespace std;
void compress(char * text);
const int strsize = 100;
int main()
{
	char text[strsize];
	gets_s(text);
	compress(text);
	cout << text << endl;
	return 0;
}
void compress(char * text)
{
	char * buf = new char[30];
	int size = strlen(text), a = 0, b = 0;
	for (a = 0; a < size; a++)
	{
		if (text[a] == ' ')
			continue;
		else {
			buf[b] = text[a];
			b++;
		}
	}
	cout << text << endl;
	cout << buf << endl;
	delete[] buf;
	system("pause");
	return;
}
