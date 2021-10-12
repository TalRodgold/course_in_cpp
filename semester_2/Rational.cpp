//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 1 question 1
//This program checks if 2 rational numbers are equal to each other
#include "Rational.h"
#include <iostream>
using namespace std;

void Rational::setDenominator( int num) // this function sets the denuminator
{
	if (!num) // if the denuminator equels 0
	{
		denumerator = 1;
	}
	else // if the denuminator is not 0
	{
		denumerator = num;
	}
}
void Rational::setNumerator(int num)// this function sets the numinator
{
	numerator = num;
}
int Rational::getNumerator() // this function returns the numinator
{
	return numerator;
}
int Rational::getDenumerator() // this function returns the denuminator
{
	return denumerator;
}
void Rational::print() // this function prints out the ratinal number
{
	cout << numerator << "/" << denumerator;
}
bool Rational::equal(Rational num) // this function return true if the 2 ratinal numbers are equal
{
	float temp_numerator = num.numerator; // turn to float
	float temp_dinuminator = numerator; // turn to float
	if (temp_numerator / num.denumerator == temp_dinuminator / denumerator) // if 2 ratinal nubers are equal
	{
		return true;
	}
	return false; // else
}
Rational Rational::reduction(Rational num)// this function reduces a rational number
{
	int i = 2; // counter 
	Rational new_num; // creat a new rational
	new_num.numerator = num.numerator; // define new numerator
	new_num.denumerator = num.denumerator; // define new denumerator
	if (new_num.numerator == new_num.denumerator) // if they are equal
	{
		new_num.numerator = 1;
		new_num.denumerator = 1;
		return new_num; // return reduced rational number
	}
	while (i != 11) // as long as we didnt check all the numbers
	{
		for (i = 2; i < 11; i++) // check for all numbers between 2 and 10
		{
			if (!(new_num.numerator % i) && !(new_num.denumerator % i)) // if both numerator and denumerator can be divided
			{
				new_num.numerator /= i; //divide numerator by i
				new_num.denumerator /= i; // divide denuinator by i
				break;
			}
		}
	}
	return new_num; // return reduced rational number
	
}
Rational Rational::add(Rational num) // this function adds 2 rational numbers  
{
	Rational new_num; // creat a new rational
	new_num.numerator = (num.numerator * denumerator) + (numerator * num.denumerator); // define new numerator
	new_num.denumerator = num.denumerator * denumerator; // define new denumerator
	if (new_num.numerator < 0 && new_num.denumerator < 0) // if they are both negativ
	{
		new_num.numerator *= -1;
		new_num.denumerator *= -1;
	}
	new_num = new_num.reduction(new_num); // reduce the number 
	return new_num; // return new rational number
}
