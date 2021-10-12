//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 3 question 1
//This program does mulitple operations on dates
using namespace std;
#include <iostream>
#include "date.h"

int main()
{
	enum list { update = 1, imidate_plus_plus, plus_plus, plus_equal, bigger_than, smaller_than, is_equal}; // list of actions
	cout << "Enter a date" << endl;
	int choice = 0; // users choice
	int d, m, y; // day, month, year
	char erelevent; // erelevent characters
	cin >> d >> erelevent >> m >> erelevent >> y; // read user input
	date user_input(d, m, y); // creat date class from user input
	user_input.print(); // print
	cout << "Enter an action code:" << endl;
	cin >> choice; // read users choice
	while (choice != -1) // while user choice is not -1
	{
		switch (choice)
		{
		case update: 
		{
			cout << "Enter a date" << endl;
			cin >> d >> erelevent >> m >> erelevent >> y; // read user input
			user_input.set_date(d, m, y); // set new input
			user_input.print(); // print
			break;
		}
		case imidate_plus_plus:
		{
			++user_input; // grow by 1
			user_input.print(); // print
			break;
		}
		case plus_plus:
		{
			user_input++.print(); // grow by 1 and print
			break; 
		}
		case plus_equal:
		{
			int num; // number for user input
			cout << "Enter # days" << endl;
			cin >> num; // read user input
			user_input += num; // add num to date
			user_input.print(); // print
			break;
		}
		case bigger_than:
		{
			cout << "Enter a date" << endl;
			cin >> d >> erelevent >> m >> erelevent >> y; // read user input
			date new_date(d, m, y); // creat new date class
			if (user_input > new_date) //if bigger
			{
				cout << ">: true" << endl;
			}
			else // if smaller
			{
				cout << ">: false" << endl;
			}
			break;
		}
		case smaller_than:
		{
			cout << "Enter a date" << endl;
			cin >> d >> erelevent >> m >> erelevent >> y; // read user input
			date new_date(d, m, y); // creat new date class
			if (user_input < new_date) // if smaller
			{
				cout << "<: true" << endl;
			}
			else // if bigger
			{
				cout << "<: false" << endl;
			}
			break;
		}
		case is_equal:
		{
			cout << "Enter a date" << endl;
			cin >> d >> erelevent >> m >> erelevent >> y; // read user input
			date new_date(d, m, y); // creat new date class
			if (user_input == new_date) // if equal
			{
				cout << "==: true" << endl;
			}
			else // if not equal
			{
				cout << "==: false" << endl;
			}
			break;
		}
		}
		cout << "Enter an action code:" << endl;
		cin >> choice; // read users choice
	}
	return 0;
}

//Enter a date
//- 5 / 1 / 2012
//Error day
//01 / 01 / 2012
//What do you want to do
//1
//Enter a date
//5 / 7 / 2010
//05 / 07 / 2010
//What do you want to do
//2
//06 / 07 / 2010
//What do you want to do
//3
//06 / 07 / 2010
//What do you want to do
//4
//Enter # days
//7
//14 / 07 / 2010
//What do you want to do
//5
//Enter a date
//14 / 7 / 2010
//false
//What do you want to do
//7
//Enter a date
//14 / 7 / 2010
//true
//What do you want to do
//- 1
//
//C:\Users\talro\source\repos\semester_2\Debug\home_task_3.2.exe(process 8440) exited with code 0.
//To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
//Press any key to close this window . . .