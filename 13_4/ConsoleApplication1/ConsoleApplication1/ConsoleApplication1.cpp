#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;
struct Data
{
	string name;
	int pasport;
	Data* left;
	Data* right;
	int status;
	Data() { status = 0; }
};
struct tree
{
private:
	Data* first;
	int kol_lists = 0;
	bool status_inicilization = false;
	bool find_status=false;
	vector<Data> gut;
	int level = 0;
public:
	tree() { first = nullptr; }
	void inicilization();
	void add(int, string);
	void procev(Data*, Data*);
	Data* del_main(Data*, int);
	void del(int);
	void inicilization_vect(Data*);
	void inicilization(int);
	void sorting_vector();
	void balance(tree&, int, int);
	void print_tree(Data*, int);
	void level_of_tree(Data*, int);
	void obnulenie_level();
	int show_level()const;
	Data* show_first()const;
	int size_vector()const;
	void display_vector();
	void kol_list(Data*);
	int show_lists();
	void delet_all_tree(Data*);
	void find(Data*,int);
	void new_status();
	bool ret_find_status();
	
};
void tree::new_status()
{
	find_status = false;
}
bool tree::ret_find_status()
{
	return find_status;
}
void tree::inicilization()
{
	cout << "Enter the pasport number:"; int number; cin >> number;
	cout << "Enter the Name:"; string s; cin >> s;
	Data* NewData = new Data;
	NewData->name = s; NewData->pasport = number;
	first = NewData;
	first->left = nullptr;
	first->right = nullptr;
}
void tree::inicilization(int data)
{
	Data* NewData = new Data;
	NewData->name = gut[data].name; NewData->pasport = gut[data].pasport;
	first = NewData;
	first->left = nullptr;
	first->right = nullptr;
}

