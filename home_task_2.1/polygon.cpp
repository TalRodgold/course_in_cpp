//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 2 question 1
//This program recives 2 polygons from the user and there corrdinants, the program returns if the perimitar of 
// the polygons are similar or not
#include "polygon.h"
#include "point.h"
#include <iostream>
using namespace std;

polygon::polygon(){} // default
polygon::polygon(int num) // constructor for vertex
{
	if (num < 0) // if user input invalid
	{
		cout << "ERROR" << endl;
	}
	else // if user input valid
	{
		pointer = new point [num]; // define pointer
		vertex = num; // define vertex
	}
	cout << "in constructor" << endl;
}
polygon::polygon(const polygon& poly) // constructor for array of points
{
	vertex = poly.vertex; //copy vertex
	pointer = new point[vertex]; // creat new array
	for (int i = 0; i < vertex; i++) // copy array
	{
		pointer[i] = poly.pointer[i];
	}
	cout << "in copy-constructor" << endl;
}
polygon::~polygon() // destructor to deletes array of points
{
	if (vertex) // if array exisists
	{
		delete[] pointer; // delete
	}
	cout << "in destructor" << endl;
}
point* polygon::get_pointer() // get pointer
{
	return pointer;
}
int polygon::get_vertex() // get vertex
{
	return vertex;
}
void polygon :: add_point(int index, point points) // func to add point
{
	pointer[index] = points; // add point in index
}
float polygon::perimter() // this function caluclates the perimiter of the polygon
{
	float total = 0; // total
	for (int i = 0; i < vertex; i++) // for size of vetex
	{
		if (i == vertex - 1) // if last number in array
		{
			total += pointer[i].distance(pointer[0]); // distance between first and last point
		}
		else
		{
			total += pointer[i].distance(pointer[i + 1]); // distance between two points
		}
	}
	return total; // return total
}

bool polygon::similar(polygon a) // this function checks if 2 polygons are similar
{
	bool flag = false; // flag to check if similar or not
	point* pointer_a = a.get_pointer(); // pointer
	if (a.vertex != vertex) // if vertex not same
	{
		return false; // return false
	}
	for (int i = 0; i < vertex; i++) // for every dot in array
	{
		for (int j = 0; j < vertex; j++)
		{
			if (pointer[i].getX() == pointer_a[j].getX() && pointer[i].getY() == pointer_a[j].getY()) // if points are similair
			{
				flag = true; // flag will become true
			}
		}
		if (!flag) // if points are not similair
		{
			return false; //return false
		}
		flag = false; // reset flag
	}
	return true; // if similair return true
}
