//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 11 question 1
//this program holds a database of families and does multiple functions on it.

#include <iostream>
#include"Family.h"
#include <fstream>
#include <queue>
using namespace std;

void setFile(fstream& file) // function for seting up an empty file
{
	file.seekg(0, ios::beg); // reset pointer
	file.seekp(0, ios::beg); // reset pointer
	Family empty_family; // creat empty family
	for (int i = 0; i < 100; i++) // add it 100 times to file
	{
		file.write((char*)&empty_family, sizeof(Family));
	}
}

void add(fstream& file)
{
	file.seekg(0, ios::beg); // reset pointer
	file.seekp(0, ios::beg); // reset pointer
	cout << "enter family info:" << endl;
	Family temp;
	int number, souls, phone;
	char name[20];
	bool classes[6]{ false };
	cin >> number;
	cin >> name;
	cin >> souls;
	cin >> phone;
	Family new_family(number, name, souls, phone, classes);

	if (number > 100 || number < 1) // check valid input
	{
		throw "ERROR: Invalid family number\n";
	}
	file.seekg((number - 1) * sizeof(Family), ios::beg); // find wanted location for family
	file.read((char*)&temp, sizeof(Family));
	if (temp.get_family_number() == number) // if family already exisists
	{
		throw "ERROR: Family is already in the file\n";
	}
	file.seekp((number - 1) * sizeof(Family), ios::beg); // go to location
	file.write((char*)&new_family, sizeof(Family)); // add family
}

void del(fstream& file, int num) // function for deleting a family
{
	file.seekg(0, ios::beg); // reset pointer
	file.seekp(0, ios::beg); // reset pointer
	Family empty_family;
	if (num < 1 || num > 100) // if invalid input
	{
		throw "ERROR: Invalid family number\n";
	}
	file.seekp((num - 1) * sizeof(Family), ios::beg); // find wanted location for family
	file.write((char*)&empty_family, sizeof(Family)); // delete family
}

void update(fstream& file, int num, queue<Family>& waiting) // this function updates s family
{
	file.seekg(0, ios::beg); // reset pointer
	file.seekp(0, ios::beg); // reset pointer
	Family temp;
	int arr[6]{ 0 };
	bool user_input[6], help_arr[6]{ false }, flag = false;

	if (num < 1 || num > 100) // if invalid input
	{
		throw "ERROR: Invalid family number\n";
	}
	file.seekg((num - 1) * sizeof(Family), ios::beg); // find wanted location for family
	file.read((char*)&temp, sizeof(Family));
	if (temp.get_family_number() != num) // if invalid input
	{
		throw "ERROR: Family is not in the file\n";
	}
	file.seekg(0, ios::beg); // reset pointer
	file.seekp(0, ios::beg); // reset pointer
	for (int i = 0; i < 100; i++) // creat arr of afternoon classes
	{
		file.read((char*)&temp, sizeof(Family));
		for (int j = 0; j < 6; j++)
		{
			if (temp.get_afternoon_classes()[j] ) // if there is a child
			{
				arr[j]++;
			}
		}
	}
	file.seekg((num - 1) * sizeof(Family), ios::beg); // find wanted location for family
	file.read((char*)&temp, sizeof(Family));
	cout << "enter 1 or 0: " << endl;
	for (int i = 0; i < 6; i++) // read user input
	{
		cin >> user_input[i];
	}
	for (int i = 0; i < 6; i++) // update free afternoon classes
	{
		if (user_input[i] && arr[i] < 11) // if theres place
		{
			temp.set_afternoon_classes(true, i);
		}
		if (user_input[i] && arr[i] > 10) // if no place
		{
			help_arr[i] == true;
			flag = true; // to tell us we need to add family to waiting list
		}
	}
	file.seekp((num - 1) * sizeof(Family), ios::beg); // find wanted location for family
	file.write((char*)&temp, sizeof(Family)); // write updated family
	if (flag) // if we need to add to waiting list
	{
		for (int i = 0; i < 6; i++) // set waiting list
		{
			temp.set_afternoon_classes(help_arr[i], i);
		}
		waiting.push(temp); // add to waiting list
	}
}

void waiting(fstream& file, queue<Family>& waiting_list) // function for waiting list
{
	file.seekg(0, ios::beg); // reset pointer
	file.seekp(0, ios::beg); // reset pointer
	queue<Family> temp_queue;
	bool flag = false;
	int temp, check;
	int arr[6]{ 0 };
	for (int i = 0; i < 6; i++) // creat arr of afternoon classes
	{
		file.seekg(32 + i, ios::beg);
		for (int j = 0; j < 100; j++)
		{
			file >> temp;
			if (temp)
			{
				arr[i] += 1;
			}
			file.seekg(32 + i, ios::cur);
		}
	}
	while (!waiting_list.empty()) // as long as we have a waiting list
	{
		file.seekg(0, ios::beg); // reset pointer
		file.seekp(0, ios::beg); // reset pointer
		for (int i = 0; i < 6; i++)
		{
			if (waiting_list.front().get_afternoon_classes()[i] == true && arr[i] < 10) // if waiting and there is place
			{
				arr[i]++;
				waiting_list.front().set_afternoon_classes(false,i);
				for (int j = 0; j < 100; j++)
				{
					file >> check;
					if (check == waiting_list.front().get_family_number())
					{
						file.seekp(file.tellg());
						file.seekp(31+i, ios::cur);
						file << 1;
						break;
					}
					file.seekg(32 + i, ios::cur);
				}
			}
		}
		temp_queue.push(waiting_list.front()); //add to temp queue
		waiting_list.pop(); // pop
	}
	while (!temp_queue.empty()) // copy back queue
	{
		flag = false;
		for (int i = 0; i < 6; i++) // check if need to put back in waiting list
		{
			if (temp_queue.front().get_afternoon_classes()[i] == true) // if need to put back
			{
				flag == true;
			}
		}
		if (flag) // add to waiting list
		{
			waiting_list.push(temp_queue.front());
		}
		temp_queue.pop(); // pop
	}
	
}

