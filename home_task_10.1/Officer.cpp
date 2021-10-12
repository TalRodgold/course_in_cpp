//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 10 question 1
//this program holds a database of soldiers

#include "Officer.h"

Officer::Officer(int i, string f, string s, int o, int so) : Soldier(i,f,s,o) //constructor
{
	sociometric = so;
}

void Officer::print() // print
{
	cout << soldier_type() << endl;
	Soldier::print();
	cout << "sociometric score: " << sociometric << endl;;
}

string Officer::soldier_type() // soldier type
{
	return "officer";
}

bool Officer::medal() // worthy of a medal
{
	if (operations > 2 && sociometric >= 92) // if worthy of medal
	{
		return true;
	}
	return false;
}

