//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 6 question 1
//this program recives from user detailes about 2 types of workers: part time and full time
// then the program calculates the holiday bounus
#pragma once
#include <string>
#include <iostream>
using namespace std;

class Employee
{
protected:
	string name;
	int id;
	int seniority;
	float pay;
public:
	Employee(string n, int i, int s, float p = 0); // constructor
	void set_name(string); // set name
	void set_id(int); // set id
	void set_seniority(int); // set seniority
	void set_pay(float); // set pay
	string get_name(); // get name
	int get_id(); // get id
	int get_seniority(); // get seniority
	float get_pay(); // get pay
	float salaryAfterBonus(); // functuion to calculate salary after bonus
	friend ostream& operator<<(ostream& os, const Employee& in); // cout
	friend istream& operator>>(istream& is, Employee& in); // cin
};

