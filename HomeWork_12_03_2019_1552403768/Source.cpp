#include<iostream>
#include<fstream>			// библиотека работы с файлами
#include<Windows.h>
#include<locale.h>




// VladimirOrlovA / HomeWork_12_03_2019_1552403768

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


using namespace std;

void Task1()
{
	/*Дан текстовый файл.Найти длину самой длинной строки.*/

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask1\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	ifstream fin("DataSource.txt");
	ofstream fout("OutTask1.txt");

	char str[50][300];					// объявляем массив из 50 строк с 300 символами
	int count = 0;						// объявляем переменную для счетчика строк
	int max=0;
	int tmp;

		
	while (!fin.eof())					// пока не достигнем конца файла --- eof -> end of file
	{
		fin.getline(str[count], 300);	// записывем считанные из файла строки в массив
		count++;
		
	}

	for (int i = 0; i != count; i++)	// ищем самую длинную строку
	{
		tmp = strlen(str[i]);

		if (tmp > max) 
			max = tmp;

	}

	cout << "Длина самой длинной строки в файле DataSource.txt -> " << max << " знаков" << endl;
	fout << "Длина самой длинной строки в файле DataSource.txt -> " << max << " знаков" << endl;
}

void Task2()
{
	/* Дан текстовый файл. Подсчитать количество слов, начинающихся с символа, который задаёт пользователь. */

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask2\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	


}


void Task3()
{
	/* Дан текстовый файл.Переписать в другой файл все его строки с заменой в них символа 0 на символ 1 и наоборот. */

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask3\n\n";
	SetConsoleTextAttribute(hConsole, 7);



}

int main()
{
	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n Orlov Vladimir HomeWork_27_02_2019_1551281479 \n\n";
	SetConsoleTextAttribute(hConsole, 7);

	/*SetConsoleCP(1251);
	SetConsoleOutputCP(1251);*/

	setlocale(LC_ALL, "");

	int number;
	char flag;

	do
	{
		cout << endl << "Enter number of Task (1) to (3) => ";
		cin >> number;

		switch (number)
		{
		case 1: {Task1(); } break;
		case 2: {Task2(); } break;
		case 3: {Task3(); } break;

		default: cout << "\nEntered number of Task does not exist...\n\n";

		}

		SetConsoleTextAttribute(hConsole, 10);
		cout << "\n--------------------------------------------------------------------------\n\n";
		SetConsoleTextAttribute(hConsole, 7);

		cout << "Do you want to continue? \n\nIf YES press (y) if NO press any keys => ";
		cin >> flag;

	} while (flag == 'y');
}