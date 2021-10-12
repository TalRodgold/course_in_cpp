//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 6 question 2
//this program maintains a round list

#include "RoundList.h"
#include <iostream>
using namespace std;

void RoundList::addToEnd(int val) // add to end
{
	if (isEmpty()) // if first element
	{
		head = new Link(val, NULL); // add to head
		return; // break
	}
	Link* p = head; // pointer
	while (p->next != NULL) //find end
		p = p->next;
	p->next = new Link(val, p); // insert val
	p->next->next = NULL; // ad  null
}

int RoundList::search(int n) // search
{
	if (isEmpty()) // if empty
	{
		return -1;
	}
	int counter = 0; // counter
	Link* p = head; // pointer
	while (p != NULL) // find length of list
	{
		p = p->next; // next to pointer
		counter++; // grow counter by 1
	}	
	int location = (n % counter); // find location of n
	p = head; //reset p
	for (int i = 0; i < location; i++) // arraive to wanted location
	{
		p = p->next;
	}
	return p->value; // return value
}
