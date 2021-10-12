//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 6 question 1
//this program recives from user detailes about 2 types of workers: part time and full time
// then the program calculates the holiday bounus

#include "FullTime.h"
#include "PartTime.h"
#include <iostream>
using namespace std;
int main()
{
	FullTime arrF[3];
	for (int i = 0; i < 3; i++)
	{
		try
		{
			cin >> arrF[i];
		}
		catch (const char* str)
		{
			cout << str << endl;
			i--;
		}
	}


	PartTime arrP[3];
	for (int i = 0; i < 3; i++)
	{
		try
		{
			cin >> arrP[i];
		}
		catch (const char* str)
		{
			cout << str << endl;
			i--;
		}
	}


	for (int i = 0; i < 3; i++)
	{
		cout << arrF[i];
		cout << "After Bonus: " << arrF[i].salaryAfterBonus() <<endl << endl;
	}


	for (int i = 0; i < 3; i++)
	{
		cout << arrP[i];
		cout << "After Bonus: " << arrP[i].salaryAfterBonus() << endl << endl;
	}
	return 0;
}

//Enter employee details :
//aaa
//111
//1
//4500
//Enter employee details :
//bbb
//222
//2
//365
//Enter employee details :
//ccc
//333
//3
//456
//Enter employee details :
//ddd
//444
//4
//987
//36
//Enter employee details :
//eee
//555
//5
//69
//87
//Enter employee details :
//fff
//666
//6
//36
//98
//Employee : aaa
//Employee ID : 111
//Years Seniority : 1
//Salary per Month : 375
//After Bonus : 875
//
//Employee : bbb
//Employee ID : 222
//Years Seniority : 2
//Salary per Month : 30.4167
//After Bonus : 530.417
//
//Employee : ccc
//Employee ID : 333
//Years Seniority : 3
//Salary per Month : 38
//After Bonus : 538
//
//Employee : ddd
//Employee ID : 444
//Years Seniority : 4
//Hours : 987
//Salary per Month : 35532
//After Bonus : 36032
//
//Employee : eee
//Employee ID : 555
//Years Seniority : 5
//Hours : 69
//Salary per Month : 6003
//After Bonus : 6503
//
//Employee : fff
//Employee ID : 666
//Years Seniority : 6
//Hours : 36
//Salary per Month : 3528
//After Bonus : 4410
//
//
//C : \Users\talro\source\repos\semester_2\Debug\home_task_6.1.exe(process 27548) exited with code 0.
//To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
//Press any key to close this window . . .