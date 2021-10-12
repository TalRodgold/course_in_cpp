//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 1 question 1
//This program checks if 2 rational numbers are equal to each other
#include"Rational.h"
#include <iostream>
using namespace std;

int main()
{
	int numerator, denominator;
	char tav;
	cout << "enter two rational numbers:" << endl;
	cin >> numerator >> tav >> denominator;
	Rational r1;
	r1.setNumerator(numerator);
	r1.setDenominator(denominator);
	cin >> numerator >> tav >> denominator;
	Rational r2;
	r2.setNumerator(numerator);
	r2.setDenominator(denominator);
	Rational ans = r1.add(r2);
	r1.print();
	cout << " + ";
	r2.print();
	cout << " = ";
	ans.print();
	cout << endl;
	if (r1.equal(r2))
		cout << "The two numbers are equal" << endl;
	else
	{
		cout << "The two numbers are different" << endl;
		r1.print();
		cout << " ";
		r2.print();
		cout << endl;
	}
	return 0;
}
//enter two rational numbers :
//1 / 2 3 / 6
//1 / 2 + 3 / 6 = 1 / 1
//The two numbers are equal
//
//C : \Users\talro\source\repos\semester_2\Debug\home_task_1.1.exe(process 9744) exited with code 0.
//To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
//Press any key to close this window . . .