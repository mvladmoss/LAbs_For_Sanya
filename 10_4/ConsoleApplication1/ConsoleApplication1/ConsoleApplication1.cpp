#include"stdafx.h"
#include<iostream>
#include<vector>
#include <string>
#include<fstream>
#include<cstdlib>
#include<windows.h>
using namespace  std;
int number(char);
int kolichestvo_things;
struct Tovar
{
	string Name;
	string day_month_year;
	int number_of_tovar;
	int price_of_tovar;
	int day, month, year;
	void get_information();
	void output_information(int)const;
	void out(int);
	void in();
	void inicilization();
};

void Tovar::get_information()
{
	cout << "Name:"; cin >> Name;
	cout << "Data:"; cin >> day_month_year;
	cout << "Number:"; cin >> number_of_tovar;
	cout << "Price:"; cin >> price_of_tovar;
}
void Tovar::output_information(int d)const
{
	cout <<d<<")" << Name << " " << number_of_tovar << " " << price_of_tovar << " " << day_month_year;
}
void Tovar::inicilization()
{
	day = 10 * number(day_month_year[0]) + number(day_month_year[1]);
	month = 10 * number(day_month_year[3]) + number(day_month_year[4]);
	year = 1000 * number(day_month_year[6]) + 100 * number(day_month_year[7]) + 10 * number(day_month_year[8]) + number(day_month_year[9]);
}
void Tovar::out(int d) {
	ifstream k("k.txt");
	for (int z = 0; z < d; z++) {
		char* str = new char[100];
		k.getline(str, 100);
	}
	k >> Name; k >> day_month_year; k >> number_of_tovar; k >> price_of_tovar;
	k.close();
}
void Tovar::in()
{
	ofstream zapis("k.txt", ios::app);
	zapis << Name << " "; zapis << day_month_year << " "; zapis << " "; zapis << number_of_tovar << "  "; zapis << price_of_tovar << " " << endl;
	zapis.close();
}
struct Bank_of_Tovar :public Tovar
{
	int nomer;
	vector<Tovar> list;
	vector<Tovar> list_for_task;
	void add_new_thing(Tovar);
	void output_information_list();
	void sort_stright();
	void quick_sort(vector<string>&, int, int);
	void temp();
	void find(string);
	int bin_search(Bank_of_Tovar s, string temp, int start, int end);
	void output_from_file(Tovar, int);
	void record_things(int);
	void output_information_list_for_task();
	void output_finding_person(int);
};
void Bank_of_Tovar::add_new_thing(Tovar temp)
{
	temp.get_information();
	list.push_back(temp);
	kolichestvo_things++;
}
void Bank_of_Tovar::find(string fint)
{
	bool finding = false;
	for (int i = 0; i<kolichestvo_things; i++)
	{
		if (list[i].Name == fint)
		{
			finding = true;
			nomer = i;
			break;
		}
	}
	if(!finding)
	{
		nomer = -1;
	}
}
void Bank_of_Tovar::sort_stright()
{
	string min;
	int index;
	for (int i = 0; i<kolichestvo_things - 1; i++)
	{
		min = list[i].Name;
		index = i;
		for (int j = i + 1; i < kolichestvo_things; j++) {
			if (j == kolichestvo_things)
				break;
			if (min>list[j].Name) {
				min = list[j].Name;
				index = j;
			}
		}
		swap(list[i], list[index]);
	}
}
void Bank_of_Tovar::temp()
{
	vector<string> tempv;
	for (int i = 0; i<kolichestvo_things; i++)
	{
		tempv.push_back(list[i].Name);
	}
	quick_sort(tempv, 0, kolichestvo_things - 1);
}
void Bank_of_Tovar::quick_sort(vector<string>&temp, int start, int end)
{
	int i = start, j = end;
	string mid = temp[(i + j) / 2];
	int middle_position = (i + j) / 2;
	while (i <= j)
	{
		while (temp[i] < mid)
			i++;
		while (temp[j] > mid)
			j--;
		if (i <= j)
		{
			swap(temp[i], temp[j]);
			swap(list[i], list[j]);
			i++;
			j--;
		}
	}
	if (j > start)
		quick_sort(temp, start, j);
	if (i < end)
		quick_sort(temp, i, end);
}
void Bank_of_Tovar::output_information_list()
{
	for (int i = 0; i<kolichestvo_things; i++)
	{
		list[i].output_information(i+1);
		cout << endl;
	}
}
void Bank_of_Tovar::output_information_list_for_task()
{
	int kol_for_task = 0;
	string time;
	cout << "Please,write the data(Day.Month.Year):"; cin >> time;
	int day_time = 10 * number(time[0]) + number(time[1]); int month_time = 10 * number(time[3]) + number(time[4]); int year_time = 1000 * number(time[6]) + 100 * number(time[7]) + 10 * number(time[8]) + number(time[9]);
	for (int i = 0; i < kolichestvo_things; i++)
	{
		list[i].inicilization();
		if (list[i].price_of_tovar > 100000) {
			if ((list[i].year - year_time <= -2) || (list[i].year-year_time==-1 && list[i].month==12 && month_time==1 && (day_time+(30-list[i].day)>=30))||
				(list[i].year<year_time && abs(list[i].month-month_time)<11)|| (list[i].year==year_time && (month_time- list[i].month) > 1) || 
				(list[i].year == year_time &&(abs(list[i].month - month_time) == 1) &&  (day_time- list[i].day<= 0)) ) {
				list_for_task.push_back(list[i]);
				kol_for_task++;
			}
		}
	}
		for (int i = 0; i < kol_for_task; i++)
		{
			list_for_task[i].output_information(i+1);
			cout << endl;
		}
	if(list_for_task.size()==0)
	{
		cout << "There is no such things" << endl;
	}
}

