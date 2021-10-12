//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 1 question 3
//This program calculates area and perimeter of circles given by user input. 
//the program also recives from user a point and the program checks if the point is in the circle or not
#pragma once
#include "point.h"
class Circle
{
private:
	Point center;
	int radius;
public:
	void setCenter(int x, int y); // this function sets center of circle
	void setRadius(int myRadius); // this function sets radius
	Point getCenter(); // this function return center of circle
	int getRadius(); // this function return radius of circle
	float area(); // this function returns the erae of the circle
	float perimeter(); // this function returns the perimeter of the circle
	int onInOut(Point p); // this function checks if a dot is on, in or outside the circle
};

