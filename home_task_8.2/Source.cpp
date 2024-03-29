//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 8 question 2
//this program implements a queue using stack

#include <iostream>
#include "QueueStack.h"
using namespace std;
int main() {
	Queue* Q;
	Q = new QueueStack();
	try {
		for (int i = 0; i < 10; i++)
			Q->enqueue(i);
	}
	catch (const char* msg)
	{
		cout << msg;
	}
	cout << "first on Q is: " << Q->front() << endl;
	cout << "take out 2 elemets:" << endl;
	cout << Q->dequeue() << ' ' << Q->dequeue() << endl;
	cout << "first on Q is: " << Q->front() << endl;
	Q->enqueue(8);
	Q->enqueue(9);
	while (!Q->isEmpty())
		cout << Q->dequeue() << " ";
	return 0;
}
//first on Q is : 0
//take out 2 elemets :
//	1 0
//	first on Q is : 2
//	2 3 4 5 6 7 8 9 8 9
//	C : \Users\talro\source\repos\semester_2\Debug\home_task_8.2.exe(process 44652) exited with code 0.
//	To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
//	Press any key to close this window . . .