//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 10 question 1
//this program holds a database of soldiers

#pragma once
#include <iostream>
#include <string>
#include "Private.h"
using namespace std;

class Commander : public Private
{
public:
	bool combat;
	Commander(int, string, string, int, bool b = 0); // constructor
	void print(); // print
	bool medal()override; // worthy of a medal
	virtual string soldier_type(); // soldier type
	bool is_combat() { return combat; }; // is a combat soldier
	virtual string get_first_name() { return first_Name; }; // get first name
	virtual string get_last_name() { return last_Name; }; // get last name
};
