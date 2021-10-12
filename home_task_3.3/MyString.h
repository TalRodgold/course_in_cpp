//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 3 question 1
//This program checks if 2 words are bigger / smaller / equal to each other
// then the program adds the 2 wordes together. after that the program gets a character 
// and a number from the user, the program changes the index of the number to the character 
#pragma once
#include <iostream>
#include<cstring>
class MyString
{
	void setMyString(const char*); // does a deep copy
	int len; // length
	char* array; // word
public:
	MyString(); // default
	MyString(const char*); // consturctor
	MyString(const MyString&); // copy constructor
	~MyString(); // distractor
	bool operator==(const MyString& s) const; // is equal
	bool operator!=(const MyString& s) const; // is not equal
	bool operator<(const MyString& s) const { return strcmp(array, s.array) < 0; } // smaller than
	bool operator>(const MyString& s) const { return strcmp(array, s.array) > 0; } // bigger than
	bool operator<=(const MyString& s) const { return strcmp(array, s.array) <= 0; } // smaller and equal than
	bool operator>=(const MyString& s) const { return strcmp(array, s.array) >= 0; } // bigger and equal than
	char& operator[](int index); // index operator
	MyString& operator=(const MyString&); // equal
	void insert(int index, const char* str);// insert two strings together from given index
	int get_len(); // get length
	void print(); // print
};


