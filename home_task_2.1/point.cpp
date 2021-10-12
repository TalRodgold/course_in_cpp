//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 2 question 1
//This program recives 2 polygons from the user and there corrdinants, the program returns if the perimitar of 
// the polygons are similar or not
#include "point.h"
#include <cmath>
void point::setX(int myX) //this function sets x
{
	x = myX;
}
void  point::setY(int myY) //this function sets y
{
	y = myY;
}
int  point::getX() //this function returns x
{
	return x;
}
int  point::getY() //this function returns y
{
	return y;
}
float point:: distance(point a) // this function calculates distance between two points
{
	int x1 = a.getX(); // get x from a
	int y1 = a.getY(); // get y from a
	int x2 = x;
	int y2 = y;
	float distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)); // caluclate distance
	return distance;// return distance from a to b
}