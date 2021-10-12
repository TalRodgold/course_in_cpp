//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 7 question 1
//this program deals with 3 types of shapes
#include "rectangle.h"
rectangle::rectangle():shape(4) // default constructor
{

}

const float rectangle::area() // calculate area
{
	float a, b;
	a = arr[0].distance(arr[1]); // distance
	b = arr[1].distance(arr[2]); // distance
	return (a * b); // return area
}

const bool rectangle::isSpecial() // check if special
{
	float a, b, c, d; // 4 points
	a = arr[0].distance(arr[1]); // distance
	b = arr[1].distance(arr[2]); // distance
	c = arr[2].distance(arr[3]); // distance
	d = arr[3].distance(arr[0]); // distance
	if (a == b && b == c && c == d) // if squear
	{
		return true;
	}
	return false;
}

void rectangle::printSpecial() // print special
{
	cout << "Square with side length " << arr[0].distance(arr[1]) << endl; // print
}
