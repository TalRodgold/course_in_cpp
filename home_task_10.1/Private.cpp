//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 10 question 1
//this program holds a database of soldiers

#include "Private.h"

Private::Private(int i, string f, string l, int o):Soldier(i,f,l,o) // constructor
{
	score = new int[o];
}

void Private::print() // print
{
	cout << soldier_type() << endl;
	Soldier::print();
	cout << "grades: ";
	for (int i = 0; i < Soldier::operations; i++)
		cout << score[i] << " ";
	cout << endl;
}

string Private::soldier_type() // soldier type
{
	return "private";
}

bool Private::medal() // worthy of a medal
{
	float avrege = 0; // avrege
	for (int i = 0; i < operations; i++) // add all operations
	{
		avrege += score[i];
	}
	avrege = avrege / operations; // calculate avrege
	if (operations >= 10 && avrege > 95) // check if worthy for medal
	{
		return true;
	}
	return false;
}
