#include"stdafx.h"
#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<iomanip>
#include<vector>
#include<windows.h>
#pragma warning(disable:4996);
int i;
using namespace std;
class Person {
private:
	string name;
	int group, math, physics, informatic, chemistry, mark;
public:
	void getdata() {
		cout << "Initials:"; cin >> name;
		cout << " number of group:"; cin >> group;
		cout << "Math:"; cin >> math;
		cout << "Physics:"; cin >> physics;
		cout << "Informatic:"; cin >> informatic;
		cout << "Chemistry:"; cin >> chemistry;
		mark = (math + chemistry + physics + informatic) / 4;
	}
	void out(int d);
	void showdata(int)const;
	void in();
	void record_pupils();
};
void Person::showdata(int number)const {
	cout << number + 1 << ")" << name << '\t' << group << '\t' << math << '\t' << physics << '\t' << informatic << '\t' << chemistry << '\t' << endl;
}
void Person::out(int d) {
	ifstream k("k.txt");
	for (int z = 0; z < d; z++) {
		char* str = new char[100];
		k.getline(str, 100);
	}
	k >> name; k >> group; k >> math; k >> physics; k >> informatic; k >> chemistry;
	mark =(math + chemistry + physics + informatic)/4;
}
void Person::in()
{
	ofstream zapis("k.txt", ios::app);
	zapis << name << " "; zapis << group << " "; zapis << math << " "; zapis << physics << " "; zapis << informatic << " "; zapis << chemistry << endl;
	zapis.close();
}
void Person::record_pupils(){
	if(mark>=8)
	{
		ofstream record_pupil("best_pupils.txt", ios::app);
		record_pupil<< name << " "; record_pupil << group << " "; record_pupil << math << " "; record_pupil << physics << " "; record_pupil << informatic << " "; record_pupil << chemistry << endl;
		record_pupil.close();
	}
}
class arr :public Person {
private:vector<Person> p;
public:
	void add(Person);
	void display(int)const;
	void output(Person, int);
	void correct(int);
	void record_pupil(int);
	void best_pupils_record(int);
};
void arr::add(Person s) {
	p.push_back(s);
}
void arr::display(int d)const {
	p[d].showdata(d);
}
void arr::output(Person s, int d) {
	s.out(d);
	p.push_back(s);
}
void arr::correct(int d) {
	p[d].getdata();
}
void arr::record_pupil(int number)
{
	p[number].in();

}
void arr::best_pupils_record(int end)
{
		p[end].record_pupils();
    
}
int main() {
	int vibor;
	ifstream q("kol.txt");
	q >> i;
	q.close();
	Person r;
	arr s;
	for (int k = 0; k < i; k++) {
		s.output(r, k);
	}
	char ch;
	do {
		cout << "1.Add" << endl << "2.Correct inforamtion" << endl << "3.Show information:";
		cin >> ch;
		switch (ch) {
		case '1': {
			system("cls");
			cout << "Enter the inforamtion for " << i + 1 << " person:" << endl;;
			r.getdata();
			s.add(r);
			i++;
			ofstream b("kol.txt");
			b << i;
			break; }
		case '2': {
			system("cls");
			for (auto j = 0; j < i; j++) 
				s.display(j);
			cout << endl << "Enter the number of pupil"; cin >> vibor;
			s.correct(vibor - 1);
			break;
		}
		case '3': {
			if (i == 0)
			{
				system("cls");
				cout << "There is no pupil";
				Sleep(1000);
			}
			system("cls");
			for (auto j = 0; j < i; j++) {
				s.display(j);
			}
			break;
		}
		}
		char check;
		cout << endl;
		cout << "If you want to continue push Y,else N:";
		cin >> ch;
		system("cls");
	} while (ch != 'N');
	ofstream record_pupil("best_pupils.txt", ios::out);
	record_pupil.close();
	for(int n=0;n<i;n++)
	{
		s.best_pupils_record(n);
	}
	if (i != 0) {
		system("cls");
		cout << "please wait,recording data to a file";
		Sleep(2000);
		ofstream z("k.txt", ios::out);
		z.close();
		for(int q=0;q<i;q++)
		{
			s.record_pupil(q);
		}
	}
	system("print best_pupils.txt");
	return 0;
}
