//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 1 question 1
//This program checks if 2 rational numbers are equal to each other
#pragma once
class Rational
{
	int numerator;
	int denumerator;
	Rational reduction(Rational); // this function reduces a rational number
public:
	void setDenominator(int); // this function sets the denuminator
	void setNumerator(int); // this function sets the numinator
	int getNumerator(); // this function returns the numinator
	int getDenumerator(); // this function returns the denuminator
	void print(); // this function prints out the rational number
	bool equal(Rational); // this function return true if the 2 rational numbers are equal
	Rational add(Rational); // this function adds 2 rational numbers
};

