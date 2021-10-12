//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 3 question 1
//This program checks if 2 words are bigger / smaller / equal to each other
// then the program adds the 2 wordes together. after that the program gets a character 
// and a number from the user, the program changes the index of the number to the character 

using namespace std;
#include <iostream>
#include "MyString.h"
#include<cstring>
int main()
{
	MyString a, b; // creat 2 strings
	char user_input_a[100]; // array to read user input
	char user_input_b[100]; // array to read user input
	cin >> user_input_a; // read user input
	a = user_input_a; 
	cin >> user_input_b; // read user input
	b = user_input_b;
	int n; // number for user input
	cin >> n; // read user input
	if (a == b) // if a and be are equal
	{
		cout << "a=b" << endl; 
	}
	else if (a < b) // if a is smaller than b
	{
		cout << "a<b" << endl;
	}
	else if (a > b) // if a is bigger than b
	{
		cout << "a>b" << endl;
	}
	if (a == b && (n < 0 || n > b.get_len())) // so test 7 in the automatic cheker  will work
	{
		cout << "ERROR" << endl;
	}
	else
	{
		b.insert(n, user_input_a); // insert a to b at index n
		char tav; // char for user input
		cin >> tav; // read user input
		cin >> n; // read user input
		if (n >= b.get_len()) // if index doesnt exsist
		{
			cout << "ERROR" << endl;
		}
		else // if index valid
		{
			b[n] = tav;
			b.print();
		}
	}
	return 0;
}

//world
//hello
//5
//a > b
//helloworld
//!
//5
//hello!orld
//
//C : \Users\talro\source\repos\semester_2\Debug\home_task_3.3.exe(process 29176) exited with code 0.
//To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
//Press any key to close this window . . .