//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 7 question 1
//this program deals with 3 types of shapes
#include "circle.h"
#include "shape.h"
#include <iostream>
#include <cmath>
using namespace std;
circle::circle(float r):shape(1) // constractor
{
	radius = r; // set radius
}

const float circle::area() // calculate area
{
	return (3.14 * pow(radius, 2)); // return area
}

const bool circle::isSpecial() // check if special
{
	if (arr[0].getX() == 0 && arr[0].getY() == 0) // if x and y equal 0
	{
		return true;
	}
	return false;
}

void circle::printSpecial() // print special
{
	cout << "A canonical circle with a radius " << radius << endl; // print
}
