//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 6 question 1
//this program recives from user detailes about 2 types of workers: part time and full time
// then the program calculates the holiday bounus
#include "Employee.h"
#include <iostream>
#include <string>
using namespace std;

Employee::Employee(string n, int i, int s, float p) // constructor
{
	set_name(n); // initializ name
	set_id(i); // initializ id
	set_seniority(s); // initializ seniority
	set_pay(p); // initializ pay
}

void Employee::set_name(string n) // set name
{
	name = n;
}

void Employee::set_id(int i) // set id
{
	if (i < 0) // if invalid input
	{
		throw "ERROR";
	}
	id = i;
}

void Employee::set_seniority(int s) // set seniority
{
	if (s < 0) // if invalid input
	{
		throw "ERROR";
	}
	seniority = s;
}

void Employee::set_pay(float p) // set pay
{
	if (p < 0) // if invalid input
	{
		throw "ERROR";
	}
	pay = p;
}

string Employee::get_name() // get name
{
	return name;
}

int Employee::get_id() // get id
{
	return id;
}

int Employee::get_seniority() // get seniority
{
	return seniority;
}

float Employee::get_pay() // get pay
{
	return pay;
}

float Employee::salaryAfterBonus() // functuion to calculate salary after bonus
{
	if (seniority <= 5) // if 5 years or less in company
	{
		return (pay / 12) + 500;
	}
	return (pay / 12) * 1.25; // if more than 5 years
}

ostream& operator<<(ostream& os, const Employee& in) // cout
{
	os << "Employee: " << in.name << endl;
	os << "Employee ID: " << in.id << endl;
	os << "Years Seniority: " << in.seniority << endl;
	return os;
}

istream& operator>>(istream& is, Employee& in) // cin
{
	cout << "Enter employee details:" << endl; // print
	string input_name; // name
	int input_id; // id
	int input_seniorty; // seniorty
	float input_pay; // pay
	is >> input_name >> input_id >> input_seniorty >> input_pay;
	in.set_name(input_name);
	in.set_id(input_id);
	in.set_seniority(input_seniorty);
	in.set_pay(input_pay);
	return is;
}
