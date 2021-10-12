//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 9 question 2
//this program holds a database of books and allows user to change database
#include "Books.h"
#include<iostream>
using namespace std;
#include<string>
#include<string.h>

const bool Books::operator==(const Books& in) // equal
{
	if (code != in.code || author_name.compare(in.author_name) || book_name.compare(in.book_name)) // if not equal
	{
		return false;
	}
	return true;
}

const bool Books::operator!=(const Books& in) // not equal
{
	if (code == in.code && !author_name.compare(in.author_name) && !book_name.compare(in.book_name)) // if equal
	{
		return false;
	}	
	return true;
}

const bool Books::operator<(Books& in)  // smaller
{
	if (code < in.code) // check code
	{
		return true;
	}
	if (author_name.compare(in.author_name) < 0) // check author
	{
		return true;
	}
	if (book_name.compare(in.book_name) < 0) // check book
	{
		return true;
	}
	return false;
}

const bool Books::operator>(const Books& in) // bigger
{
	if (code > in.code) // check code
	{
		return true;
	}
	if (author_name.compare(in.author_name) > 0) // check author
	{
		return true;
	}
	if (book_name.compare(in.book_name) > 0) // check book
	{
		return true;
	}
	return false;
}

const bool Books::operator<=(const Books& in) // smaller and equal
{
	if (author_name.compare(in.author_name) <= 0)
	{
		return true;
	}	
	return false;
}

const bool Books::operator>=(const Books& in) // bigger and equal
{
	if (author_name.compare(in.author_name) >= 0)
	{
		return true;
	}
	return false;
}

ostream& operator<<(ostream& os, const Books& in)  // cout 
{
	os << in.code << " " << in.author_name << " " << in.book_name;
	return os;
}

istream& operator>>(istream& is, Books& in) // cin 
{
	is >> in.code >> in.author_name >> in.book_name;
	return is;
}
