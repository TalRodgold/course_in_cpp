//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 1 question 3
//This program calculates area and perimeter of circles given by user input. 
//the program also recives from user a point and the program checks if the point is in the circle or not
#include <iostream>
#include "circle.h"
#include <cmath>
using namespace std;
float const PI = 3.14;

void Circle::setCenter(int x, int y)// this function sets center of circle
{
	center.setX(x);
	center.setY(y);
}
void Circle::setRadius(int myRadius) // this function sets radius
{
	radius = myRadius;
}
Point Circle::getCenter() // this function return center of circle
{
	center.getX();
	center.getY();
	return center;
}
int Circle::getRadius() // this function return radius of circle
{
	return radius;
}
float Circle::area() // this function returns the erae of the circle
{
	return PI * pow(radius, 2);
}
float Circle::perimeter() // this function returns the perimeter of the circle
{
	return 2 * PI * radius;
}
int Circle::onInOut(Point p) // this function checks if a dot is on, in or outside the circle
{
	float distance = sqrt(pow((p.getX() - center.getX()), 2) + pow((p.getY() - center.getY()), 2)); // equation for distance between 2 pointes
	if (distance == radius) // if point is on the circle
	{
		return 0;
	}
	if (distance < radius) // if point is in circle
	{
		return -1;
	}
	return 1; // if point is outside circle
}
