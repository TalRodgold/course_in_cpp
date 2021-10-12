//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 2 question 1
//This program recives 2 polygons from the user and there corrdinants, the program returns if the perimitar of 
// the polygons are similar or not
#include <iostream>
#include "point.h"
#include "polygon.h"
#include<cmath>
using namespace std;
polygon user_input(); //this function reads user input and return a polygon
int main()
{
	polygon a = user_input(); // read user input
	polygon b = user_input(); // read user input
	if (a.similar(b)) // if a and b are similar
	{
		cout << "equal.perimeter: " << round(a.perimter()) << endl;
	}
	else // if a and b are diffrent
	{
		cout << "perimeter:" << round(a.perimter()) << endl;
		cout << "perimeter:" << round(b.perimter()) << endl;
	}
	return 0;
}

polygon user_input() //this function reads user input and return a polygon
{
	point point; // temp point
	int num_of_sides = 0; // number of sides
	int x = 0; // x
	int y = 0; // y
	char irrelevant; // irrelevant chars from user input
	cout << "enter number of sides:" << endl;
	cin >> num_of_sides; // read user input for number of sides
	polygon temp(num_of_sides); // creat a polygon in size of user input
	cout << "enter the point values:" << endl;
	for (int i = 0; i < num_of_sides; i++) // for number of points/sides
	{
		cin >> irrelevant >> x >> irrelevant >> y >> irrelevant; // read user input
		point.setX(x); // add x to point
		point.setY(y); // add y to point
		temp.add_point(i, point); // add point
	}
	return temp; // return polygon
}


//enter number of sides :
//4
//in constructor
//enter the point values :
//(0, 0) (0, 2) (2, 2) (2, 0)
//in copy - constructor
//in destructor
//enter number of sides :
//3
//in constructor
//enter the point values :
//(1, 1) (2, 0) (3, 1)
//in copy - constructor
//in destructor
//in copy - constructor
//in destructor
//perimeter : 8
//perimeter : 5
//in destructor
//in destructor
//
//C : \Users\talro\source\repos\semester_2\Debug\home_task_2.1.exe(process 19476) exited with code 0.
//To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
//Press any key to close this window . . .