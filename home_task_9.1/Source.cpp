//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 9 question 1
//this program implements a tree

#include <iostream>
#include "SearchTree.h"
using namespace std;

enum { END, ADD, SEARCH, REMOVE, BREADTHSCAN, HEIGHT, SUCCESSOR, DELETEDUP, REFLECT };
int main()
{
	SearchTree<int> T1;
	cout << "enter 10 numbers:\n";
	int x, y, z;
	for (int i = 0; i < 10; i++)
	{
		cin >> x;
		T1.add(x);
	}
	cout << "inorder: ";
	T1.inOrder();
	cout << "\nenter 0-8:\n";
	cin >> x;
	while (x != END)
	{
		switch (x)
		{
		case ADD: cout << "enter a number: ";
			cin >> y;
			T1.add(y);
			cout << "after adding " << y << ": ";
			T1.inOrder();
			cout << endl;
			break;
		case SEARCH: cout << "enter a number: ";
			cin >> y;
			if (T1.search(y))
				cout << "exist" << endl;
			else
				cout << "no exist" << endl;
			break;
		case REMOVE:cout << "enter a number: ";
			cin >> y;
			try
			{
				T1.remove(y);
				cout << "after removing " << y << ": ";
				T1.inOrder();
				cout << endl;
			}
			catch (const char* str)
			{
				cout << str << endl;
			}
			break;
		case BREADTHSCAN: cout << "breadth scan: ";
			T1.breadthScan();
			cout << endl;
			break;
		case HEIGHT:cout << "height of tree: " << T1.height() << endl;
			break;
		case SUCCESSOR:cout << "enter a number: ";
			cin >> y;
			try
			{
				z = T1.successor(y);
				cout << "successor of " << y << " is: " << z << endl;

			}
			catch (const char* str)
			{
				cout << str << endl;
			}
			break;
		case DELETEDUP: cout << "after delete duplicate: ";
			T1.deleteDuplicates();
			T1.inOrder();
			cout << endl;
			break;
		case REFLECT:T1.reflect();
			cout << "reflected tree: ";
			T1.inOrder();
			T1.reflect();
			cout << endl;
			break;
		}
		cout << "enter 0-8:\n";
		cin >> x;
	}
	return 0;
}

//enter 10 numbers:
//0 1 2 3 4 5 6 7 8 9
//inorder : 0 1 2 3 4 5 6 7 8 9
//enter 0 - 8 :
//	7
//	after delete duplicate : 0 1 2 3 4 5 6 7 8 9
//	enter 0 - 8 :
//	8
//	reflected tree : 9 8 7 6 5 4 3 2 1 0
//	enter 0 - 8 :
//	6
//	enter a number : 5
//	successor of 5 is : 6
//	enter 0 - 8 :
//	0
//
//	C : \Users\talro\source\repos\semester_2\Debug\home_task_9.1.exe(process 25216) exited with code 0.
//	To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
//	Press any key to close this window . . .
