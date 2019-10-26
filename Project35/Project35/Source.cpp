# include <iostream>                    


int r;
const int k = 5;
const int kol = 3;
const int zap = 4;
using namespace std;

struct student
{
	char name[kol];
	int cl;
	char sub1[20], sub2[20], sub3[20], sub4[20], sub5[20];
	int m[k];
	int sr;
};

struct student Stud[zap];

struct student bad;

int sch = 0;

void enter_new()
{
	cout << "Ввод информации" << endl;
	if (sch < zap)
	{
		cout << "Запись №";
		cout << sch + 1;
		cout << endl << "Фамилия " << endl;
		cin >> Stud[sch].name;
		cout << "Класс " << endl;
		cin >> Stud[sch].cl;
		cout << "Предметы " << endl;
		cin >> Stud[sch].sub1;
		cin >> Stud[sch].sub2;
		cin >> Stud[sch].sub3;
		cin >> Stud[sch].sub4;
		cin >> Stud[sch].sub5;
		cout << "Оценки " << endl;
		for (int j = 1; j <= k; j++)
		{
			cin >> Stud[sch].m[j];
		}
		cout << "Средний балл " << endl;
		cin >> Stud[sch].sr;
		sch++;
	}
	else
		cout << "Введено максимальное кол-во запи-сей";
	cout << "Что дальше?" << endl;
	cin >> r;
}

void del()
{
	int d;
	cout << "\nНомер записи, которую надо удалить" << endl;
	cout << "Если надо удалить все записи, нажмите '99'" << endl;
	cin >> d;
	if (d != 99)
	{
		for (int de_1 = (d - 1); de_1 < sch; de_1++)
			Stud[de_1] = Stud[de_1 + 1];
		sch = sch - 1;
	}
	if (d == 99)
		for (int i = 0; i < zap; i++)
			Stud[i] = bad;
	cout << "Что дальше?" << endl;
	cin >> r;
}

void out()
{
	int sw, o;
	cout << endl << "Введите: " << endl;
	cout << "1-вывод одной записи" << endl;
	cout << "2-вывод всех записей" << endl;      cin >> sw;
	if (sw == 1)
	{
		cout << "Введите номер записи, которую нужно вывести" << endl;
		cin >> o;  cout << endl;
		cout << "Фамилия ";
		cout << Stud[o - 1].name << endl;
		cout << "Класс ";
		cout << Stud[o - 1].cl << endl;
		cout << "Предметы ";
		cout << Stud[o - 1].sub1 << " ";
		cout << Stud[o - 1].sub2 << " ";
		cout << Stud[o - 1].sub3 << " ";
		cout << Stud[o - 1].sub4 << " ";
		cout << Stud[o - 1].sub5 << endl;
		cout << "Оценки ";
		for (int j = 1; j <= k; j++)
		{
			cout << Stud[o - 1].m[j] << " ";
		}
		cout << endl;
		cout << "Средний балл ";
		cout << Stud[o - 1].sr << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < sch; i++) {
			cout << "Фамилия ";
			cout << Stud[i].name << endl;
			cout << "Класс ";
			cout << Stud[i].cl << endl;
			cout << "Предметы ";
			cout << Stud[i].sub1 << " ";
			cout << Stud[i].sub2 << " ";
			cout << Stud[i].sub3 << " ";
			cout << Stud[i].sub4 << " ";
			cout << Stud[i].sub5 << endl;
			cout << "Оценки ";
			for (int j = 1; j <= k; j++)
			{
				cout << Stud[i].m[j] << " ";
			}
			cout << endl;
			cout << "Средний балл ";
			cout << Stud[i].sr << endl;
		}
	}
	cout << "Что делать дальше?" << endl;
	cin >> r;
}

void vibor() {
	/* поиск по имени */
	bool isExists = false;
	char name[30];
	std::cout << "Введите имя: " << std::endl;
	std::cin >> name;

	for (int i = 0; i < zap; i++) {

		if (strcmp(Stud[i].name, name) == 0) {
			/* вывести данные на экран */
			isExists = true;
			break;
		}
	}

	if (!isExists) { std::cout << "заданного имени в базе данных нет! " << std::endl; }

	/*поиск по среднему баллу */
	isExists = false;
	double middleMark;
	std::cout << "Введите средний балл: " << std::endl;
	std::cin >> middleMark;

	for (int i = 0; i < zap; i++) {

		if (Stud[i].sr == middleMark) {
			/* вывести данные на экран */
			isExists = true;
		}
	}

	if (!isExists) { std::cout << "учащихся с заданным средним баллом не найдено! " << std::endl; }

}



int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Записей пока нет" << endl;
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для вывода записи(ей)" << endl;
	cout << "4-для выбора записи(ей)" << endl;
	cout << "5-для выхода" << endl;
	cin >> r;
	do
	{
		switch (r)
		{
		case 1:  del();     break;
		case 2:  enter_new();     break;
		case 3:  out();     break;
		case 4: vibor(); break;
		}
	} while (r != 5);
}
