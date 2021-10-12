//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 11 question 1
//this program holds a database of families and does multiple functions on it.
#pragma once
#include <fstream>
#include <iostream>
using namespace std;
class Family
{
	int family_number;
	char family_name[20]{};
	int number_of_souls;
	int phone_number;
	bool afternoon_classes[6];
public:
	Family(); // default
	Family(int,char*,int,int,bool*); // constructor
	int get_family_number(); // get family number
	bool* get_afternoon_classes(); // get afternoon classes
	void set_afternoon_classes(bool, int); // set afternoon classes
	char* get_family_name(); // get family name
	friend ostream& operator<<(ostream& os, const Family& in); // cout
};

