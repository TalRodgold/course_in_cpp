//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 2 question 2
//This program does mulitple functions on vectors
#include <iostream>
using namespace std;
#include "vector.h"

enum options
{
	stop, assignment, isEqual, mult, add, clear, delLast, at, insert
};
int main()
{
	vector  v1(10), v2(10), v3;
	for (int i = 1; i <= 4; i++)
	{
		v1.insert(i);
		v2.insert(i + 4);
	}
	int choice, val, index;
	cout << "enter your choice 0-8:\n";
	cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case assignment: v3.assign(v1);
			break;
		case isEqual:	if (v1.is_equal(v2)) cout << "v1==v2\n"; else cout << "v1!=v2\n";
			break;
		case mult:		cout << "v1*v2=" << v1.strcatcat(v2) << endl;
			break;
		case add:		v3.assign(v1.strnewcat(v2));
			break;
		case clear:		v1.clear();
			break;
		case delLast:	       v2.del_last();
			break;
		case at:		cout << "enter index:" << endl; cin >> index; cout << "enter value:" << endl; cin >> val; v3.at(index) = val;
			break;
		case insert:	cout << "enter value:" << endl; cin >> val; v3.insert(val);
			break;
		default: cout << "ERROR";
		}
		v1.print();		v2.print();		v3.print();
		cout << "enter your choice 0-8:\n";
		cin >> choice;
	}
	return 0;
}

//enter your choice 0 - 8:
//4
//capacity : 10 size : 4 values : 1 2 3 4
//capacity : 10 size : 4 values : 5 6 7 8
//capacity : 20 size : 8 values : 1 2 3 4 5 6 7 8
//enter your choice 0 - 8 :
//	0
//
//	C : \Users\talro\source\repos\semester_2\Debug\home_task_2.2.exe(process 8976) exited with code 0.
//	To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
//	Press any key to close this window . . .
