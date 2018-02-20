#include "stdafx.h"
#include<iostream>
#include <algorithm>
#include<iomanip>
#include<Windows.h>
using namespace  std;
struct link
{
	int data;
	link* next;
};
struct linklist
{
private:
	link* first;
	int number=0;
public:
	linklist()
	{first = nullptr;}
	void push_back(int);
	void pop_back();
	void pop_back_with_display();
	void display();
	void del();
	
	link* delet(link*);
	void sorting_elements();
	void sorting_ptr();
	void delet_all_stack();
	void format();
};
void linklist::push_back(int d)
{
	link* newlink = new link;
	newlink->data = d;
	newlink->next =first;
	first = newlink;
}
void linklist::pop_back()
{
	link* templink = first;
	first = first->next;
	delete templink;
}
void linklist::pop_back_with_display()
{
	link* templink = first;
	cout << first->data;
	first = first->next;
	delete templink;
}
void linklist::delet_all_stack()
{
while(first)
{
	link* templink = first;
	first = first->next;
	delete templink;
}
}
void linklist::display()
{
	link* current = first;
	int count = 0;
	while(current)
	{
		cout << count+1<<")"<<current->data << " ";
		current = current->next;
		count++;
	}
}
void linklist::format()
{
	display();
	cout << endl;
	int answer;
	cout << "Please enter the place:"; cin >> answer;
	link* temp = first;
	while(answer-1)
	{
		temp = temp->next;
		answer--;
	}
	system("cls");
	int value;
	cout << "Enter new value:"; cin >> value;
	temp->data = value;
}
link* linklist::delet(link* temp)
{
	if (temp != nullptr) {
		while (temp->data % 2 == 0) {
			link * q=temp;
			temp = temp->next;
			delete q;
			if (temp == nullptr)
				break;
		}
	}
	if (temp == nullptr)
	{
		return nullptr;
	}
	else {
		number++;
		return temp;
	}
}
void linklist::del()
{
	link* s;
	first = delet(first);
	link* current=first;
	s =first;
	while(s!=nullptr)
	{
		s=delet(first->next);
		if (s == nullptr) {
			link* newlink = nullptr;
			first->next = newlink;
			break;
		}
		first->next= s;
		first = s;
	
	}
	first = current;
	if (number == 0)
		cout << "Thers is no elements now";
}
void linklist::sorting_elements()
{
	link* temp = first;
	link* current;
	int min;
	link* t=nullptr;
	while(temp)
	{
		current = temp;
		min = temp->data;
		while(current)
		{
			if(min>=current->data)
			{
				min = current->data;
				t = current;
			}
			current=current->next;
		}
		swap(t->data, temp->data);
		temp = temp->next;
	}
}
void linklist::sorting_ptr()
{
	link* newlink = new link;
	newlink->next = first;
	first = newlink;
	link* current = nullptr;
	link *now, *temp;
	if (first->next->next == nullptr)
		return;
	do
	{
		for(now=first;now->next->next!=current;now=now->next)
			if(now->next->data>now->next->next->data )
			{
				temp = now->next->next;
				now->next->next=temp->next;
				temp->next = now->next;
				now->next=temp;
			}
		current = now->next;
	} while (first->next->next != current);
	link* t = first;
	first = first->next;
	delete t;
}
int main()
{
	linklist s;
	char answer;
	cout << "Stack is empty.Would you like to add number(Y/N):"; cin >> answer;
	switch (answer)
	{
	case 'Y': {
		system("cls"); cout << "Enter please the number:";
		int number; cin >> number;
		s.push_back(number);
		system("cls"); cout << "Would you like to continue(Y/N):"; cin >> answer;
		if (answer == 'Y')
			break;
		else {
			cout << "Good luck";
			Sleep(2000);
			exit(0);
		}
	}
	case 'N':
	{
		exit(0);
	}
	}
	do {
		system("cls");
		cout << "1)Add element" << "   " << "2)Delete element" << "    " << "3)Sort" << "    " << "4)Task" << "    " << "5)Formating"<<"    "<<"6)Display";
		cout << endl << "You answer(N if you want to exit):"; cin >> answer;
		switch (answer)
		{
		case '1':
		{
			system("cls"); cout << "Enter please the number:";
			int number; cin >> number;
			s.push_back(number);
			char temp;
			system("cls"); cout << "Would you like yo continue(Y/N):"; cin >>temp;
			if (temp== 'Y')
				break;
			else if (temp == 'N') {
				cout << "Good luck";
				Sleep(2000);
				exit(0);
			}
		}
		case '2':
		{
			char l;
			system("cls");
			cout << "1)Pop_back" << "   " << "2)Pop_back with display" << "   " << "3)Delete all stack"; cout << endl << "You answer:"; cin >>l;
			switch (l)
			{
			case '1':
			{
				s.pop_back();
				break;
			}
			case '2':
			{
				s.pop_back_with_display();
				break;
			}
			case '3':
			{
				s.delet_all_stack();
			}
			}
			char temp;
			Sleep(2000);
			system("cls"); cout << "Would you like yo continue(Y/N):"; cin >>temp;
			if (temp== 'Y')
				break;
			else if(temp=='N'){
				cout << "Good luck";
				Sleep(2000);
				exit(0);
			}
		}
		case '3':
		{
			char temp;
			system("cls"); cout << "1)Sort  ptr" << "   " << "2)Sort elemetns"; cout << endl << "You answer:"; cin >> temp;
			switch (temp)
			{
			case '1':
			{
				s.sorting_ptr();
			}
			case '2':
				s.sorting_elements();
			}
			system("cls"); cout << "Would you like yo continue(Y/N):"; cin >>temp;
			if (temp== 'Y')
				break;
			else if (temp == 'N') {
				cout << "Good luck";
				Sleep(2000);
				exit(0);
			}
		}
		case '4':
		{
			s.del();
			Sleep(5000);
			char temp;
			system("cls"); cout << "Would you like yo continue(Y/N):"; cin >>temp;
			if (temp== 'Y')
				break;
			else if (temp == 'N') {
				cout << "Good luck";
				Sleep(2000);
				exit(0);
			}
		}
		case '5':
		{
			s.format();
			char temp;
				system("cls"); cout << "Would you like yo continue(Y/N):"; cin >>temp;
			if (temp== 'Y')
				break;
			else if (temp == 'N') {
				cout << "Good luck";
				Sleep(2000);
				exit(0);
			}
		}
		case '6':
			{
			s.display();
			char temp;
		    cout<<endl << "Would you like yo continue(Y/N):"; cin >>temp;
			if (temp == 'Y')
				break;
			else if (temp == 'N') {
				cout << "Good luck";
				Sleep(2000);
				exit(0);
			}
			}
		}
	} while (answer != 'N');
	system("pause");
	return 0;
}

