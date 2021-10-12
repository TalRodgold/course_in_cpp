//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 7 question 1
//this program deals with 3 types of shapes

#include <iostream>
#include "point.h"
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
using namespace std;

int main()
{
	cout << "How many shapes you would like to define?" << endl; // print
	int size; // how many shapes
	cin >> size; // user input
	shape** arr = new shape*[size]; // creat array size of user input
	for (int i = 0; i < size; i++) 
	{
		cout << "Which shape will you choose? Circle - 1, Triangular - 3, Rectangle - 4" << endl; // print
		int choice; // users choice
		cin >> choice; // user input
		switch (choice)
		{
		case(1): // circle
		{
			cout << "Enter radius:" << endl;
			float r; // radius
			cin >> r; 
			if (r <= 0) // if invalid input
			{
				cout << "invalid input" << endl;
				break;
			}
			arr[i] = new circle(r); // creat circle
			break;
		}
		case(3): // triangle
		{
			arr[i] = new triangle(); // creat traingle
			break;
		}
		case(4): // rectangle
		{
			arr[i] = new rectangle(); // creat rectangl
			break;
		}
		default: // invalid input
			i--;
			cout << "invalid input" << endl;
			break;
		}
	}
	for (int i = 0; i < size; i++) // to print
	{
		cout << endl << *arr[i];
		cout << "area is: " << arr[i]->area() << endl;
		if (arr[i]->isSpecial()) // if special
		{
			arr[i]->printSpecial();
		}
	}
	return 0;
}

//How many shapes you would like to define ?
//3
//Which shape will you choose ? Circle - 1, Triangular - 3, Rectangle ö 4
//1
//Enter radius :
//4
//Enter values of 1 points :
//	(0, 0)
//	Which shape will you choose ? Circle - 1, Triangular - 3, Rectangle ö 4
//	2
//	invalid input
//	Which shape will you choose ? Circle - 1, Triangular - 3, Rectangle ö 4
//	4
//	Enter values of 4 points :
//	(0, 0) (1, 0) (1, 1) (0, 1)
//	Which shape will you choose ? Circle - 1, Triangular - 3, Rectangle ö 4
//	3
//	Enter values of 3 points :
//	(0, 0) (1, 0) (1, 1)
//
//	points : (0, 0)
//	area is : 50.24
//	A canonical circle with a radius 4
//
//	points : (0, 0) (1, 0) (1, 1) (0, 1)
//	area is : 1
//	Square with side length 1
//
//	points : (0, 0) (1, 0) (1, 1)
//	area is : 0.5
//
//	C : \Users\talro\source\repos\semester_2\Debug\home_task_7.1.exe(process 12116) exited with code 0.
//	To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
//	Press any key to close this window . . .
