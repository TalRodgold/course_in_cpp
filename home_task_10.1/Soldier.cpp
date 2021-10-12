//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 10 question 1
//this program holds a database of soldiers

#include "Soldier.h"

Soldier::Soldier(int i, string f, string l, int o) // constructor
{
	id = i;
	first_Name = f;
	last_Name = l;
	operations = o;
}

void Soldier::print() // print
{
	cout << "ID: " << id << endl;
	cout << "first name: " << first_Name << endl;
	cout << "last name: " << last_Name << endl;
	cout << "num operations: " << operations << endl;
}