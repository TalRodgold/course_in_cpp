//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 9 question 2
//this program holds a database of books and allows user to change database

#include <iostream>
#include "SearchTree.h"
#include "Books.h"
using namespace std;

int main()
{
	SearchTree<Books> b; 
	Books w;
	char user_input = 'z';
	while (user_input != 'e')
	{
		cout << "enter a-e:" << endl;
		cin >> user_input;
		switch (user_input)
		{
		case 'a': // add
		{
			cout << "enter a book" << endl;
			cin >> w;
			b.add(w);
			break;
		}
		case 'b': // remove
		{
			cout << "enter a book" << endl;
			cin >> w;
			try {
				b.remove(w); 
			}
			catch (const char* str)
			{
				cout << str << endl;
			}
			break;
		}
		case 'c':  // search
		{
			cout << "enter a book" << endl;
			cin >> w;
			if (b.search(w))  
				cout << "exist" << endl;
			else
				cout << "not exist" << endl;
			break;
		}
		case 'd':  // print
		{
			b.inOrder(); 
			break;
		}
		case 'e': //exit
		{
			break;
		}
			
		default: //error
		{
			cout << "error" << endl;
		}
		}
	}
	return 0;
}

//enter a - e:
//a
//enter a book
//2 b b
//enter a - e :
//	a
//	enter a book
//	5 e e
//	enter a - e :
//	a
//	enter a book
//	1 a a
//	enter a - e :
//	a
//	enter a book
//	4 d d
//	enter a - e :
//	a
//	enter a book
//	7 g g
//	enter a - e :
//	a
//	enter a book
//	3 c c
//	enter a - e :
//	b
//	enter a book
//	5 e e
//	enter a - e :
//	d
//	1 a a 2 b b 3 c c 4 d d 7 g g enter a - e :
//	e
//
//	C : \Users\talro\source\repos\semester_2\Debug\home_task_9.2.exe(process 25264) exited with code 0.
//	To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
//	Press any key to close this window . . .