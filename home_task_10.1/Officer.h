//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 10 question 1
//this program holds a database of soldiers

#pragma once
#include <iostream>
#include <string>
#include "Soldier.h"
using namespace std;
class Officer : public Soldier
{
public:
	int sociometric;
	Officer(int, string, string, int, int); //constructor
	bool medal()override; // worthy of a medal
	virtual void print(); // print
	virtual string soldier_type(); // soldier type
	int get_score()const { return sociometric; }; // get score
	virtual string get_first_name() { return first_Name; }; // get first name
	virtual string get_last_name() { return last_Name; }; // get last name
};

