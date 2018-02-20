#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<Windows.h>
using namespace std;
struct link
{
	int data;
	link* next;
	link* previous;
};
struct two_linklink {
private:
	link* first;
	link* last;
	int number = 0;
public:
	two_linklink()
	{
		first = nullptr;
		last = nullptr;
	}
	void push_back();
	void display();
	void pop_back();
	void inicilization();
	void dell_task();
	int numb();
	link* dell_first(link*);
	link* dell_last(link*);
};
int two_linklink::numb()
{
	return number;
}
void two_linklink::inicilization()
{
	system("cls");
	cout << "Enter please the number"; int answer; cin >> answer;
	link* newlink = new link;
	newlink->data = answer;
	newlink->next = nullptr;
	newlink->previous = nullptr;
	first = newlink;
	last = newlink;
}
void two_linklink::push_back()
{
	system("cls");
	cout << "Enter please the number"; int answer; cin >> answer;
	link* newlink = new link;
	newlink->data = answer;
	newlink->previous = first;
	newlink->next = nullptr;
	first->next= newlink;
	first = newlink;
}
void two_linklink::pop_back()
{
	system("cls");
	cout << "Enter please the number"; int answer; cin >> answer;
	link* newlink = new link;
	newlink->data = answer;
	newlink->next = last;
	newlink->previous = nullptr;
	last->previous= newlink;
	last = newlink;
}
void two_linklink::display()
{
	char answer;
	cout << "Do you want to display:" << endl << "1)From start" << endl << "2)From end" << endl << "Your answer:"; cin >> answer;
	switch (answer)
	{
	case '1':
	{
		link* temp = last;
		while (temp !=nullptr)
		{
			cout << temp->data << "   ";
			temp = temp->next;
		}
		break;
	}
	case '2':
	{
		link* temp = first;
		while (temp !=nullptr)
		{
			cout << temp->data << " ";
			temp = temp->previous;
		}
		break;
	}
	}
}
void two_linklink::dell_task()
{
	first=dell_first(first);
	link* qwerty = first;
	link* temp = first;
	
	while(temp!=nullptr)
	{
		temp = dell_last(temp->previous);
		if (temp == nullptr) {
			break;
		}
		first->previous = temp;
		first = temp;
	}
	first = qwerty;
}
link* two_linklink::dell_first(link* temp)
{
	if(temp==last)
	{
		if (temp->data % 2 == 0)
		{
			link* s = temp;
			last = nullptr;

			delete s;
			return nullptr;
		}
		else {
			number++;
			return last;
		}
	}

		if (temp == nullptr)
		{
			return nullptr;
		}
		while (temp->data % 2 == 0) {
			link* q = temp;
			temp = temp->previous;
			temp->next = nullptr;
			delete q;
			if (temp == nullptr)
				break;
		}
		if (temp == nullptr)
		{
			return nullptr;
		}
		else
		{
			number++;
			return temp;
		}
}
link* two_linklink::dell_last(link* temp)
{
	if (temp == nullptr)
		return nullptr;
	if (temp == last)
	{
		if (temp->data % 2 == 0)
		{
			link* s = temp;
			temp->next->previous = nullptr;
			last = temp->next;
			delete s;
			return nullptr;
		}
		else {
			number++;
			return nullptr;
		}
	}
	while(temp->data%2==0)
	{
		link* q=temp;
		temp->previous->next= temp->next;
		temp->next->previous = temp->previous;
		temp = temp->previous;
		delete q;
		if (temp == nullptr)
			break;
	}
	if (temp == nullptr)
	{
		return nullptr;
	}
	else
	{
		number++;
		return temp;
	}
}
int main()
{
	two_linklink s;
	char q;
	cout << "Stack is empty.Would you like to add number(Y/N):"; cin >> q;
	switch (q)
	{
	case 'Y': {
		system("cls"); cout << "Enter please the number:";
		s.inicilization();
		system("cls"); cout << "Would you like to continue(Y/N):"; cin >> q;
		if (q == 'Y')
			break;
		else {
			cout << "Good luck";
			Sleep(2000);
			exit(0);
		}
	}
	}
	char answer;
	do {
		cout << "1)Push_back" << "   " << "2)Pop_back" << "   " << "3)Display" <<"    "<<"4)Task"<< endl;
		cout << "Your answer(N if you want to exit):"; cin >> answer;
		switch (answer)
		{
		case '1':
		{
			system("cls");
			s.push_back();
			char temp;
			system("cls"); cout << "Would you like yo continue(Y/N):"; cin >> temp;
			if (temp == 'Y')
				break;
			else if (temp == 'N') {
				cout << "Good luck";
				Sleep(2000);
				exit(0);
			}
		}
		case '2':
		{
			s.pop_back();
			char temp;
			system("cls"); cout << "Would you like yo continue(Y/N):"; cin >> temp;
			if (temp == 'Y')
				break;
			else if (temp == 'N') {
				cout << "Good luck";
				Sleep(2000);
				exit(0);
			}
		}
		case '3':
		{
			s.display();
			char temp;
			system("pause");
			system("cls"); cout << "Would you like yo continue(Y/N):"; cin >> temp;
			if (temp == 'Y')
				break;
			else if (temp == 'N') {
				cout << "Good luck";
				Sleep(2000);
				exit(0);
			}
		}
		case '4':
		{
			char temp;
			s.dell_task();
			int k = s.numb();
			if (k == 0)
			{
				cout << "Stack is empty.Would you like to add number(Y/N):"; cin >> q;
				switch (q)
				{
				case 'Y': {
					system("cls"); cout << "Enter please the number:";
					s.inicilization();
					system("cls"); cout << "Would you like to continue(Y/N):"; cin >> q;
					if (q == 'Y')
						break;
					else {
						cout << "Good luck";
						Sleep(2000);
						exit(0);
					}
				}
				}
			}
			else {
				system("cls"); cout << "Would you like yo continue(Y/N):"; cin >> temp;
				if (temp == 'Y')
					break;
				else if (temp == 'N') {
					cout << "Good luck";
					Sleep(2000);
					exit(0);
				}
			}
		}
		}
	} while (answer != 'N');
	return 0;
}

