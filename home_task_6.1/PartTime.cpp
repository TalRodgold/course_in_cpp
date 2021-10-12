//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 6 question 1
//this program recives from user detailes about 2 types of workers: part time and full time
// then the program calculates the holiday bounus
#include "PartTime.h"
#include <iostream>
#include <string>
using namespace std;
PartTime::PartTime(string n, int i, int s, float h, float p) :Employee(n, i, s, p) // constractor
{
	set_hour_sallery(h);
}

PartTime::PartTime() : Employee("", 0, 0, 0) // default constractor
{
	hour_sallery = 0;
}

void PartTime::set_hour_sallery(float h) // set hour salery
{
	if (h < 0) // if invalid input
	{
		throw "ERROR";
	}
	hour_sallery = h;
}

float PartTime::get_hour_sallery() // get hour salery
{
	return hour_sallery;
}

float PartTime::salary() // salery
{
	return hour_sallery ;
}

float PartTime::salaryAfterBonus() // functuion to calculate salary after bonus
{
	if (seniority <= 5) // if 5 years or less in company
	{
		return (pay * hour_sallery) + 500;
	}
	return (pay * hour_sallery) * 1.25; // if more than 5 years
}

ostream& operator<<(ostream& os, const PartTime& in) // cout
{
	os << (Employee&)in; // print from employee
	cout << "Hours: " << in.hour_sallery << endl; // print hour sallery
	cout << "Salary per Month: " << in.hour_sallery * in.pay << endl; // print sallery per month
	return os;
}

istream& operator>>(istream& is, PartTime& in) // cin
{
	cout << "Enter employee details:" << endl; // print
	string input_name; // name
	int input_id; // id
	int input_seniorty; // seniorty
	float input_pay; // pay
	float input_hours; // hours
	is >> input_name >> input_id >> input_seniorty >> input_hours >> input_pay;
	in.set_name(input_name);
	in.set_id(input_id);
	in.set_seniority(input_seniorty);
	in.set_pay(input_pay);
	in.set_hour_sallery(input_hours);
	return is;
}
