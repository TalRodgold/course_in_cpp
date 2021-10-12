//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 10 question 1
//this program holds a database of soldiers

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Soldier
{
public:
	int id; // id number
	string first_Name; // first name
	string last_Name; // last name
	int operations; //number of operations

	Soldier(int, string, string, int); // constructor
	virtual ~Soldier() {}; // virtual ditractor
	virtual bool medal() = 0; // worthy of a medal
	virtual void print(); // print
	virtual int get_score()const { return 0; }; // get score
	virtual string soldier_type() { return ""; }; // soldier type
	virtual string get_first_name() { return ""; }; // get first name
	virtual string get_last_name() { return ""; }; // get last name
	virtual bool is_combat() { return false; }; // is a combat soldier
};
