//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 9 question 2
//this program holds a database of books and allows user to change database
#pragma once
#include <iostream>
using namespace std;
template<class T>
class Queue
{
public:
	virtual ~Queue() {}; //virtual distructor
	virtual void clear() = 0; //virtual clear func
	virtual void enqueue(T value) = 0; //virtual enqueue func
	virtual T dequeue() = 0; //virtual dequeue func
	virtual T front() = 0;  //virtual front func
	virtual bool isEmpty() = 0; //virtual empty func
};

