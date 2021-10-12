//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 5 question 1
//this program keeps lets user insert or remove numbers from a List class

#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List lst;
	int choice, val;
	cout << "enter the list values\n";
	cin >> lst;
	cout << "choose 0-2\n";
	cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case 1:cout << "enter a value to insert\n";
			cin >> val;
			lst.insert(val);
			break;
		case 2:cout << "enter a value to remove\n";
			cin >> val;
			try {
				lst.remove(val);
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			break;
		default:cout << "ERROR\n";
		}
		cout << lst << endl;
		cout << "choose 0-2\n";
		cin >> choice;
	}
	return 0;
}

//enter the list values
//3 2 1 1
//choose 0 - 2
//2
//enter a value to remove
//2
//3 1
//choose 0 - 2
//1
//enter a value to insert
//4
//4 3 1
//choose 0 - 2
//1
//enter a value to insert
//2
//4 3 2 1
//choose 0 - 2
//0
//
//C:\Users\talro\source\repos\semester_2\Debug\home_task_5.1.exe(process 8796) exited with code 0.
//To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
//Press any key to close this window . . .

