//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 3 question 1
//This program does mulitple operations on dates
#pragma once
class date
{
	int day;
	int month;
	int year;
public:
	date(int = 1, int = 1, int = 1920); // consturctor
	date(const date&); // copy constructor
	date(date&&); // move constructor
	void set_date(int, int, int); // set date
	date operator++(); // imidate plus 1
	date operator++(int); // plus 1
	date operator+=(const int&); // plus equal
	date operator=(const date&); // placement
	bool operator>(const date&); // bigger than
	bool operator<(const date&); // smaller than
	bool operator==(const date&) const; // operator for comparison
	void print(); // print
};

