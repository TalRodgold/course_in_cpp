//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 3 question 1
//This program does mulitple functions (binary and unary) on rational numbers
#pragma once
class Rational
{
	int numerator;
	int denominator;
	Rational reduction(Rational); // this function reduces a rational number
public:
    Rational(); // default
    Rational(int, int); // constructor
    //binary operations
    Rational operator*(Rational); //operator for multipling
    Rational operator+(const Rational&); //operator for adding
    Rational& operator=(const Rational&); //operator for Placement of a variable
    Rational operator-(const Rational&); // operator for subtraction
    Rational operator/(const Rational&); // operator for dividing
    Rational operator++(); // operator for plus one
    Rational operator++(int); // operator for imidiate plus one
    Rational operator--(); // operator for minuse one
    Rational operator--(int); // operator for imidiate minuse one
    bool operator<=(const Rational&); // operator for small or equal
    bool operator>=(const Rational&); // operator for bigger or equal
    bool operator<(const Rational&); // operator for smaller than
    bool operator>(const Rational&); // operator for bigger than
    bool operator==(const Rational&) const; // operator for comparison
    bool operator!=(const Rational&) const; // operator for inequality
	void setDenominator(int); // this function sets the denuminator
	void setNumerator(int); // this function sets the numinator
	int getNumerator(); // this function returns the numinator
	int getDenominator(); // this function returns the denuminator
	void print(); // this function prints out the rational number
	bool equal(Rational); // this function return true if the 2 rational numbers are equal
	Rational add(Rational); // this function adds 2 rational numbers
};
