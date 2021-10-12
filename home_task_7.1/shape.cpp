//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 7 question 1
//this program deals with 3 types of shapes\

#include "shape.h"
#include <iostream>
#include <cmath>
using namespace std;

shape::shape(int n) // constructor
{
	num_of_points = n; // set num of points
	point* a = new point[n]; // creat array
	cout << "Enter values of " << n << " points:" << endl;
	for (int i = 0; i < n; i++) // user input
	{
		cin >> a[i];
	}
	arr = a; // set arr
}

shape::shape(const shape& copy) // copy constructor
{
	if (arr != nullptr)	 // if empty
	{
		delete arr;
	}
	num_of_points = copy.num_of_points; // copy num of points
	point* a = new point[copy.num_of_points]; // new arr
	for (int i = 0; i < num_of_points; i++) // copy
	{
		a[i] = copy.arr[i];
	}
	arr = a; // set arr
}

shape::shape(shape&& move) // move constructor
{
	if (arr != nullptr)  // if empty
	{
		delete arr;
	}
	num_of_points = move.num_of_points; // move num of points
	arr = move.arr; // move arr
}


shape::~shape() // distractor
{
	delete arr;
}


ostream& operator<<(ostream& os, const shape& in) // cout
{
	os << "points: ";
	for (int i = 0; i < in.num_of_points; i++) // for evrey point in array
	{
		os << "(" << in.arr[i].getX() << "," << in.arr[i].getY() << ") ";
	}
	cout << endl;
	return os;
}
