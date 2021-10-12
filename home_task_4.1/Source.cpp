//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 4 question 1
//this program keeps track of 10 bank accounts, and allows sevrel actions in the account

#include <iostream>
#include "Clock.h"
#include "Account.h"
using namespace std;

enum action
{
	stop,
	balance,
	deposit,
	withdraw,
	sumDeposit,
	sumWithdraw
};
action menu()
{
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all withdraws" << endl;
	cout << "enter 5 to see the sum of all Deposits" << endl;
	cout << "enter 0 to stop" << endl;
	int x;
	cin >> x;
	return (action)x;
}
int findAccount(Account* bank, int size)
{
	int number, code;
	cout << "please enter account number: ";
	cin >> number;
	int i = 0;
	while (i < size && bank[i].getAccountNumber() != number)
		i++;
	if (i == size) // if account number does not exsist
	{
		throw "ERROR: no such account number!\n";
	}
	cout << "please enter the code: ";
	cin >> code;
	if (bank[i].getCode() == code)
		return i;
	throw "ERROR: wrong code!\n"; // if code is wrong
}
void printTransaction(Account a, action ac, Clock& c)
{
	cout << c << "\t";
	;
	switch (ac)
	{
	case balance: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "balance: " << a.getBalance() << endl;
		break;
	case deposit:
	case withdraw: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "new balance: " << a.getBalance() << endl;
		break;
	case sumDeposit:
		cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
		break;
	case sumWithdraw:
		cout << "sum of all withdraws: " << Account::getSumWithdraw() << endl;
		break;
	}
}
void getBalance(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);
	c += 20;
	printTransaction(bank[i], balance, c);
}
void cashDeposit(Account* bank, int size, Clock& c)
{
	try // try to check valid user input
	{
		int i = findAccount(bank, size);
		float amount;
		cout << "enter the amount of the check: ";
		cin >> amount;
		bank[i].deposit(amount);
		c += 30;
		printTransaction(bank[i], deposit, c);
	}
	catch (const char* msg) // catch for error
	{
		cout << c << '\t' << msg;
	}
}
void cashWithdraw(Account* bank, int size, Clock& c)
{
	
	try // try to check valid user input
	{
		int i = findAccount(bank, size);
		if (i < 0)
		{
			throw "ERROR: wrong code!\n";
		}
		float amount;
		cout << "enter the amount of money to withdraw: ";
		cin >> amount;
		bank[i].withdraw(amount);
		c += 50;
		printTransaction(bank[i], withdraw, c);
	}
	catch (const char* msg) // catch for error
	{
		cout << c << '\t' << msg;
	}
	
}
int main()
{
	Clock c(8);
	Account bank[10];
	cout << "enter account number, code and email for 10 accounts:\n";
	for (int i = 0; i < 10; i++)
	{
		try {
			cin >> bank[i];
			for (int j = 0; j < i; j++)
				if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
					throw "ERROR: account number must be unique!\n";
		}
		catch (const char* msg)
		{
			cout << c << '\t' << msg;
			i--;
		}
	}
	action ac = menu();
	while (ac)
	{
		switch (ac)
		{
		case balance: getBalance(bank, 10, c);
			break;
		case withdraw:cashWithdraw(bank, 10, c);
			break;
		case deposit:cashDeposit(bank, 10, c);
			break;
		case sumDeposit:c += 60;
			printTransaction(bank[0], sumDeposit, c);
			break;
		case sumWithdraw:c += 60;
			printTransaction(bank[0], sumWithdraw, c);

		}
		ac = menu();
	}
	return 0;
}

//enter account number, codeand email for 10 accounts:
//1 1111 aaa@gmail.com
//2 2222 aaa@gmail.com
//3 3333 bbb@gmail.com
//4 4444 ccc@gmail.com
//5 5555 ddd@gmail.com
//6 6666 eee@gmail.com
//7 7777 fff@gmail.com
//8 8888 ggg@gmail.com
//9 9999 hhh@gmail.com
//10 1010 iii@gmail.com
//enter 1 to get account balance
//enter 2 to deposit money
//enter 3 to withdraw money
//enter 4 to see the sum of all withdraws
//enter 5 to see the sum of all Deposits
//enter 0 to stop
//3
//please enter account number : 40
//08 : 00 : 00 : ERROR : no such account number!enter 1 to get account balance
//enter 2 to deposit money
//enter 3 to withdraw money
//enter 4 to see the sum of all withdraws
//enter 5 to see the sum of all Deposits
//enter 0 to stop
//
//C : \Users\talro\source\repos\semester_2\Debug\home_task_4.1.exe(process 18172) exited with code - 1.
//To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
//Press any key to close this window . . .

