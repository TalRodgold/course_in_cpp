//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 1 question 2
//This program checks wich worker in latt lev made the least amount of money and the worker who got the highest sallery
#pragma once
class latt_lev
{
	int id;
	char name[21];
	float sallery;
	int hours_worked;
	float money_gained;
public:
	void set_id(int); //this function sets the id
	void set_name(char*); // this function sets the name
	void set_sallery(float); // this function sets sallery
	void set_hours_worked(int); // this function sets hours worked
	void set_money_gained(float); // this function sets money gained
	int get_id(); // this function returns id
	char* get_name(); //this function returns name
	float get_sallery(); //this function returns sallery
	int get_hours_worked(); //this function returns hours worked
	float get_money_gained(); //this function returns money gained
	float sallery_calculator(latt_lev); //this function caluclates the sallery
};