void tree::display_vector()
{
	for (int i = 0; i<gut.size(); i++)
	{
		cout << gut[i].pasport << "  ";
	}
}
Data* tree::show_first()const
{
	return first;
}
int tree::size_vector() const
{
	return gut.size();
}
int tree::show_level()const
{
	return level;
}
void tree::obnulenie_level()//После каждого отображения дерева,что бы, если после просмотра изменился уровень(любые действия с деревом), можно было заново посчитать его высоту
{
	level = 0;
}
void tree::inicilization_vect(Data* temp)
{
	if (temp == nullptr)
		return;
	Data newlink;
	newlink.pasport = temp->pasport;
	newlink.left = temp->left;
	newlink.right = temp->right;
	newlink.name = temp->name;
	gut.push_back(newlink);
	inicilization_vect(temp->left);
	inicilization_vect(temp->right);
}
void tree::sorting_vector()
{
	for (int i = 0; i<gut.size(); i++)
	{
		for (int j = i + 1; j<gut.size(); j++)
		{
			if (gut[j].pasport <= gut[i].pasport)
				swap(gut[j].pasport, gut[i].pasport);
		}
	}
}
void tree::balance(tree &s, int start, int end)
{
	int mid = (start + end) / 2;
	if (start == end) {
		s.add(gut[mid].pasport, gut[mid].name);
		return;
	}
	
	if (s.first == nullptr)
	{
		cout << endl;
		s.gut = gut;
		s.inicilization(mid);
	}

	else {
		s.add(gut[mid].pasport, gut[mid].name);
	}
	balance(s, start, mid);
	balance(s, mid+1, end);

}
void tree::add(int data, string s)
{
	Data* newlink = new Data;
	newlink->left = nullptr;
	newlink->right = nullptr;
	newlink->name = s; newlink->pasport = data;
	Data* temp = first;
	procev(newlink, temp);
}
void tree::procev(Data* newlink, Data* exist)
{
	if (exist->pasport>newlink->pasport)
	{
		if (exist->left != nullptr)
			procev(newlink, exist->left);
		else
		{
			exist->left = newlink;
			return;
		}
	}
	if (exist->pasport<newlink->pasport)
	{
		if (exist->right != nullptr)
			procev(newlink, exist->right);
		else
		{
			exist->right = newlink;
			return;
		}
	}
}
void tree::level_of_tree(Data *temp, int lev) {
	if (temp) {
		level_of_tree(temp->right, lev + 1);
		level_of_tree(temp->left, lev + 1);
	}
	if (lev>level) {
		level = lev;
	}
}
void tree::print_tree(Data* p, int level)
{
	if (p)
	{
		print_tree(p->left, level + 1);
		for (int i = 0; i< level; i++) cout << "   ";
		cout << p->pasport << endl;
		print_tree(p->right, level + 1);
	}
}
Data* tree::del_main(Data* temp, int current)
{
	if (temp == nullptr) {
		return temp;
	}
	if (temp->pasport == current) {
		Data* k;
		if (temp->right == nullptr) {
			k = temp->left;
		}
		else {
			Data* ykaz = temp->right;
			if (ykaz->left == nullptr) {
				ykaz->left = temp->left;
				k = ykaz;
			}
			else {
				Data* min = ykaz->left;
				while (min->left != nullptr) {
					ykaz = min;
					min = ykaz->left;
				}
				ykaz->left = min->right;
				min->left = temp->left;
				min->right = temp->right;
				k = min;
			}
		}
		delete temp;
		return k;
	}
	else if (current<temp->pasport) {
		temp->left = del_main(temp->left, current);
	}
	else {
		temp->right = del_main(temp->right, current);
	}
	return temp;
}
void tree::del(int temp)
{
	first = del_main(first, temp);
}
void tree::kol_list(Data* temp)
{
	if (temp == nullptr)
		return;
	if (temp->left == nullptr && temp->right == nullptr)
	{
		kol_lists++;
	}
	kol_list(temp->left);
	kol_list(temp->right);
}
int tree::show_lists()
{
	kol_list(first);
	return kol_lists;
}
void tree::delet_all_tree(Data* temp)
{
	if (temp != nullptr) {
		delet_all_tree(temp->left);
		delet_all_tree(temp->right);
		delete temp;
	}
	first = nullptr;
}
void tree::find(Data* temp,int looking_up)
{
	if (temp == nullptr) {
		return ;
	}
	if (temp->pasport == looking_up) {
		find_status = true;
		cout << "Name:" << temp->name << endl;
	}
	find(temp->left, looking_up);
	find(temp->right, looking_up);
}
int main()
{
	tree s;
	char answer;
	cout << "The tree is empty.Would you like to create it(Y?N):"; cin >> answer;
	switch (answer) {
	case 'Y': {
		s.inicilization();
		system("cls");
		char k;
		cout << "Would you like to continue(Y/N):"; cin >> k;
		if (k == 'N')
		{
			system("cls");
			cout << "Good luck";
			Sleep(2000);
			exit(0);
		}
		else {
			break;
		}

	}
	case 'N': {
		system("cls");
		cout << "Good luck";
		Sleep(2000);
		exit(0);
			}
		}
		system("cls");
		char otvet;
		char k;
	do
	{
		system("cls");
		cout << "1)Add" << "   " << "2)Balance" << "   " << "3)Display" << "    " << "4)Task" <<"    "<<"5)Delete element"<<"    "<<"6)Delete all tree"<<"    "<<"7)Find"<<endl;
		cout << "Your answer(N if you want to exit):";cin>>otvet;
		switch(otvet)
		{
		case '1':
			{
			string temp; cout << "Enter the Name:"; cin >> temp;
			int number; cout << "Enter the pasport number:"; cin >> number;
			s.add(number, temp);
			system("cls");
			cout << "Would you like to continue(Y/N):"; cin >> k;
			if (k == 'N')
			{
				system("cls");
				cout << "Good luck";
				Sleep(2000);
				exit(0);
			}
			else {
				break;
			}
			}
		case '2':
			{
			tree new_tree;
			Data* temp = s.show_first();
			s.inicilization_vect(s.show_first());
			s.sorting_vector();
			s.balance(new_tree, 0, s.size_vector() - 1);
			s.delet_all_tree(temp);
			s = new_tree;
			cout << "Would you like to continue(Y/N):"; cin >> k;
			if (k == 'N')
			{
				system("cls");
				cout << "Good luck";
				Sleep(2000);
				exit(0);
			}
			else {
				break;
			}
			}
		case '3':
			{
			s.print_tree(s.show_first(), 0);
			cout << "Would you like to continue(Y/N):"; cin >> k;
			if (k == 'N')
			{
				system("cls");
				cout << "Good luck";
				Sleep(2000);
				exit(0);
			}
			else {
				break;
			}
			}
		case '4':
			{
			system("cls");
			s.kol_list(s.show_first());
			cout << s.show_lists() << endl;
			cout << "Would you like to continue(Y/N):"; cin >> k;
			if (k == 'N')
			{
				system("cls");
				cout << "Good luck";
				Sleep(2000);
				exit(0);
			}
			else {
				break;
			}
			}
		case '5':
			{
			system("cls");
			int temp;
			cout << "Enter the number:"; cin >> temp;
			s.del(temp);
			cout << "Would you like to continue(Y/N):"; cin >> k;
			if (k == 'N')
			{
				system("cls");
				cout << "Good luck";
				Sleep(2000);
				exit(0);
			}
			else {
				break;
			}
			}
		case '6':
			{
			s.delet_all_tree(s.show_first());
			cout << "The tree is empty.Would you like to create it(Y?N):"; cin >> answer;
			switch (answer) {
			case 'Y': {
				s.inicilization();
				system("cls");
				char k;
				cout << "Would you like to continue(Y/N):"; cin >> k;
				if (k == 'N')
				{
					system("cls");
					cout << "Good luck";
					Sleep(2000);
					exit(0);
				}
				else {
					break;
				}

			}
			case 'N': {
				system("cls");
				cout << "Good luck";
				Sleep(2000);
				exit(0);
			}
			}
			}
		case '7':
			{
			system("cls");
			int temp;
			cout << "Enter the number:"; cin >> temp;
			s.find(s.show_first(), temp);
				if(!s.ret_find_status())
				{
					cout << "There is no such element";
				}
				cout << "Would you like to continue(Y/N):"; cin >> k;
				if (k == 'N')
				{
					system("cls");
					cout << "Good luck";
					Sleep(2000);
					exit(0);
				}
			}
		}
	} while (otvet != 'N' || k!='N');
	return 0;
}