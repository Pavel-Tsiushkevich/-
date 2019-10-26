struct Object
{
	void** Data; // ������ �-��� �� �-� ���-�������
	Object(int, int(*)(void*));
	// ����������� ����� ��� ���������� ���������� �������� ��� �������� ���-������
	// 1-�� �������� ������������ - ����������� ������� �-� ���-������� (� ����� ������� ��� 5), 2-�� - ������� ��� ��������� ������ �� �-��
	int Size; // ������������ ���������� �-� � �������
	int N; // ������� ���������� �-�
	int(*GetKey)(void*);
	// ������� ��� ��������� ������ �� �-��, *GetKey - ������� �-�� �� �������
	// void* - ������� ��������� � �������� ��������� �-�� �� ������������ ������
	bool Insert(void*); // ������� ������� �-� � ���-�������
	int SearchInd(int key);
	// ������� ������ ������� �-� � ���-������� �� �����, Ind - ������. �� ���� �������
	void* Search(int key); // ������� ������ �-�� �� �-� �� �����
	void* Delete(int key); // ������� �������� �-� �� �����
	bool Delete(void*); // ������� �������� �-� �� ������
	void Scan(void(*f)(void*));
	// ������� ������ ���-�������, ������� ��������� ������� ��� ������ ������ �-�
	// � �� � ���� ������� ��������� � �������� ��������� �-�� �� ������������ ������
	double koefzap(); // ������� ��� ������� ������������ ������������� ���-�������
};
static void* DEL = (void*)-1; // �������� ��� ������ �-�� ��� ����������� �������� �-�
Object Create(int size, int(*getkey)(void*));// ������� ��� �������� ���-�������, ��������� ������������ ������ ������� � ������� ��������� ����� �� �-�
#pragma once
