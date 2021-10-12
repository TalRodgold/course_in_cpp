//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 9 question 2
//this program holds a database of books and allows user to change database
#pragma once
#include "Queue.h"
template<class T>
class QueueVector : public Queue<T>
{
public:
	QueueVector(int max);
	//QueueVector(const QueueVector&);
	void clear() override;
	T dequeue() override;
	void enqueue(T value) override;
	T front() override;
	bool isEmpty()  override;
private:
	T* data;
	int capacity;
	int nextSlot;
	int firstUse;
};

template<class T>
inline QueueVector<T>::QueueVector(int max)
{
	capacity = max + 1;
	data = new T[capacity];
	clear();
}

template<class T>
inline void QueueVector<T>::clear()
{
	nextSlot = 0;
	firstUse = 0;
}

template<class T>
inline T QueueVector<T>::dequeue()
{
	if (isEmpty()) throw "Queue is empty\n";
	int dataloc = firstUse;
	++firstUse %= capacity;
	return data[dataloc];

}

template<class T>
inline void QueueVector<T>::enqueue(T val)
{
	if ((nextSlot + 1) % capacity == firstUse)
		throw "the Queue is full\n";
	data[nextSlot] = val;
	++nextSlot %= capacity;
}

template<class T>
inline T QueueVector<T>::front()
{
	if (isEmpty())
		throw "Queue is empty\n";
	return data[firstUse];
}

template<class T>
inline bool QueueVector<T>::isEmpty()
{
	return nextSlot == firstUse;
}



