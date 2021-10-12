//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 7 question 1
//this program deals with 3 types of shapes
#pragma once
#include <iostream>
using namespace std;
class point
{
protected:
	int x;
	int y;
public:
	point(){} // default
	void setX(int myX); //this function sets x
	void setY(int myY);//this function sets y
	int getX(); //this function returns x
	int getY(); //this function returns y
	float distance(point); // calculates distance beetwen two points
	friend istream& operator>>(istream& is, point& in); // cin
};

