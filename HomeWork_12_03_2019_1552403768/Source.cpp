#include<iostream>
#include<fstream>			// ���������� ������ � �������
#include<Windows.h>
#include<locale.h>




// VladimirOrlovA / HomeWork_12_03_2019_1552403768

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


using namespace std;

void Task1()
{
	/*��� ��������� ����.����� ����� ����� ������� ������.*/

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask1\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	ifstream fin("DataSource1.txt");
	ofstream fout("OutTask1.txt");

	char str[50][300];					// ��������� ������ �� 50 ����� � 300 ���������
	int count = 0;						// ��������� ���������� ��� �������� �����
	int max=0;
	int tmp;

		
	while (!fin.eof())					// ���� �� ��������� ����� ����� --- eof -> end of file
	{
		fin.getline(str[count], 300);	// ��������� ��������� �� ����� ������ � ������
		count++;
		
	}

	for (int i = 0; i != count; i++)	// ���� ����� ������� ������
	{
		tmp = strlen(str[i]);

		if (tmp > max) 
			max = tmp;

	}

	cout << "Task 1 -����� ����� ������� ������ � ����� DataSource1.txt -> " << max << " ������" << endl;
	fout << "\nTask 1 - ����� ����� ������� ������ � ����� DataSource1.txt -> " << max << " ������" << endl;
}


void Task2()
{
	/* ��� ��������� ����. ���������� ���������� ����, ������������ � �������, ������� ����� ������������. */

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask2\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	cout << "������� ������ ������ ����� -> ";
	char c=' ';
	cin >> c;
	
	
	ifstream fin ("DataSource2.txt");
	ofstream fout("OutTask2.txt");

	char str[50][150];
	int count(0);

	while (!fin.eof())
	{
		fin.getline(str[count], 150);		//// ��������� �� ����� "DataSource.txt" ������ �� ����� ����� � ���������� ������ � ������ �� �������
		count++;
	}


	int countW = 0;

	// ���� ����� ������������ � ��������� ������� �� ���� �������
	for (int i = 0; i < count; i++)
	{
		// ��������� ������ ����� � �������
		if (str[i][0] == c)
			countW++;
		
		// ��������� ��� ����� � ������, ����� ������� �����
		for (int j = 0; j < strlen(str[i]); j++)
		{
			
			if (str[i][j] == ' ' &&  str[i][j + 1] == c && j != 0)
				countW++;
		}
	}

	cout << "Task 2 - ���-�� ���� � ������� " << c <<" � ����� DataSource2.txt -> "<< countW << endl;
	fout << "\nTask 2 - ���-�� ���� � ������� " << c << " � ����� DataSource2.txt -> " << countW << endl;

}


void Task3()
{
	/* ��� ��������� ����.���������� � ������ ���� ��� ��� ������ � ������� � ��� ������� 0 �� ������ 1 � ��������. */

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask3\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	char str;

	ifstream fin("DataSource3.txt");
	ofstream fout("OutTask3.txt");
	
	fout << "�������� �����:\n";

	while (fin.get(str)) 
		fout << str;
	fout << endl;

	cout << "Task 3 part 1\n";
	fout << "Task 3 part 1\n";
	cout << "Change symbol 0 to 1 on file DataSource3.txt and write result in file OutTask3 \n";
	fout << "Change symbol 0 to 1 on file DataSource3.txt and write result in file OutTask3 \n";

	fin.close();
	fin.open("DataSource3.txt");

	while (fin.get(str))
	{
		if (str == '0') 
			str = '1';
		fout << str;
	}
	fout << endl;

	
	cout << "Task 3 part 2\n";
	fout << "Task 3 part 2\n";
	cout << "Change symbol 1 to 0 on file DataSource3.txt and write result in file OutTask3 \n";
	fout << "Change symbol 1 to 0 on file DataSource3.txt and write result in file OutTask3 \n";

	fin.close();
	fin.open("DataSource3.txt");
	
	while (fin.get(str))
	{
		if (str == '1')
			str = '0';
		fout << str;
	}


}


int main()
{
	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n Orlov Vladimir HomeWork_12_03_2019_1552403768 \n\n";
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