//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 7 question 1
//this program deals with 3 types of shapes
#pragma once
#include <iostream>
#include "point.h"
using namespace std;
class shape : public point
{
protected:
	int num_of_points; // number of points
	point* arr; // array with all points
public:
	shape(){} // default
	shape(int); // constructor
	shape(const shape&); // copy constructor
	shape(shape&&); // move constructor
	virtual ~shape(); // distractor
	friend ostream& operator<<(ostream& os, const shape& in); // cout
	virtual const float area() = 0; // calculate area
	virtual const bool isSpecial() = 0; // check if special
	virtual void printSpecial() = 0; // print special
};

