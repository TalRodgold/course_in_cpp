//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 10 question 1
//this program holds a database of soldiers

#pragma once

#include "Soldier.h"


class Private : public Soldier
{
public:
	int* score = new int; // grades
	Private(int, string, string, int); // constructor
	bool medal()override; // worthy of a medal
	virtual string soldier_type(); // soldier type
	virtual void print(); // print
	virtual bool is_combat() { return false; }; // is a combat soldier
	virtual string get_first_name() { return first_Name; }; // get first name
	virtual string get_last_name() { return last_Name; }; // get last name
};



