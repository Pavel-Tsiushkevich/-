#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

int compress(char * text);//���������� �������
const int strsize = 40;//������ ������

int main()
{
	SetConsoleCP(1251);//��������� �����
	SetConsoleOutputCP(1251);//��������� ������

	char text[strsize] = "����� � ��������� ���";//�������� �����
	int size = compress(text);//�������� ������� ������� ���������� ������ �����
	cout << endl;//������� ������
	for (int i = 0; i < size; i++)//����� �� ����� ������ ��� ��������
	{
		cout << text[i];//������� �� �����
	}
	_getch();
	return 0;
}

int compress(char * text)
{
	char * buf = new char[strlen(text)];//������� ������, ������� ����� ��
	int b = 0;// ������� �������� � ����� ������
	for (int i = 0; i < strlen(text); i++)//�� ���� �������� ������ text
	{
		if (text[i] == ' ')//���� ������
			continue;//�� ���������� ��
		else//�����
		{
			buf[b] = text[i];//���������� � ����� ������
			b++;//� ������ ������� ����� �� ��������� ������
		}
	}
	strcpy(text, buf);//����� ���������� ���� �������� �������� ���������� ������ � ��������
	return b;//���������� �����
}