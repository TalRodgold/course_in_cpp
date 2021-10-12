//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 7 question 1
//this program deals with 3 types of shapes
#include "shape.h"
#include <iostream>
using namespace std;
#pragma once

class circle : public shape
{
protected:
	float radius; // radius of circle
public:
	circle(float); // constractor
	const float area() override; // calculate area
	const bool isSpecial() override; // check if special
	void printSpecial() override; // print special
};

