//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 2 question 1
//This program recives 2 polygons from the user and there corrdinants, the program returns if the perimitar of 
// the polygons are similar or not
#pragma once
class point
{
private:
	int x;
	int y;
public:
	void setX(int myX); //this function sets x
	void setY(int myY); //this function sets y
	int getX(); //this function returns x
	int getY(); //this function returns y
	float distance(point); // this function calculates distance between two points

};

