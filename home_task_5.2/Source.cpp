//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 5 question 2
//this program recives from user 2 lists and the merges them, reverses them and sets them
#include <iostream>
#include "List.h"
using namespace std;

void reverse(List& lst) // this function reverses the list
{
	List new_lst; // creat new list
	while (!(lst.isEmpty()))// while list if not empty
	{
		new_lst.add(lst.firstElement()); //copy to new list the first elemnt
		lst.removeFirst(); // delete first elemnt
	}
	lst = new_lst; // paste new list
}

List merge(List lst1, List lst2) // this function murges 2 lists together
{
	reverse(lst1); // reverse the list
	reverse(lst2); // reverse the list
	List new_lst; // creat new list
	while (!(lst1.isEmpty()) && !(lst2.isEmpty())) // as long as both lists are not empty
	{
		if (lst1.firstElement() <= lst2.firstElement()) // if first element in list 1 is smaller
		{
			new_lst.add(lst1.firstElement()); // add to new list
			lst1.removeFirst(); // remove first element
		}
		else // if first element in list 2 is smaller
		{
			new_lst.add(lst2.firstElement()); // add to new list
			lst2.removeFirst(); // remove first element
		}
	}
	// when one of the lists is empty
	if (lst1.isEmpty()) // if list 1 is empty
	{
		while (!(lst2.isEmpty())) // as long as list not empty
		{
			new_lst.add(lst2.firstElement()); // add to new list
			lst2.removeFirst(); // remove first element
		}
	}
	else // if list 2 is empty
	{
		while (!(lst1.isEmpty())) // as long as list not empty
		{
			new_lst.add(lst1.firstElement()); // add to new list
			lst1.removeFirst(); // remove first element
		}
	}
	return new_lst; // return mereged list
}
void makeSet(List& lst) // this function creats a set
{
	List new_lst; // creat new list
	new_lst.add(lst.firstElement()); // add first element
	lst.removeFirst(); // remove first element
	while (!(lst.isEmpty())) // as long as list in not empty
	{
		if (lst.firstElement() == new_lst.firstElement()) // if elemnt already exisists
		{
			lst.removeFirst(); // delete
		}
		else 
		{
			new_lst.add(lst.firstElement()); // add to new list
			lst.removeFirst(); // remove first element
		}
	}
	reverse(new_lst); // reverse new list
	lst = new_lst; //  paste new list
}
int main()
{
	List lst1, lst2, mergedList;
	try
	{
		cout << "enter sorted values for the first list:" << endl;
		cin >> lst1;
		cout << "enter sorted values for the second list:" << endl;
		cin >> lst2;
		mergedList = merge(lst1, lst2);
		cout << "the new merged list: " << mergedList << endl;

		makeSet(mergedList);
		cout << "the new merged set: " << mergedList << endl;

		reverse(mergedList);
		cout << "the new merged reverse: " << mergedList << endl;

	}
	catch (const char* txt)
	{
		cout << txt << endl;
	}
	return 0;
}

//enter sorted values for the first list :
//6 5 4 3 2 1 9
//enter sorted values for the second list :
//7 5 4 3 9
//the new merged list : 7 6 5 5 4 4 3 3 2 1
//the new merged set : 7 6 5 4 3 2 1
//the new merged reverse : 1 2 3 4 5 6 7
//
//C : \Users\talro\source\repos\semester_2\Debug\home_task_5.2.exe(process 10676) exited with code 0.
//To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
//Press any key to close this window . . .
