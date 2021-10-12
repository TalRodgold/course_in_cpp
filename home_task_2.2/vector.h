//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 2 question 2
//This program does mulitple functions on vectors
#pragma once
class vector
{
	int* data;
	int capacity;
	int size ;
public:
	vector(int num = 2); // contructor to define capacity and data
	vector(const vector& vec); // copy constructor
	~vector(); // distructor
	int get_capacity(); // get capacity
	int get_size(); // get size 
	void print(); // this function prints the vector
	void assign(const vector&); // this function duplicates vector
	bool is_equal(vector); // this function checks if 2 vectors are equal
	int& at(int); // this function returns content of index
	float strcatcat(vector); // this function multiplys by scalar
	vector strnewcat(vector); // this function creats new vector and adds to it 2 vectors
	void clear(); // this function clears content of vector
	void del_last(); // this function deletes last index in data
	void insert(int); // this function inserts value in data

};

