//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 9 question 2
//this program holds a database of books and allows user to change database

#pragma once
#include<string>
#include <iostream>
using namespace std;
class Books
{
	int code;   
	string author_name;
	string book_name;
public:
	Books() { code = 0; author_name = ""; book_name = ""; }  // constructor
	const bool operator==(const Books&); // equal
	const bool operator!=(const Books&); // not equal
	const bool operator<(Books&);    // smaller
	const bool operator>(const Books&); // bigger
	const bool operator<=(const Books&); // smaller and equal
	const bool operator>=(const Books&); // bigger and equal
	friend ostream& operator<<(ostream& os, const Books& in);  // cout
	friend istream& operator>>(istream& is, Books& in);   // cin
};


