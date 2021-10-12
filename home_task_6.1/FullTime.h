#pragma once
#include "Employee.h"
class FullTime : public Employee
{
	float year_sallery;
public:
	FullTime(string n, int i, int s, float p); // constractor
	FullTime(); // default constractor
	void set_year_sallery(); // set year sallery
	float get_year_sallery(); // get year sallery
	float salary(); // salary
	friend ostream& operator<<(ostream& os, const FullTime& in); // cout
	friend istream& operator>>(istream& is, FullTime& in); // cin
};

