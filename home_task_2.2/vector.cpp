//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 2 question 2
//This program does mulitple functions on vectors
#include "vector.h"
#include <iostream>
using namespace std;

vector::vector(int num) // contructor to define capacity and data
{
	capacity = num;
	size = 0;
	data = new int[capacity];
}

vector::vector(const vector& vec) // copy constructor
{
	capacity = vec.capacity; //copy capacity
	size = vec.size; // copy size
	data = new int[capacity]; // creat new array
	for (int i = 0; i < size; i++) // copy array
	{
		data[i] = vec.data[i];
	}
}

vector::~vector() // distructor
{
	if (capacity) // if array exisists
	{
		delete[] data; // delete
	}
}

int vector::get_capacity() // get capacity
{
	return capacity;
}

int vector::get_size() // get size 
{
	return size;
}

void vector::print() // this function prints the vector
{
	cout << "capacity: " << capacity << " size: " << size << " values:"; // print capacity and size
	for (int i = 0; i < size; i++) // print data
	{
		cout << " " << data[i];
	}
	cout << endl;
}

void vector::assign(const vector& vec) // this function duplicates vector
{
	capacity = vec.capacity; // copy capacity
	size = vec.size; // copy size
	data = new int[capacity]; // creat new array
	for (int i = 0; i < size; i++) // copy data
	{
		data[i] = vec.data[i];
	}
}

bool vector::is_equal(vector vec) // this function checks if 2 vectors are equal
{
	if (size != vec.size) // if size is diffrent
	{
		return false; // return false
	}
	for (int i = 0; i < size; i++) // check every number in vector
	{
		if (data[i] != vec.data[i]) // if numbers are diffrent
		{
			return false; // return false
		}
	}
	return true; // if vectors are equal return true
}

int& vector::at(int index) // this function returns content of index
{
	if (index >= size || index < 0) // if index does not exisst
	{
		cout << "ERROR" << endl; // print error
		return data[0]; // return first index
	}
	return data[index]; // return wanted index
}

float vector::strcatcat(vector vec) // this function multiplys by scalar
{
	float total = 0; // total
	if (size != vec.size ) // if vectors are diffrent sizes
	{
		cout << "ERROR" << endl; // print error
		return -1; // return -1
	}
	for (int i = 0; i < size; i++) // if vectors are same size
	{
		total += data[i] * vec.data[i]; // muliply and add to total
	}
	return total; // return total
}

vector vector::strnewcat(vector vec) // this function creats new vector and adds to it 2 vectors
{
	int i = 0; // counter
	int j = 0; // counter
	int new_size = vec.size + size; // new size from 2 vectors
	vector new_vec(capacity + vec.capacity); // creat new vector
	new_vec.size = new_size;
	for (i; i < size; i++) // copy first vector
	{
		new_vec.data[i] = data[i];
	}
	for (i; i < new_size; i++ && j++) // copy second vector
	{
		new_vec.data[i] = vec.data[j];
	}
	return new_vec; // return new vector
}

void vector::clear() // this function clears content of vector
{
	for (int i = 0; i < size; i++) // clear data
	{
		data[i] = 0;
	}
	size = 0; // clear size
}

void vector::del_last() // this function deletes last index in data
{
	if (size == 0) // if data is empty
	{
		cout << "ERROR" << endl; // print error
	}
	else // if data not empty
	{
		data[size - 1] = 0; // clear last
		size--;
	}
}

void vector::insert(int val) // this function inserts value in data
{
	if (size == capacity) // if cappacity is full
	{
		capacity *= 2; // grow cappacity by 2
		int* new_data = new int[capacity]; // creat new array
		for (int i = 0; i < size; i++) // copy data
		{
			new_data[i] = data[i];
		}
		delete[] data; // delete old data
		data = new_data; // insert new data

	}
	data[size] = val; //insert value to data
	size++; // grow size by 1
}
