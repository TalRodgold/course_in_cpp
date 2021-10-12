#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include <iostream>
#include<cstring>
using namespace std;

MyString::MyString(const char* str) // consturctor
{
	setMyString(str);
}

MyString::MyString() : MyString("") {} // default

MyString::MyString(const MyString& str) : MyString(str.array) {} // copy constructor

MyString::~MyString() // distractor
{
	delete[] array;
 }

bool MyString::operator==(const MyString& s) const // is equal
{
	if (len != s.len) // if length is different
	{
		return false; // return false
	}
	for (int i = 0; i < len; i++) // for every letter in words
	{
		if (array[i] != s.array[i] && array[i] != (s.array[i] + 32) && (array[i] + 32) != s.array[i]) // if they are not equal (also cappital)
		{
			return false; // return false
		}
	}
	return true; // if words equal return true
}

bool MyString::operator!=(const MyString& s) const // is not equal
{

	if (len != s.len) // if length is different
	{
		return true; // return true
	}
	for (int i = 0; i < len; i++) // for every letter in words
	{
		if (array[i] != s.array[i] && array[i] != (s.array[i] + 32) && (array[i] + 32) != s.array[i]) // if they are not equal (also cappital)
		{
			return true; // return true
		}
	}
	return false; // if words equal return false
}

MyString& MyString::operator=(const MyString& str) // equal
{
	if (&str != this) // if diffrent
	{
		delete[] array; // delete

		setMyString(str.array); // set string
	}

	return *this; // return string
}

int MyString::get_len() // get length
{
	return len; // return length
}



char& MyString::operator[](int index) // index operator
{
	if (index < 0 || index > len) // throw exception
	{
		cout << "ERROR" << endl;
	}
	return array[index]; // return index in array
}


void MyString::insert(int index, const char* str) // insert two strings together from given index
{
	if (index < 0 || index > len) // throw exception
	{
		cout << "ERROR" << endl;
		MyString empty;
		*this = empty; // return empty
	}
	else
	{
		int i; // counter
		int j = 0; // counter
		int new_str_len = strlen(str) + len + 1; // new length
		MyString new_str; // new string
		new_str.len = new_str_len; // copy new length
		new_str.array = new char[new_str_len]; // creat new char
		for (i = 0; i < index; i++) // copy all the characters till index
		{
			new_str.array[i] = array[i];
		}
		int k = i;
		for (i; i < index + strlen(str); i++) // copy second word
		{
			new_str.array[i] = str[j];
			j++;
		}
		for (k; k < len; k++) // copy rest of first word
		{
			new_str.array[i] = array[k];
			i++;
		}
		new_str[strlen(str) + len] = '\0'; // add null to end of string
		*this = new_str; // return new string
		new_str.print(); // print
	}
}


void MyString::setMyString(const char* str) // does a deep copy
{
	if (str)
	{
		len = strlen(str); // set length
		array = new char[len + 1]; // creat array in the correct size
		strcpy(array, str); // copy
	}
	else // if empty
	{
		array = NULL;
	}
	
}

void MyString::print() // print
{
	cout << array << endl;;
}