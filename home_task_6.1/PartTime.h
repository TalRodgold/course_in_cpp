//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 6 question 1
//this program recives from user detailes about 2 types of workers: part time and full time
// then the program calculates the holiday bounus
#pragma once
#include "Employee.h"
class PartTime : public Employee
{
	float hour_sallery;

public:
	PartTime(string n, int i, int s, float p, float h); // constractor
	PartTime(); // default constractor
	void set_hour_sallery(float); // set hour salery
	float get_hour_sallery(); // get hour salery
	float salary(); // salery
	float salaryAfterBonus(); // functuion to calculate salary after bonus
	friend ostream& operator<<(ostream& os, const  PartTime& in); // cout
	friend istream& operator>>(istream& is, PartTime& in); // cin
};

