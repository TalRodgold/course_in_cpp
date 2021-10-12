//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 6 question 2
//this program maintains a round list

#include <iostream>
using namespace std;
class List
{
protected:
	class Link
	{
	public:
		// constructor
		Link(int linkValue, Link* nextPtr);
		Link(const Link&);
		// data areas
		int value;
		Link* next;
	};	//end of class Link
public:
	// constructors
	List();
	List(const List&);
	~List();

	// operations
	void add(int value); // add
	int firstElement() const; // first element
	bool search(const int& value) const; // search
	bool isEmpty() const; // is empty
	void removeFirst(); // remove first
	void clear(); // clear
	void insert(int); // insert
	void remove(int); // remove
	List& operator=(const List&); // equal
	friend ostream& operator<<(ostream& os, const List& in); // cout
	friend istream& operator>>(istream& is, List& in); // cin
protected:
	// data field
	Link* head;
};


