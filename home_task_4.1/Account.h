//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 4 question 1
//this program keeps track of 10 bank accounts, and allows sevrel actions in the account
#pragma once
using namespace std;
#include <iostream>
#include<string>

class Account
{
	int accountNumber;
	int code;
	float balance;
	string mail;
	static float sumWithdraw; // sum of all withdraws
	static float sumDeposit; // sum of all deposits
public: 
	Account(); // default consturctor
	Account(int, int, float, string); // constructor
	const int getAccountNumber(); // get account number
	const int getCode(); // get code
	float getBalance(); // get balance
	string getMail(); // get mail
	void setAccountNumber(const int); // set account number
	void setCode(const int); // set code
	void setBalance(float); // set balance
	void setMail(string); // set mail
	void withdraw(float); // function to withdraw
	void deposit(float); // function to deposit
	static float getSumDeposit(); // get sum of deposit
	static float getSumWithdraw(); // get sum of withdraw
	friend istream& operator>>(istream& is, Account& in); // cin
};

