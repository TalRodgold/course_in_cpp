//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 10 question 1
//this program holds a database of soldiers

#include "Commander.h"

Commander::Commander(int i, string f, string s, int o, bool c) : Private(i, f, s, o) // constructor
{
	combat = c;
}

void Commander::print() // print
{
	cout << soldier_type() << endl;
	Soldier::print();
	cout << "grades: ";
	for (int i = 0; i < Soldier::operations; i++)
		cout << Private::score[i] << " ";
	cout << endl << "combat: ";
	if (combat)
		cout << "yes";
	else
		cout << "no";
	cout << endl;
}

string Commander::soldier_type() //soldier type
{
	return "commander";
}

bool Commander::medal() // worthy of a medal
{
	float avrege = 0;
	for (int i = 0; i < operations; i++)
	{
		avrege += score[i];
	}
	avrege = avrege / operations;
	if (operations >= 7 && avrege > 90 && combat)
	{
		return true;
	}
	return false;
}
