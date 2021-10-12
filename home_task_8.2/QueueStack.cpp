//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 8 question 2
//this program implements a queue using stack
#include "QueueStack.h"

QueueStack::QueueStack(){} // default constructor

void QueueStack::clear() // clear
{
	while (!data.empty()) // as long as data is not empty
	{
		data.pop(); // pop
	}
}

int QueueStack::dequeue() // dequeue
{
	stack<int> temp; // temp stack
	while (!data.empty())  // as long as data is not empty copy it to temp
	{
		temp.push(data.top()); // copy to temp
		data.pop(); // pop
	}
	int wanted = temp.top(); // save wanted number
	temp.pop(); // remove wanted number
	while (!temp.empty()) // return to data
	{
		data.push(temp.top()); // copy to data
		temp.pop(); // pop
	}
	return wanted; // return first number in queue number 
}

void QueueStack::enqueue(int value) // enqueue
{
	data.push(value); // add val to data
}

int QueueStack::front() // return first element in queue
{
	stack<int> temp; // temp stack
	while (!data.empty()) // as long as data is not empty copy it to temp
	{
		temp.push(data.top()); // copy to temp
		data.pop(); // pop
	}
	int wanted = temp.top(); // save wanted number
	while (!temp.empty()) // return to data
	{
		data.push(temp.top()); // copy to data
		temp.pop(); // pop
	}
	return wanted; // return first number in queue number 
}

bool QueueStack::isEmpty() const // is empty
{
	if (data.empty()) // if data is empty
	{
		return true; // true
	}
	return false; // else
}
