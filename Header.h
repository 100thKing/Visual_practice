#pragma once

#include "iostream"
#include "fstream"
#include "locale"
#include <iomanip>
using namespace std;

ofstream F1_write;
ifstream F1_read;
fstream F2;

struct Person
{
	string FIO;
	double phone_num;
	int birthday[3];
};

void Fill_bat_F1()
{
	F1_write << "Климов С. М. 11111111111 01 01 2000";
	F1_write << endl;
	F1_write << "Морозов П. С. 22222222222 02 02 2000";
	F1_write << endl;
	F1_write << "Царев А. А. 33333333333 03 03 2000";
	F1_write << endl;
	F1_write << "Ильина М. А. 44444444444 04 04 2000";
	F1_write << endl;
	F1_write << "Медведев М. Д. 55555555555 05 05 2000";
	F1_write << endl;
	F1_write << "Горбунов М. Ю. 66666666666 06 06 2000";
	F1_write << endl;
	F1_write << "Куликов Н. В. 77777777777 07 07 2000";
	F1_write << endl;
	F1_write << "Наумов А. Д. 88888888888 08 08 2000";
	F1_write << endl;

}

void Read_bat_F1(Person arr[])
{
	string buff;
	for (int k = 0; k < 8; k++)
	{
		arr[k].FIO += "";
	}


	for (int i = 0; i < 8; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			F1_read >> buff;
			arr[i].FIO += buff + " ";
		}
		F1_read >> arr[i].phone_num;
		for (int k = 0; k < 3; k++)
		{
			F1_read >> arr[i].birthday[k];
		}
	}
}

void Fill_bat_F2(Person arr[])
{
	for (int i = 0; i < 8; i++)
	{
		F2 << arr[i].FIO;
		F2 << setprecision(12) << arr[i].phone_num << " ";
		for (int k = 0; k < 3; k++)
		{
			F2 << arr[i].birthday[k] << " ";
		}
		F2 << endl;
	}
}

void bubbleSort(Person arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j].FIO > arr[j + 1].FIO)
				swap(arr[j], arr[j + 1]);
}

bool Open_bats()
{
	F1_write.open("D:/CODE/Практика/F1.bat");
	F1_read.open("D:/CODE/Практика/F1.bat");
	F2.open("D:/CODE/Практика/F2.bat");
	if (!F1_write.is_open())
	{
		cout << "Файл F1 не найден";
		cout << endl << endl;
		return -1;
	}
	if (!F2.is_open())
	{
		cout << "Файл F2 не найден";
		cout << endl << endl;
		return 0;
	}
}

void Close_bats()
{
	F1_read.close();
	F1_write.close();
	F2.close();
}


//int main()
//{
//	Person student[8];
//	setlocale(LC_ALL, "rus");
//
//	Open_bats();
//
//	Fill_bat_F1();
//
//	Read_bat_F1(student);
//
//	bubbleSort(student, 8);
//
//	Fill_bat_F2(student);
//
//	Close_bats();
//
//}