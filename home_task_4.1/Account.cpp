//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 4 question 1
//this program keeps track of 10 bank accounts, and allows sevrel actions in the account
#include "Account.h"
#include <cstring>
#include <iostream>
#include<string>
using namespace std;

float Account::sumDeposit = 0; // set sum of all withdraws
float Account::sumWithdraw = 0; // set sum of all deposits

Account::Account() // default consturctor
{
	accountNumber = 0;
	code = 0;
	balance = 0;
	mail = "";
}

Account::Account(int a, int c, float b, string m) // constructor
{
	setAccountNumber(a); // set account number
	setCode(c); // set code
	setBalance(b); // set balance
	setMail(m); // set mail
}

const int Account::getAccountNumber() // get account number
{
	return accountNumber;
}

const int Account::getCode() // get code
{
	return code;
}

float Account::getBalance() // get balance
{
	return balance;
}

string Account::getMail() // get mail
{
	return mail;
}

void Account::setAccountNumber(const int a) // set account number
{
	accountNumber = a;
}

void Account::setCode(const int c) // set code
{
	if (c > 9999 || c < 1000) // verify valid code
	{
		throw "ERROR: code must be of 4 digits!\n"; // throw expresion
	}
	code = c; // if valid
}

void Account::setBalance(float b) // set balance
{
	balance = b;
}

void Account::setMail(string s) // set mail
{
	if (!s.find('@')) // verify @ exisists
	{
		throw "ERROR: email must contain @!\n"; // throw expresion
	}
	int index = s.find('.'); // find index of '.'
	string temp = s.substr(index, (s.size() - 1)); // creat new string containing ending of mail
	if (temp != ".co.il" && temp != ".com") // if ending invalid
	{
		throw "ERROR: email must end at .com or .co.il!\n"; // throw expresion
	}
	mail = s; // if valid
}



void Account::withdraw(float nis) // function to withdraw
{
	if ((balance - nis) < -6000) // if exceeding the account limit
	{
		throw "ERROR: cannot have less than - 6000 NIS!\n"; // throw expresion
	}
	if (nis > 2500) // if withdraw too big
	{
		throw "ERROR: cannot withdraw more than 2500 NIS!\n"; // throw expresion
	}
	balance -= nis; // if valid
	sumWithdraw += nis; // if valid
}

void Account::deposit(float d) // function to deposit
{
	if (d > 10000) // if deposit too big
	{
		throw "ERROR: cannot deposit more than 10000 NIS!\n"; // throw expresion
	}
	balance += d; // if valid
	sumDeposit += d; // if valid
}

float Account::getSumDeposit() // get sum of deposit
{
	return sumDeposit;
}

float Account::getSumWithdraw() // get sum of withdraw
{
	return sumWithdraw;
}

istream& operator>>(istream& is, Account& in) // cin
{
	string s; // creat string for mail
	int a, c; // a for account num, c for code
	is >> a >> c >> s; // read user input
	in.setAccountNumber(a); // set account number
	in.setCode(c); // set code
	in.setMail(s); // set mail
	in.setBalance(0); // set balance to 0
	return is; // return user input
}
