//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 4 question 1
//this program keeps track of 10 bank accounts, and allows sevrel actions in the account
#include "Clock.h"
#include <iostream>
#include <iomanip>
using namespace std;

Clock::Clock() // default consturctor
{
	hour = 0;
	minute = 0;
	second = 0;
}

Clock::Clock(int h, int m, int s) // consturctor
{
	check_valid_input(h, 'h'); // set hour
	check_valid_input(m, 'm'); // set minute
	check_valid_input(s, 's'); // set second
}

Clock::Clock(const Clock& copy) // copy constructor
{
	hour = copy.hour; // copy hour
	minute = copy.minute; // copy minute
	second = copy.second; // copy second
}

Clock Clock::operator=(const Clock& copy)
{
	hour = copy.hour; // copy hour
	minute = copy.minute; // copy minute
	second = copy.second; // copy second
	return *this; // return copied clock
}

Clock Clock::operator+=(int s) // add and equal
{
	int time = second + s;
	while( time > 59) // as long as we have more than 59 seconds
	{
		time -= 60; // take off 60 seconds
		minute += 1; // add it to minute
		if (minute > 59) // if we have 59 minutes
		{
			hour += 1;
			minute = 0;
		}
		if (hour == 24) // if we passed 24 houres
		{
			hour = 0;
		}
	}
	second = time;
	return *this; // return new time
}

int Clock::get_hour() // get hour
{
	return hour;
}

int Clock::get_minute() // get minute
{
	return minute;
}

int Clock::get_second() // get second
{
	return second;
}

void Clock::set_hour(int h) // set hour
{
	check_valid_input(h, 'h');
}

void Clock::set_minute(int m) // set minute
{
	check_valid_input(m, 'm');
}

void Clock::set_second(int s) // set second
{
	check_valid_input(s, 's');
}

void Clock::check_valid_input(int n, char t) // check valid input
{
	try //check valid input
	{
		if (t == 'h')
		{
			if (n > 23) // for hour
			{
				throw 1;
			}
			if (n < 0) // for hour
			{
				throw 2;
			}
			hour = n; // if valid
		}
		else if (t == 'm')
		{
			if (n > 59) // for minutes
			{
				throw 3;
			}
			if (n < 0) // for minutes
			{
				throw 4;
			}
			minute = n; // if valid
		}
		else if (t == 's')
		{
			if (n > 59) // for seconds
			{
				throw 5;
			}
			if (n < 0) // for seconds
			{
				throw 6;
			}
			second = n;	 // if valid
		}
	}
	catch (int a) // catch for invalid user input
	{
		// set default value
		hour = 0;
		minute = 0;
		second = 0;
		switch (a)
		{
		case(1): // for hour
			cout << "Invalid time - more than 24 hours." << endl;
			break;
		case(2): // for hour
			cout << "Invalid time - negative number of hours." << endl;
			break;
		case(3): // for minutes
			cout << "Invalid time - more than 60 minutes." << endl;
			break;
		case(4): // for minutes
			cout << "Invalid time - negative number of minutes." << endl;
			break;
		case(5): // for seconds
			cout << "Invalid time - more than 60 seconds." << endl;
			break;
		case(6): // for seconds
			cout << "Invalid time - negative number of seconds." << endl;
			break;
		}
	}
}

ostream& operator<<(ostream& os, const Clock& in) // cout
{
	os << setw(2) << setfill('0') << in.hour << ':'; // print hour
	os << setw(2) << setfill('0') << in.minute << ':'; // print  minute
	os << setw(2) << setfill('0') << in.second << ':'; // print second
	return os;
}

istream& operator>>(istream& is, Clock& in) // cin
{
	char erelevent; // for ':' character
	int h, m, s; // h for hour, m for minute, s for second
	is >> h >> erelevent >> m >> erelevent >> s; // read user input
	in.set_hour(h); // set hour
	in.set_minute(m); // set minute
	in.set_second(s); // set second
	return is; // return user input
}
