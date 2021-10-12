//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 6 question 2
//this program maintains a round list

#pragma once
#include "List.h"
class RoundList : public List
{

public:
	void addToEnd(int val); // add to end
	int search(int n); // search

};

