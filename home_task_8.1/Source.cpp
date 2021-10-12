//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 8 question 1
//this program converts user input from infixToPostfix to  Postfix 
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string infixToPostfix(string s) // convert infixToPostfix to  Postfix 
{
	char ch; // save character
	string str; // saave string to return
	stack<char> stk; // stack of type char
	for (int i = 0; i < s.length(); i++) // for every char in s
	{
		ch = s[i]; 
		if (ch == '(') 
		{
			stk.push(ch); // push '(' to stk
		}
		else if (ch == ')')
		{			
			while (!stk.empty() && stk.top() != '(')  // till stack is empty or '('
			{
				str += stk.top(); // copy top
				stk.pop(); // pop
			}
			stk.pop(); // pop
		}
		
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') // if operator
		{
			if (ch == '+' || ch == '-') // if plus or minus
			{
				while (!stk.empty() && (stk.top() == '*' || stk.top() == '/' || stk.top() == '+' || stk.top() == '-')) // while operator is bigger
				{
					str += stk.top(); // copy top
					stk.pop(); // pop
					
				}
				stk.push(ch); // push
			}
			else if (ch == '*' || ch == '/') // if divide or multiply
			{
				while (!stk.empty() && (stk.top() == '*' || stk.top() == '/')) // while operator is bigger
				{
					str += stk.top(); // copy top
					stk.pop(); // pop
				}
				stk.push(ch); // push
			}
		}
		else // if number
		{
			str += ch; // add number to str
		}
		if (i == (s.length() - 1)) // if we finished s
		{
			while (!stk.empty()) // as long as stack not empty
			{
				int temp_2 = int(s[i + 1]); // if next char is num
				if (temp_2 <= 47 || temp_2 >= 58) // if not num
				{
					str += " "; // add space
				}
				str += stk.top(); // copy top
				stk.pop(); // pop
			}
		}
		if ((i + 1) != s.length()) // if not end
		{
			int temp = int(s[i + 1]);
			if (temp != 40 && (temp <= 47 || temp >= 58)) // check if next char is num
			{
				str += " "; // add space
			}
		}
	}
	return str; // return Postfix
}
int calcPostfix(string s) // calculate Postfix
{
	int num; // number 
	stack<int> stk; // stack
	string str; // string
	for (int i = 0; i < s.length(); i++) //  for every char in s
	{
		str = ""; // empty str
		while (s[i] != ' ' && i != s.length()) // if not space
		{
			str += s[i]; // add next char
			i++; // grow i by 1
		}
		
		if (!(str == "+" || str == "-" || str == "*" || str == "/")) //if number
		{
			int size = str.length(); // size of str
			num = 0; // reset num
			for (int i = 0; i < size - 1; i++) // if more than 1 digit
			{
				num += (str[i] - 48) * (10 * (i+1)); //grow digit
			}
			num += (str[str.length() - 1]) - 48; // add last digit or if only 1 digit
			stk.push(num); // push
		}
		else // if operator
		{
			int temp_1 = stk.top(); // pop first number
			stk.pop();
			int temp_2 = stk.top(); // pop second number
			stk.pop();
			int answer; // for answer
			if (str == "*") // if multiply
			{
				answer = temp_2 * temp_1;
			}
			else if (str == "+") // if plus
			{
				answer = temp_2 + temp_1;
			}
			else if (str == "-") // if minus
			{
				answer = temp_2 - temp_1;
			}
			else if (str == "/") // if divide
			{
				answer = temp_2 / temp_1;
			}
			stk.push(answer); // push answer
		}
	}
	return stk.top(); // return answer
}

int main()
{
	string exp;
	cout << "enter an infix expression as a string" << endl;
	cin >> exp;
	string postfix = infixToPostfix(exp);
	cout << postfix << endl;
	cout << calcPostfix(postfix) << endl;
	return 0;
}
//enter an infix expression as a string
//(5 + 3)* ((20 / 10) + (8 - 6))
//5 3 + 20 10 / 8 6 - +*
//32
//
//C:\Users\talro\source\repos\semester_2\Debug\home_task_8.1.exe(process 26640) exited with code 0.
//To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
//Press any key to close this window . . .
