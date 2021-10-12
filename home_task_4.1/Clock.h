//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 4 question 1
//this program keeps track of 10 bank accounts, and allows sevrel actions in the account
#pragma once
using namespace std;
#include <iostream>
class Clock
{
	int hour;
	int minute;
	int second;

public:
	Clock(); // default consturctor
	Clock(int = 0, int = 0, int = 0); // consturctor
	Clock(const Clock&); // copy constructor
	Clock operator=(const Clock&); // placement
	Clock operator+=(int); // add and equal
	int get_hour(); // get hour
	int get_minute(); // get minute
	int get_second(); // get second
	void set_hour(int); // set hour
	void set_minute(int); // set minute
	void set_second(int); // set second
	void check_valid_input(int, char); // check valid input
	friend ostream& operator<<(ostream& os, const Clock& in); // cout
	friend istream& operator>>(istream& is, Clock& in); // cin
};

