//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 7 question 1
//this program deals with 3 types of shapes
#include "point.h"
#include <iostream>
#include <cmath>
using namespace std;

void point::setX(int myX) //this function sets x
{
	x = myX; 
}
void point::setY(int myY) //this function sets y
{
	y = myY; 
}
int point::getX() //this function returns x
{
	return x;
}
int point::getY() //this function returns y
{
	return y;
}

float point::distance(point a) // this function calculates distance between two points
{
	int x1 = a.getX(); // get x from a
	int y1 = a.getY(); // get y from a
	int x2 = x;
	int y2 = y;
	float distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)); // caluclate distance
	return distance;// return distance from a to b
}

istream& operator>>(istream& is, point& in) // cin
{
	char erelevent; // for: '(' and ',' and ')'
	int X, Y;
	is >> erelevent >> X >> erelevent >> Y >> erelevent; // user input
	in.setX(X);
	in.setY(Y);
	return is;
}