bool rishum(fstream& file, int num, int class_num) // function for subscribing
{
	file.seekg(0, ios::beg); // reset pointer
	file.seekp(0, ios::beg); // reset pointer
	Family temp;
	if (num < 1 || num > 100) // if invalid input
	{
		throw "ERROR: Invalid family number\n";
	}
	if (class_num < 1 || class_num > 6) // if invalid input
	{
		throw "ERROR: Invalid class number\n";
	}
	file.seekg((num - 1) * sizeof(Family), ios::beg); // find wanted location for family
	file.read((char*)&temp, sizeof(Family));
	if (temp.get_family_number() != num) // if invalid input
	{
		throw "ERROR: Family is not in the file\n";
	}
	if (temp.get_afternoon_classes()[class_num - 1]) // if afternoon class is true
	{
		return true;
	}
	return false; // else
}

void print(fstream& file, int num)
{
	file.seekg(0, ios::beg); // reset pointer
	file.seekp(0, ios::beg); // reset pointer
	Family temp;
	if (num < 1 || num > 100) // if invalid input
	{
		throw "ERROR: Invalid family number\n";
	}
	file.seekg((num - 1) * sizeof(Family), ios::beg); // find wanted location for family
	file.read((char*)&temp, sizeof(Family));
	if (temp.get_family_number() != num) // if invalid input
	{
		throw "ERROR: Family is not in the file\n";
	}
	cout << temp; // print
}

void inClass(fstream& file, int class_num)
{
	file.seekg(0, ios::beg); // reset pointer
	file.seekp(0, ios::beg); // reset pointer
	Family temp;
	if (class_num < 1 || class_num > 6) // if invalid input
	{
		throw "ERROR: Invalid class number\n";
	}
	for (int i = 0; i < 100; i++)
	{
		file.read((char*)&temp, sizeof(Family));
		if (temp.get_afternoon_classes()[class_num - 1])
		{
			cout << temp.get_family_name();
		}
		
	}
}

int main()
{
	enum option
	{ADD = 1, DEL, UPDATE, WAITING, RISHUM, PRINT, CLASS};
	queue<Family> q;
	fstream file;
	file.open("families.txt", ios::binary | ios::in | ios::out);
	if (!file)
	{
		cout << "ERROR: couldn't open file\n";
		return 0;
	}
	setFile(file);
	int choice;
	int snum;
	int cnum;
	cout << "Choices are:\n0 to exit\n1 to add a family\n2 to delete a family\n3 to update rishum to classes\n4 to update waiting to classes \n5 to check rishum for a classas\n6 to print a family\n7 to print all the families that participate in a specific class\n";
	cout << "enter 0-7:\n";
	cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case ADD://add to the file
			try { add(file); }
			catch (const char* msg) { cout << msg; }
			break;
		case DEL://delete from file
			cout << "enter number of family to delete:\n";
			cin >> snum;
			try { del(file, snum); }
			catch (const char* msg) { cout << msg; }
			break;
		case UPDATE://update the list of classes of a family
			cout << "enter number of family to update:\n";
			cin >> snum;
			try { update(file, snum, q); }
			catch (const char* msg) { cout << msg; }
			break;
		case WAITING://update the list of classes of a waiting family
			waiting(file, q);
			break;
		case RISHUM://check rishum to a specific class
			cout << "enter number of family to check rishum:\n";
			cin >> snum;
			cout << "enter number of class to check rishum:\n";
			cin >> cnum;
			try
			{
				cout << "The family is" << (rishum(file, snum, cnum) ? " " : " not ") << "taking the class\n";
			}
			catch (const char* msg) { cout << msg; }
			break;
		case PRINT://print the details of a specific family
			cout << "enter number of family to print:\n";
			cin >> snum;
			try { print(file, snum); }
			catch (const char* msg) { cout << msg; }
			break;
		case CLASS://print the details of all the families that are taking a specific class
			cout << "enter number of class to check rishum:\n";
			cin >> cnum;
			try { inClass(file, cnum); }
			catch (const char* msg) { cout << msg; }
			break;
		default:
			cout << "ERROR: invalid choice\n";

		}
		cout << "\nenter 0-7:\n";
		cin >> choice;
	}
	file.close();
	return 0;
}

//Choices are :
//0 to exit
//1 to add a family
//2 to delete a family
//3 to update rishum to classes
//4 to update waiting to classes
//5 to check rishum for a classas
//6 to print a family
//7 to print all the families that participate in a specific class
//enter 0 - 7 :
//	1
//	enter family info :
//2
//wrgtrht
//222
//22
//
//enter 0 - 7:
//3
//enter number of family to update :
//2
//enter 1 or 0 :
//	1 1 1 0 0 0
//
//	enter 0 - 7 :
//	6
//	enter number of family to print :
//2
//Family name : wrgtrht
//Number os souls : 222
//Phone number : 22
//Afternoon classes : Y  Y  Y  N  N  N
//
//enter 0 - 7 :
//	7
//	enter number of class to check rishum :
//2
//wrgtrht
//enter 0 - 7 :
//	0
//
//	C : \Users\talro\source\repos\semester_2\Debug\home_task_11.1.exe(process 17692) exited with code 0.
//	To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
//	Press any key to close this window . . .