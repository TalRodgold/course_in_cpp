//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 7 question 1
//this program deals with 3 types of shapes
#pragma once
#include "shape.h"
class triangle : public shape
{
public:
	triangle(); // default constractor
	const float area() override; // calculate area
	const bool isSpecial() override; // check if special
	void printSpecial() override; // print special
	
};

