//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 3 question 1
//This program does mulitple functions (binary and unary) on rational numbers
#include "Rational.h"
#include <iostream>
using namespace std;

Rational Rational::operator *(Rational num) //operator for multipling
{
	Rational tmp; // creat temp rational
	tmp.setNumerator(numerator * num.getNumerator()); // set numirator
	tmp.setDenominator(denominator * num.getDenominator()); // set denominator
	return reduction(tmp); // return new rational after reduction
}
Rational Rational::operator +(const Rational& num) //operator for adding
{
	Rational temp; // creat temp rational
	temp.numerator = numerator * num.denominator + num.numerator * denominator; // set new numinator
	temp.denominator = denominator * num.denominator;// set  new denuminator
	return reduction(temp); // return new rational after reduction
}

Rational& Rational::operator=(const Rational& num) //operator for Placement of a variable
{
	numerator = num.numerator; // set numerator
	denominator = num.denominator; // set denominator
	return *this; // return rational
}

bool Rational::operator==(const Rational& num) const // operator for comparison
{
	return (numerator * num.denominator == denominator * num.numerator); // if is equal return true else will return false
}

bool Rational::operator!=(const Rational& num) const // operator for inequality
{
	Rational temp; // temp rational
	temp.numerator = numerator; // set numerator
	temp.denominator = denominator; // set denominator
	return !temp.equal(num); // return true if not equal and false if equal
}

Rational Rational::operator-(const Rational& num)  // operator for subtraction
{
	Rational temp; // temp rational
	temp.numerator = numerator * num.denominator - num.numerator * denominator; // set numerator
	temp.denominator = denominator * num.denominator; // set denominator
	return reduction(temp); // return new rational after reduction
}

Rational Rational::operator/(const Rational& num) // operator for dividing
{
	Rational temp; // temp rational
	temp.numerator = numerator * num.denominator; // set numerator
	temp.denominator = denominator * num.numerator; // set denominator
	return reduction(temp); // return new rational after reduction
}

bool Rational::operator<=(const Rational& num) // operator for small or equal
{
	if (numerator * num.denominator <= num.numerator *denominator) // if is small or equal
	{
		return true; // return true
	}
	return false; // else
}

bool Rational::operator>=(const Rational& num) // operator for bigger or equal
{
	if (numerator * num.denominator >= num.numerator * denominator) // if is bigger or equal
	{
		return true; // return true
	}
	return false; // else
}

bool Rational::operator<(const Rational& num) // operator for smaller than
{
	if (numerator * num.denominator < num.numerator * denominator) // if smaller than
	{
		return true; // return true
	}
	return false; // else
}

bool Rational::operator>(const Rational& num) // operator for bigger than
{
	if (numerator * num.denominator > num.numerator * denominator) // if bigger than
	{
		return true; // return true
	}
	return false; // else
}

Rational Rational::operator++() // operator for plus one
{
	numerator += denominator; // add one
	return reduction(*this); // return new rational after reduction
}

Rational Rational::operator++(int) // operator for imidiate plus one
{
	Rational temp = *this; // set temp as this
	numerator += denominator; // add one
	return reduction(temp); // return new rational after reduction
}
Rational Rational::operator--()  // operator for minuse one
{
	numerator -= denominator; // minuse one
	return reduction(*this); // return new rational after reduction
}

Rational Rational::operator--(int) // operator for imidiate minuse one
{
	Rational temp = *this; // set temp as this
	numerator -= denominator; // minuse one
	return reduction(temp); // return new rational after reduction
}
void Rational::setDenominator(int num) // this function sets the denuminator
{
	if (!num) // if the denuminator equels 0
	{
		denominator = 1;
	}
	else // if the denuminator is not 0
	{
		denominator = num;
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
int Rational::getDenominator() // this function returns the denuminator
{
	return denominator;
}
void Rational::print() // this function prints out the ratinal number
{
	if (numerator == denominator) // if equal
	{
		cout << "1";
		return; // break
	}
	if (denominator == 1) // if denominator equals 1
	{
		cout << numerator;
		return; // break
	}
	if(!numerator) // if numinator equals 0
	{
		cout << "0";
		return; // break
	}
	if (!(numerator % denominator)) // if rational is a hole num
	{
		cout << numerator / denominator;
		return; // break
	}
	Rational temp;
	temp.numerator = numerator; // set numerator
	temp.denominator = denominator; // set denominator
	temp = reduction(temp);
	cout << temp.numerator << "/" << temp.denominator;
}
bool Rational::equal(Rational num) // this function return true if the 2 ratinal numbers are equal
{
	float temp_numerator = num.numerator; // turn to float
	float temp_dinuminator = numerator; // turn to float
	if (temp_numerator / num.denominator == temp_dinuminator / denominator) // if 2 ratinal nubers are equal
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
	new_num.denominator = num.denominator; // define new denumerator
	if (new_num.numerator == new_num.denominator) // if they are equal
	{
		new_num.numerator = 1;
		new_num.denominator = 1;
		return new_num; // return reduced rational number
	}
	while (i != 11) // as long as we didnt check all the numbers
	{
		for (i = 2; i < 11; i++) // check for all numbers between 2 and 10
		{
			if (!(new_num.numerator % i) && !(new_num.denominator % i)) // if both numerator and denumerator can be divided
			{
				new_num.numerator /= i; //divide numerator by i
				new_num.denominator /= i; // divide denuinator by i
				break;
			}
		}
	}
	return new_num; // return reduced rational number

}
Rational::Rational() // default
{
	numerator = 0;
	denominator = 1;
}
Rational::Rational(int numi, int denumi) // constructor
{
	if (denumi == 0) // if denuminator equals 0
	{
		cout << "ERROR" << endl;
		denumi = 1;
	}
	numerator = numi; // set numirator
	denominator = denumi; // set denumirator
}
Rational Rational::add(Rational num) // this function adds 2 rational numbers  
{
	Rational new_num; // creat a new rational
	new_num.numerator = (num.numerator * denominator) + (numerator * num.denominator); // define new numerator
	new_num.denominator = num.denominator * denominator; // define new denumerator
	if (new_num.numerator < 0 && new_num.denominator < 0) // if they are both negativ
	{
		new_num.numerator *= -1;
		new_num.denominator *= -1;
	}
	new_num = new_num.reduction(new_num); // reduce the number 
	return new_num; // return new rational number
}