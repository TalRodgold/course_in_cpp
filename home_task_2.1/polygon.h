//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 2 question 1
//This program recives 2 polygons from the user and there corrdinants, the program returns if the perimitar of 
// the polygons are similar or not
#pragma once
#include "point.h"
class polygon
{
	point* pointer; // array of points
	int vertex; // number of points in polygon
public:
	polygon(); // default
	polygon(int); // constructor for vertex
	polygon(const polygon&); // constructor for array of points
	~polygon(); // destructor to deletes array of points
	point* get_pointer(); // get pointer
	int get_vertex(); // get vertex
	void add_point(int, point); // func to add point
	float perimter(); // this function caluclates the perimiter of the polygon
	bool similar(polygon); // this function checks if 2 polygons are similar
};

