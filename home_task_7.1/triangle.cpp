//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 7 question 1
//this program deals with 3 types of shapes
#include "triangle.h"
#include <cmath>
triangle::triangle():shape(3) // default constractor
{

}

const float triangle::area() // calculate area
{
	float a, b, c; // three points
	a = arr[0].distance(arr[1]); // distance 
	b = arr[1].distance(arr[2]); // distance 
	c = arr[2].distance(arr[0]); // distance 
	float alpha = acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b)); // calculate alpha
	float s = ((a * b * sin(alpha)) / 2); // calculate area
	return s; // return area
}

const bool triangle::isSpecial() // check if special
{
	float a, b, c; // three points
	a = arr[0].distance(arr[1]); // distance
	b = arr[1].distance(arr[2]); // distance
	c = arr[2].distance(arr[0]); // distance
	if (a == b == c) // if three points are equal
	{
		return true;
	}
	return false;
}

void triangle::printSpecial() // print special
{
	cout << "An isosceles triangle with a side length " << arr[0].distance(arr[1]) << endl; // print
}

