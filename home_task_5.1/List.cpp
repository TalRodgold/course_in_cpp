//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 5 question 1
//this program keeps lets user insert or remove numbers from a List class

#include "List.h"
#include <iostream>
using namespace std;

List::Link::Link(int val, Link* nxt) : value(val), next(nxt)
{}

List::Link::Link(const Link& source) : value(source.value), next(source.next)
{}

List::List() : head(NULL)
{
	// no further initialization
}

List::List(const List& l)
{
	Link* src, * trg;
	if (l.head == NULL)
		head = NULL;
	else
	{
		head = new Link((l.head)->value, NULL);
		src = l.head;
		trg = head;
		while (src->next != NULL)
		{
			trg->next = new Link((src->next)->value, NULL);
			src = src->next;
			trg = trg->next;
		}
	}
}

List::~List()
{
	clear();
}

void List::insert(int key) // insert
{
	if (this->isEmpty() || head->value <= key) // if list is empty or key is smallest
	{
		head = new Link(key, head); // insert key
	}
	else
	{
		for (Link* p = head; p != NULL; p = p->next) // check every link in list
		{
			if ((p->value >= key) && (p->next == NULL || p->next->value <= key)) // if correct place for key
			{
				p->next = new Link(key, p->next); // insert key
				break;
			}
		}
	}
}

void List::remove(int key) // remove
{
	if (this->isEmpty()) // if list is empty
	{
		throw "value not found\n"; // throw exprtion
	}
	if (key == head->value) // if key to remove is first in list
	{
		head = head->next; // remove key
		return; // break
	}
	for (Link* p = head; p != NULL; p = p->next) // check every link in list
	{
		if (key == p->next->value) // if key found
		{
			p->next = p->next->next; // remove key
			return; // break
		}
	}
	throw "value not found\n"; // if key not found
}

void List::clear()
{
	// empty all elements from the List
	Link* theNext;
	for (Link* p = head; p != NULL; p = theNext)
	{
		// delete the element pointed to by p
		theNext = p->next;
		p->next = NULL;
		delete p;
	}
	// mark that the List contains no elements
	head = NULL;
}

List List::operator=(const List& l) // equal
{
	head->value = l.head->value;
	return *this;
}

bool List::isEmpty() const
{
	// test to see if the List is empty
	// List is empty if the pointer to the head
	// Link is null
	return head == NULL;
}

void List::add(int val)
{
	//Add a new value to the front of a Linked List
	if (this->isEmpty())
	{
		head = new Link(val, head);
		head->next = NULL;
	}
	else
		head->next = new Link(val, NULL);
	if (head == NULL)
		throw "failed in memory allocation";
}

int List::firstElement() const
{
	// return first value in List
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
}

bool  List::search(const int& val) const
{
	// loop to test each element
	for (Link* p = head; p != NULL; p = p->next)
		if (val == p->value)
			return true;
	// not found
	return false;
}


void List::removeFirst()
{
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node
	Link* p = head;
	// reassign the first node
	head = p->next;
	p->next = NULL;
	// recover memory used by the first element
	delete p;
}

istream& operator>>(istream& is, List& in) // cin
{
	int val, temp; // val for value of user input
	is >> val; // read user input
	in.add(val); // add user input
	is >> val; // read user input
	if (val < in.firstElement()) // if user input is smaller than first element
	{
		in.add(val); // add user input
		temp = val; // hold val in temp
		is >> val; // read new input from user
		while (val < temp) // while value is smaller than last value
		{
			in.insert(val); // insert new value
			temp = val; // hold val in temp
			is >> val; // read new input from user
		}
	}
	return is;
}

ostream& operator<<(ostream& os, const List& in) // cout
{
	for (List :: Link* p = in.head; p != NULL; p = p->next ) // for every link in list
	{
		os << p->value << ' '; // print
	}
	return os;
}