//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 6 question 1
//this program recives from user detailes about 2 types of workers: part time and full time
// then the program calculates the holiday bounus
#include "FullTime.h"
#include <iostream>
#include <string>
using namespace std;

FullTime::FullTime(string n, int i, int s, float p) :Employee(n, i, s, p) // constractor
{
	set_year_sallery();
}

FullTime::FullTime() : Employee("", 0, 0, 0) // default constractor
{
	year_sallery = 0;
}

void FullTime::set_year_sallery() // set year sallery
{
	year_sallery = pay;
}

float FullTime::get_year_sallery() // get year sallery
{
	return year_sallery;
}

float FullTime::salary() // salary
{
	return year_sallery / 12;
}

ostream& operator<<(ostream& os, const FullTime& in) // cout
{
	os << (Employee&)in; // print from employee
	cout << "Salary per Month: " << (in.year_sallery / 12) << endl; // print year sallery
	return os;
}

istream& operator>>(istream& is, FullTime& in) // cin
{
	is >> (Employee&)in; // read from employee
	in.set_year_sallery(); // set year sallery
	return is;
}
