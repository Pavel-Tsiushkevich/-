#include<stdio.h> 

void main()
{
	FILE *f1, *f2;
	errno_t err1, err2;
	err1 = fopen_s(&f1, "f.txt", "r");
	if (err1 != NULL)
	{
		printf("error");
	}
	float buff[20], buff1[20], buff2[20]; int i1 = 0, i2 = 0;
	for (int i = 0; i < 20; i++)
		fscanf_s(f1, "%f", buff[i]);
	for (int i = 0; i < 20; i++)
	{
		if (buff[i] > 0)
		{
			buff1[i1] = buff[i];
		}
		if (buff[i] > 0)
		{
			buff1[i1] = buff[i];
		}
	}
	fclose(f1);
	err2 = fopen_s(&f2, "q.txt", "w");
	if (err2 != 0)
	{
		printf("error");
	}
	for (int i = 0; i < 20; i++)
	{
		fprintf_s(f2, "%f", buff1[i]);
		fprintf_s(f2, "%f", buff2[i]);
	}
	fclose(f2);
}