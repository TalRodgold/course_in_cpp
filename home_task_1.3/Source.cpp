//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 1 question 3
//This program calculates area and perimeter of circles given by user input. 
//the program also recives from user a point and the program checks if the point is in the circle or not
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "circle.h"
#include "point.h"
using namespace std;
int count(Circle circle, int x, int y); // this function checks if point is in circle. if yes returns 1 else returns 0
void user_input(Circle A, Circle B, Circle C); // this function reads from user pointes and then prints how many points are in each circle

int main()
{
	cout << "enter the center point and radius of 3 circles:" << endl;
	Circle a, b, c; //3 circles
	char erlevent; // erelevent caracters
	int x, y, r; // point x, point y, radius r
	cin >> erlevent >> x >> erlevent >> y >> erlevent >> r; // read user input
	a.setCenter(x, y); //set center
	a.setRadius(r); // set radius
	cin >> erlevent >> x >> erlevent >> y >> erlevent >> r; // read user input
	b.setCenter(x,y); //set center
	b.setRadius(r); // set radius
	cin >> erlevent >> x >> erlevent >> y >> erlevent >> r; // read user input
	c.setCenter(x, y); //set center
	c.setRadius(r); // set radius
	cout << "perimeter:     A:" << a.perimeter() << "     B:" << b.perimeter() << "     C:" << c.perimeter() << endl;
	cout << "area:     A:" << a.area() << "     B:" << b.area() << "     C:" << c.area() << endl;
	cout << "enter points until (0,0):" << endl;
	user_input(a, b, c); // check how many points are in circle
	return 0;
}

void user_input(Circle A, Circle B, Circle C) // this function reads from user pointes and then prints how many points are in each circle 
{
	int counter_a = 0; // counter for how many points are in circle a
	int counter_b = 0; // counter for how many points are in circle b
	int counter_c = 0; // counter for how many points are in circle c
	char erlevent; // erelevent caracters
	int x, y; // point x, point y
	cin >> erlevent >> x >> erlevent >> y >> erlevent; // read user input
	while (x || y) // while user input is not (0,0)
	{
		counter_a += count(A, x, y); // check if point in circle a
		counter_b += count(B, x, y); // check if point in circle b
		counter_c += count(C, x, y); // check if point in circle c
		cin >> erlevent >> x >> erlevent >> y >> erlevent; // read user input
	}
	cout << "num of points in circle:     A:" << counter_a << "     B:" << counter_b << "     C:" << counter_c << endl;
}

int count(Circle circle, int x, int y) // this function checks if point is in circle. if yes returns 1 else returns 0
{
	Point p; // point
	p.setX(x); // set x
	p.setY(y); // set y
	if (circle.onInOut(p) <= 0) // check if point is in circle
	{
		return 1; // if in circle
	}
	return 0; // else
}

//enter the center pointand radius of 3 circles:
//(0, 0)3
//(1, 1)2
//(5, 5)2
//perimeter : A : 18.84     B : 12.56     C : 12.56
//area : A : 28.26     B : 12.56     C : 12.56
//enter points until(0, 0) :
//	(0, 1)
//	(1, 0)
//	(0, 4)
//	(0, 0)
//	num of points in circle : A:2     B : 2     C : 0
//
//	C : \Users\talro\source\repos\semester_2\Debug\home_task_1.3.exe(process 24768) exited with code 0.
//	To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
//	Press any key to close this window . . .