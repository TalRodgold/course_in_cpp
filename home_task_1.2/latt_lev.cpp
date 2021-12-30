//Name: Tal Rodgold
//Course: Workshop in c++
//Task number: task 1 question 2
//This program checks wich worker in latt lev made the least amount of money and the worker who got the highest sallery
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "latt_lev.h"
#include <iostream>
using namespace std;

void latt_lev :: set_id(int temp) //this function sets the id
{
	id = temp;
}
void latt_lev::set_name(char* temp) // this function sets the name
{
	strcpy(name, temp);
}
void latt_lev::set_sallery(float temp)// this function sets sallery
{
	sallery = temp; 
}
void latt_lev::set_hours_worked(int temp) // this function sets hours worked
{
	hours_worked = temp;
}
void latt_lev :: set_money_gained(float temp)// this function sets money gained
{
	money_gained = temp;
}
int latt_lev :: get_id() // this function returns id
{
	return id;
}
char* latt_lev :: get_name() //this function returns name
{
	return name;
}
float latt_lev::get_sallery() //this function returns sallery
{
	return sallery;
}
int latt_lev::get_hours_worked() //this function returns hours worked
{
	return hours_worked;
}
float latt_lev::get_money_gained() //this function returns money gained
{
	return money_gained;
}
float latt_lev::sallery_calculator(latt_lev worker) //this function caluclates the sallery
{
	float total_sallery = 0; // total sallery
	float gained_money = worker.money_gained; // money worker gained
	float percent[5]{ 0.10, 0.15, 0.20, 0.30, 0.40 }; // percent gained by worker
	int gained[5]{ 1000, 1000, 2000, 1000, worker.money_gained };// money gained by worker
	for (int i = 0; i < 5; i++) // run 5 times for every percent
	{
		if ( gained_money > 0 ) // check how much percent to give worker
		{
			if (gained_money < gained[i]) // for last time
			{
				total_sallery += gained_money * percent[i];
				break;
			}
			total_sallery += gained[i] * percent[i]; // add percent to total sallery
			gained_money -= gained[i]; // reduce sum from gained money
		}
	}
	total_sallery += worker.hours_worked * worker.sallery; // add to total sallery
	return total_sallery;   // return total sallery for worker
}
