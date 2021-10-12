#pragma once
using namespace std;
#include "Queue.h"
#include <stack>
#include <iostream>
class Queue
{
public:
    virtual void clear() = 0; // clear
    virtual void enqueue(int value) = 0;  // enqueue
    virtual int dequeue() = 0; // dequeue
    virtual int front() = 0; // return first element in queue
    virtual bool isEmpty() const = 0; // is empty
};


