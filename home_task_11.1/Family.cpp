//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 11 question 1
//this program holds a database of families and does multiple functions on it.
#include "Family.h"
#include <cstring>
#include <iostream>
Family::Family() // default
{
	family_number = 0;
	number_of_souls = 0;
	phone_number = 0;
	for (int i = 0; i < 6; i++)
	{
		afternoon_classes[i] = false;
	}
}

Family::Family(int number, char* name, int souls, int phone, bool* classes) // constructor
{
	if (number < 0 || number > 101)
	{
		throw "ERROR: Invalid family number";
	}
	family_number = number;
	for (int i = 0; i < strlen(name) ; i++)
	{
		family_name[i] = name[i];
	}
	number_of_souls = souls;
	phone_number = phone;
	for (int i = 0; i < 6; i++)
	{
		afternoon_classes[i] = classes[i];
	}
}

int Family::get_family_number()  // get family number
{
	return family_number;
}

bool* Family::get_afternoon_classes() // get afternoon classes
{
	return afternoon_classes;
}

void Family::set_afternoon_classes(bool t_or_f, int num) // set afternoon classes
{
	afternoon_classes[num] = t_or_f;
}

char* Family::get_family_name() // get family name
{
	return family_name;
}

ostream& operator<<(ostream& os, const Family& in) // cout
{
	
	os << "Family name: " << in.family_name << endl;
	os << "Number os souls: " << in.number_of_souls << endl;
	os << "Phone number: " << in.phone_number << endl;
	os << "Afternoon classes: ";
	for (int i = 0; i < 6; i++)
	{
		if (in.afternoon_classes[i])
		{
			os << "Y  ";
		}
		else
		{
			os << "N  ";
		}
	}
	os << endl;
	return os;
}
