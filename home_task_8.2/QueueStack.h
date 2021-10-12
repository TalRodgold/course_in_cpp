//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 8 question 2
//this program implements a queue using stack
#pragma once
#include <iostream>
#include "Queue.h"
#include <stack>
using namespace std;

class QueueStack : public Queue
{
protected:
	stack<int> data; // stack that holds the data
	
public:
	QueueStack(); // default constructor
	void clear() override; // clear
	int dequeue() override; // dequeue
	void enqueue(int value) override; // enqueue
	int front() override; // return first element in queue
	bool isEmpty() const override; // is empty
};


