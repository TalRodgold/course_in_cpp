//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 1 question 2
//This program checks wich worker in latt lev made the least amount of money and the worker who got the highest sallery
#define _CRT_SECURE_NO_WARNINGS
#include "latt_lev.h"
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	latt_lev currnt_worker, min_sum , max_sallery; // 3 varibels to keep data of currnt worker, worker with min income and worker with max sallery
	bool first_worker = true; //chaek if this is the first worker
	bool flag; // flag to check valid input
	int num; // user input for id / exit program
	char name[21]; // user input name
	float sallery; // user input sallery
	int hours_worked; // user input houers worked
	float money_gained; // user input money gained
	cout << "enter details, to end enter 0:" << endl;
	cin >> num;
	while (num) // as long as user input is not 0
	{
		flag = true; // reset flag
		currnt_worker.set_id(num); // set id
		cin >> name;
		currnt_worker.set_name(name); // set name
		cin >> sallery;
		if (sallery < 0) // check valid input
		{
			flag = false;
		}
		currnt_worker.set_sallery(sallery); // set sallery
		cin >> hours_worked;
		if (hours_worked < 0) // check valid input
		{
			flag = false;
		}
		currnt_worker.set_hours_worked(hours_worked); // set houers worked
		cin >> money_gained;
		if (money_gained < 0) // check valid input
		{
			flag = false;
		}
		currnt_worker.set_money_gained(money_gained); // set money gained
		if (first_worker && flag) // if this is the first worker from user input and user input was valid
		{
			min_sum = currnt_worker;
			max_sallery = currnt_worker;
			first_worker = false; // change flag for first worker
			cin >> num; // get user input
			continue;
		}
		if (flag) // if user input was valid
		{
			if (currnt_worker.get_money_gained() < min_sum.get_money_gained()) // if new worker gained less money
			{
				min_sum = currnt_worker;
			}
			if (currnt_worker.sallery_calculator(currnt_worker) > max_sallery.sallery_calculator(max_sallery)) // if new worker got higher sallery
			{
				max_sallery = currnt_worker;
			}
		}
		else // if user input was invalid
		{
			cout << "ERROR" << endl;
		}
		cin >> num; // read user input
	}
	cout << "minimum sum: " << min_sum.get_money_gained() << " " << min_sum.get_name() << " " << min_sum.get_id() << endl;
	cout << "highest salary: " << max_sallery.sallery_calculator(max_sallery) << " " << max_sallery.get_name() << " " << max_sallery.get_id() << endl;	
	return 0;
}

//enter details, to end enter 0:
//1111111 doron 35 120 6000
//2222222 tal 50 55 1400
//4444444 levi 45 - 4 100
//ERROR
//3333333 naomi 30 120 800
//0
//minimum sum : 800 naomi 3333333
//highest salary : 5550 doron 1111111
//
//C : \Users\talro\source\repos\semester_2\Debug\home_task_1.2.exe(process 9148) exited with code 0.
//To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
//Press any key to close this window . . .