void Bank_of_Tovar::output_from_file(Tovar s, int d) {
	s.out(d);
	list.push_back(s);
}
int Bank_of_Tovar::bin_search(Bank_of_Tovar s, string temp, int start, int end)
{
	int i = start;
	int j = end;
	string mid_element = list[(i + j) / 2].Name;
	int mid = (i + j) / 2;
	if (temp == mid_element) {
		nomer = mid;
		return 0;
	}
	if(start==end && temp!=mid_element)
	{
		nomer = -1;
		return 0;
	}
	else if (temp > mid_element)
		bin_search(s, temp, mid + 1, end);
	else if (temp < mid_element) {
		bin_search(s, temp, start, mid - 1);
	}
}
void Bank_of_Tovar::record_things(int number)
{
	list[number].in();
}
void Bank_of_Tovar::output_finding_person(int d)
{
	list[d].output_information(0);
}
int main()
{
	Bank_of_Tovar s;
	Tovar q;
	ifstream kol("kol.txt");
	kol >> kolichestvo_things;
	kol.close();
	char vib;
	char vibor;
	if (kolichestvo_things == 0) {
		cout << "There is no any things in data base.Would you like to add something(Y/N):"; cin >> vibor;
	switch(vibor)
	{
	case 'Y':
	{
		Sleep(1000);
		s.add_new_thing(q); cout << "Data was successfully added";
		system("cls");
		cout << "would you like yo continue(Y/N):";
		cin >> vibor;
		break; 
	}
	case 'N': {
		system("cls");
		cout << "Good luck";
		Sleep(2000);
			exit(0);
	}
	}
	}
	else {
		cout << "Would you like to downoload previous loaded information(Y/N):"; cin >> vib;
		if (vib == 'Y') {
			for (int i = 0; i < kolichestvo_things; i++)
			{
				s.output_from_file(q, i);
			}
		}
	}
	system("cls");
	do {
		cout << "1)Add   " << "2)View list   " << "3)View list for task   " << "4)Find   " << "5)Sort   " << endl;
		cout << "Your choose:"; cin >> vibor;
		switch (vibor)
		{
		case '1':
		{
			system("cls");
			s.add_new_thing(q);
			cout << "Would you like to continue(Y/N):"; cin >> vibor;
			system("cls");
				break;
		}
		case '2':
		{
			system("cls");
			s.output_information_list();
			cout << "Would you like to continue(Y/N):"; cin >> vibor;
			system("cls");
			break;
		}
		case '3':
		{
			s.output_information_list_for_task();
			cout << "Would you like to continue(Y/N):"; cin >>vibor;
				system("cls");
			break;
		}
		case '4':
		{
			char otvet;
			system("cls");
			cout << "What type of founding would you like you to choose:" << endl;
			cout << "1)linear search" << endl;
			cout << "2)binary search" << endl;
			cout << "Your choose:"; cin >> otvet;
			system("cls");
			if (otvet == '1')
			{
				string find;
				cout << "Enter the name of thing:"; cin >> find;
				s.find(find);
				if (s.nomer == -1)
				{
					cout << "There is no such thing in data base";
				}
				else
				{
					s.output_finding_person(s.nomer);
				}
				cout <<endl<< "Would you like to continue(Y/N):"; cin >> vibor;
				system("cls");
				break;
			}
			else if (otvet == '2')
			{
				system("cls");
				char bin;
				Bank_of_Tovar tempory = s;
				cout << "What type of sort would you like to choose:" << endl << "1)Quick sort" << endl << "2)Stright sort:"; cin >> bin;
				if (bin == '1')
				{
					tempory.temp();
				}
				else if (bin == '2')
				{
					tempory.sort_stright();
				}
				system("cls");
				string find;
				cout << "Enter the name of thing:"; cin >> find;
				tempory.bin_search(tempory, find, 0, kolichestvo_things - 1);
				if(tempory.nomer==-1)
				{
					cout << "There is no such thing in data base"<<endl;
				}
				else
				{
					tempory.output_finding_person(tempory.nomer);
				}
				cout<< endl<<"Would you like to continue(Y/N):"; cin >> vibor;
				system("cls");
				break;
			}
		}

		case '5':
		{
			system("cls");
			char bin;
			cout << "What type of sort would you like to choose:" << endl << "1)Quick sort" << endl << "2)Stright sort:"; cin >> bin;
			if (bin == '1')
			{
				s.temp();
			}
			else if (bin == '2')
			{
				s.sort_stright();
			}
			cout << "Would you like to continue(Y/N):"; cin >> vibor;
			break;
		}
		}
	} while (vibor=='Y');
	ofstream z("k.txt", ios::out);
	z.close();
	for (int q = 0; q<kolichestvo_things; q++)
	{
		s.record_things(q);
	}
	ofstream b("kol.txt");
	b << kolichestvo_things;
	b.close();
	system("pause");
	return 0;
}
int  number(char s)
{
	if (s == '0')
		return 0;
	if (s == '1')
		return 1;
	if (s == '2')
		return 2;
	if (s == '3')
		return 3;
	if (s == '4')
		return 4;
	if (s == '5')
		return 5;
	if (s == '6')
		return 6;
	if (s == '7')
		return 7;
	if (s == '8')
		return 8;
	if (s == '9')
		return 9;
}
