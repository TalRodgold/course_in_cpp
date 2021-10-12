//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 3 question 1
//This program does mulitple operations on dates
using namespace std;
#include <iostream>
#include "date.h"

date::date(int d, int m, int y) // consturctor
{
	if (d < 1 || d > 30) // if user input invalid
	{
		cout << "Error day" << endl;
		day = 1; // set day to be 1
	}
	else // if user input valid
	{
		day = d;
	}
	if (m < 1 || m > 12) // if user input invalid
	{
		cout << "Error month" << endl;
		month = 1; // set month to be 1
	}
	else // if user input valid
	{
		month = m;
	}
	if (y < 1920 || y > 2099) // if user input invalid
	{
		cout << "Error year" << endl;
		year = 1920; // set year to be 1920
	}
	else // if user input valid
	{
		year = y;
	}
}

date::date(const date& copy) // copy constructor
{
	day = copy.day; // copy day
	month = copy.month; // copy month
	year = copy.year; // copy year
}

date::date( date&& move) // move contructor
{
	day = move.day; // move day
	month = move.month; // move month
	year = move.year; // move year
}

void date::set_date(int d, int m, int y) // set date
{
	if (d < 1 || d > 30) // if user input invalid
	{
		return; // break
	}
	if (m < 1 || m > 12) // if user input invalid
	{
		return; // break
	}
	if (y < 1920 || y > 2099) // if user input invalid
	{
		return; // break
	}
	// if all input was valid
	day = d; // set day
	month = m; // set month
	year = y; // set year
}

date date::operator++() // imidate plus 1
{
	if (day < 30) // if day is less than 30
	{
		day += 1; // add one to day
		return *this; // return new date
	}
	if (day == 30) // if day is 30
	{
		day = 1; // day equals one
		if (month == 12) // if munth equals 12
		{
			month = 1; // month equals 1
			year += 1; // year plus 1
			if (year > 2099) // if year to big
			{
				day = 1;
				month = 1;
				year = 1920;
				return *this; // return new date
			}
			return *this; // return new date
		}
		month += 1; // grow month by one
		return *this; // return new date
	}
}

date date::operator++(int) // plus 1
{
	date temp = *this;
	if (day < 30) // if day is less than 30
	{
		day += 1; // add one to day
		return temp; // return new date
	}
	if (day == 30) // if day is 30
	{
		day = 1; // day equals one
		if (month == 12) // if munth equals 12
		{
			month = 1; // month equals 1
			year += 1; // year plus 1
			if (year > 2099) // if year to big
			{
				day = 1;
				month = 1;
				year = 1920;
				return temp; // return new date
			}
			return temp; // return new date
		}
		month += 1; // grow month by one
		return temp; // return new date
	}
}

date date::operator+=(const int& plus) // plus equal
{
	date temp = *this; // creat temp 
	if (temp.day + plus < 30) // if less than 30 dayes in total
	{
		temp.day += plus; //add dayes
		*this = temp; // copy temp
		return temp; // return new date
	}
	int days_to_add = (temp.day + plus) % 30; // how many dayes to add
	int months_to_add = (temp.month + plus) / 12; // how many months to add
	temp.day = days_to_add; // add days
	temp.month += months_to_add; // add months
	if (temp.month < 12) // if less than 12 months
	{
		*this = temp; // copy temp
		return temp;  // return new date
	}
	int years_to_add = temp.month / 12; // add years
	temp.month = temp.month % 12; // add months
	temp.year += years_to_add; // add years
	if (temp.year > 2099) // if year to big
	{
		temp.day = 1; // default
		temp.month = 1; // default
		temp.year = 1920; // default
		*this = temp; // copy temp
		return temp; // return new date
	}
	*this = temp; // copy temp
	return temp; // return new date
}

date date::operator=(const date& copy) // placement
{
	day = copy.day; // copy day
	month = copy.month; // copy month
	year = copy.year; // copy year
	return *this; // return cpyied date
}

bool date::operator>(const date& compair) // bigger than
{
	if (year > compair.year) // if years are bigger
	{
		return true; // return true
	}
	if (year == compair.year) // if years are equal
	{
		if (month > compair.month) // if months are bigger
		{
			return true; // return true
		}
		if (month == compair.month) // if months are equal
		{
			if (day > compair.day) // if day is bigger
			{
				return true; // return true
			}
		}
	}
	return false; // if not bigger
}

bool date::operator<(const date& compair) // smaller than
{
	if (year > compair.year)  // if years are bigger
	{
		return false; // return false
	}
	if (year == compair.year) // if years are equal
	{
		if (month > compair.month) // if months are bigger
		{
			return false; // return false
		}
		if (month == compair.month) // if months are equal
		{
			if (day > compair.day) // if day is bigger
			{
				return false; // return false
			}
		}
	}
	return true; // if not bigger return true
}

bool date::operator==(const date& compair) const // operator for comparison
{
	if (day == compair.day && month == compair.month && year == compair.year) // if day month and year are equal
	{
		return true; // return true
	}
	return false; // else return false
}

void date::print() // print
{
	cout << day << "/" << month << "/" << year << endl;
}

