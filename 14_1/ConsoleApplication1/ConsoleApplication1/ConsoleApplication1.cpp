#include "stdafx.h"
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
void razbiv(vector<double>&, vector<double>&, double, double, double);
double Newton(double);
double func(double);
double det(double);
int main()
{
	vector<double> start;
	vector<double> end;
	double a, b, h;
	cout << "Enter please a:"; cin >> a;
	cout << "Enter please b:"; cin >> b;
	cout << "Enter please h:"; cin >> h;
	razbiv(start, end, a, b, h);
	for (int i = 0; i<start.size(); i++)
	{
		cout << start[i] << "     " << end[i] << endl;
	}

	system("pause");
	cout << endl << Newton(start[0]);
	cout << endl << Newton(start[1]);
	cout << endl << Newton(start[2]);
	system("pause");
	return 0;
}
double Newton(double start)
{
	double x = start;
	double x0 = start;
	double e = 0.000001;
	do
	{
		x0 = x;
		x = double(x0 - func(x) / det(x));

	} while (fabs(x-x0)> e);
	return x;
}
double det(double x)
{
	return (2 * x - 20 * sin(x)*cos(x));
}
double func(double x)
{
	return (x*x - 10 * sin(x)*sin(x) + 2);
}
void razbiv(vector<double>& nach, vector<double>& konec, double start, double end, double h)
{
	double j = start;
	double i = end;
	for (j; j <= i; j = j + h)
	{
		if (func(j)*func(j + h)< 0) {
			nach.push_back(j);
			konec.push_back(j + h);
		}
	}
}
