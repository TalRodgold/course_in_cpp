//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 10 question 1
//this program holds a database of soldiers

#include <vector>
#include <algorithm>
#include <string>
#include "Soldier.h"
#include "Private.h"
#include "Commander.h"
#include "Officer.h"
#include <iostream>
using namespace std;

enum option {
	stop,	//	סיום התוכנית
	addNewSoldier,	//	הוספת חייל חדש
	medalList,	//	הדפסת פרטי כל החיילים הזכאים לצל"ש
	mostSociometric,	//	הדפסת שם (משפחה ופרטי) של  החייל בעל ציון סוציומטרי מקסימלי 
	countMedalPrivate,	//	הדפסת מספר החיילים הטירוניים הזכאים לצל"ש
	noCombatCommander,	//	הדפסת שמות (משפחה ופרטי) של המפקדים שאינם בקרבי
	overSoldier,	//	הדפסת הודעה מתאימה, האם קיים חייל שהשתתף ביותר מ- 15  מבצעים צבאיים
	removeOfficer,	//	מחיקת כל החיילים הקצינים שלא השתתפו כלל במבצע צבאי
};

void add(vector<Soldier*>& v) // adding soldier to vec
{
	//for user input
	int user_input, user_id, user_operations, user_grade, user_score;
	string user_first_name, user_last_name;
	bool user_combat;
	//print
	cout << "enter 1 to add a private soldier\n";
	cout << "enter 2 to add a commander soldier\n";
	cout << "enter 3 to add a officer soldier\n";
	cin >> user_input; // read user input
	
	
	cout << "enter id, first name, last name and number Of operations\n";// print
	cin >> user_id >> user_first_name >> user_last_name >> user_operations;
	switch (user_input)
	{
	case 1: //private
	{
		Private* p = new Private(user_id, user_first_name, user_last_name, user_operations);  // creat new private
		
		if (p->operations)
		{
			cout << "enter " << p->operations << " grades\n";
			for (int i = 0; i < p->operations; i++)
			{
				cin >> user_grade;   
				p->score[i] = user_grade; // add grades
			}
		}
		v.push_back(p); // add to vec
		break;
	}
	case 2: // commander
	{
		Commander* c = new Commander(user_id, user_first_name, user_last_name, user_operations); // creat new commander
		if (c->operations)
		{
			cout << "enter " << c->operations << " grades\n";
			for (int i = 0; i < c->operations; i++)
			{
				cin >> user_grade;
				c->score[i] = user_grade; // add grades
			}
		}
		cout << "enter 1 if the soldier is combat and 0 if not\n"; // special for commander
		cin >> user_combat;
		c->combat = user_combat;
		v.push_back(c);
		break;
	}
	case 3: // officer
	{
		cout << "enter number of sociometric score\n";
		cin >> user_score; 
		Officer* o = new Officer(user_id, user_first_name, user_last_name, user_operations, user_score);// creat new officer
		v.push_back(o);
		break;
	}
	default: cout << "ERROR" << endl; // default
	}
}

void medal(vector<Soldier*>v)  // if worth medal
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]->medal())
		{
			v[i]->print();
		}
			
	}
}

Soldier* mostSociometricScore(vector<Soldier*>v)  // officer with highest score
{
	Soldier* temp = NULL;
	int max = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]->get_score() > max && v[i]->soldier_type() == "officer")
		{
			temp = v[i];
			max = v[i]->get_score();
		}
	}
	return temp;
}

int main()
{
	vector<Soldier*>mySoldiers;  // vec of soldiers
	int op;
	cout << "enter 0-7\n";
	cin >> op;
	while (op != stop)
	{
		switch (op) 
		{             
		case addNewSoldier:add(mySoldiers);  	
			break;
		case medalList:medal(mySoldiers);  
			break;
		case mostSociometric:    
		{
			Soldier* s = mostSociometricScore(mySoldiers); 
			cout << "Officer soldier with most sociometric score: ";
			cout << s->get_first_name() << ' ' << s->get_last_name() << endl;
			break; 
		}
		case countMedalPrivate: 
		{cout << "# private soldier for medal: ";
			cout << count_if(mySoldiers.begin(), mySoldiers.end(), [](Soldier* s) {return s->soldier_type() == "private" && s->medal(); }) << endl;
			break; 
		}
		case noCombatCommander: 
		{cout << "list of no combat commander soldier:";
			for_each(mySoldiers.begin(), mySoldiers.end(), [](Soldier* s) {if (s->soldier_type() == "commander" && !s->is_combat()) cout << s->get_first_name() << " " << s->get_last_name() << endl; });
			cout << endl;
			break; 
		}
		case overSoldier:
		{
			if (any_of(mySoldiers.begin(), mySoldiers.end(), [](Soldier* s) {return s->operations > 15; }))
			cout << "there is a soldier that takes more than 15 operations\n";
			else cout << "no soldier takes more than 15 operations\n";
			break; 
		}
		case removeOfficer:
		{
			vector<Soldier*>::iterator its = remove_if(mySoldiers.begin(), mySoldiers.end(), [](Soldier* s){return s->soldier_type() == "officer" && s->operations == 0; });for_each(mySoldiers.begin(), its, [](Soldier* s) {s->print(); });
		break; 
		}
		};
		cout << "enter 0-7\n";
		cin >> op;
	}
	return 0;
}

//enter 0 - 7
//1
//enter 1 to add a private soldier
//enter 2 to add a commander soldier
//enter 3 to add a officer soldier
//1
//enter id, first name, last nameand number Of operations
//111 aaa aaa 10
//enter 10 grades
//100 100 90 95 98 100 100 100 98 99
//enter 0 - 7
//1
//enter 1 to add a private soldier
//enter 2 to add a commander soldier
//enter 3 to add a officer soldier
//1
//enter id, first name, last nameand number Of operations
//222 bbb bbb 5
//enter 5 grades
//100 100 90 95 98
//enter 0 - 7
//1
//enter 1 to add a private soldier
//enter 2 to add a commander soldier
//enter 3 to add a officer soldier
//2
//enter id, first name, last nameand number Of operations
//333 ccc ccc 8
//enter 8 grades
//100 100 90 95 98 100 100 100
//enter 1 if the soldier is combat and 0 if not
//1
//enter 0 - 7
//1
//enter 1 to add a private soldier
//enter 2 to add a commander soldier
//enter 3 to add a officer soldier
//3
//enter id, first name, last nameand number Of operations
//444 ddd ddd 2
//enter number of sociometric score
//94
//enter 0 - 7
//2
//private
//ID: 111
//first name : aaa
//last name : aaa
//num operations : 10
//grades : 100 100 90 95 98 100 100 100 98 99
//commander
//ID : 333
//first name : ccc
//last name : ccc
//num operations : 8
//grades : 100 100 90 95 98 100 100 100
//combat : yes
//enter 0 - 7
//1
//enter 1 to add a private soldier
//enter 2 to add a commander soldier
//enter 3 to add a officer soldier
//1
//enter id, first name, last nameand number Of operations
//555 eee eee 17
//enter 17 grades
//100 100 90 95 98 100 100 100 98 99 90 95 100 98 100 98 100
//enter 0 - 7
//1
//enter 1 to add a private soldier
//enter 2 to add a commander soldier
//enter 3 to add a officer soldier
//1
//enter id, first name, last nameand number Of operations
//666 fff fff 15
//enter 15 grades
//100 100 90 95 98 100 100 90 95 98 100 100 90 95 98
//enter 0 - 7
//1
//enter 1 to add a private soldier
//enter 2 to add a commander soldier
//enter 3 to add a officer soldier
//2
//enter id, first name, last nameand number Of operations
//777 ggg ggg 8
//enter 8 grades
//100 100 90 95 98 100 100 100
//enter 1 if the soldier is combat and 0 if not
//0
//enter 0 - 7
//1
//enter 1 to add a private soldier
//enter 2 to add a commander soldier
//enter 3 to add a officer soldier
//3
//enter id, first name, last nameand number Of operations
//888 hhh hhh 20
//enter number of sociometric score
//100
//enter 0 - 7
//3
//Officer soldier with most sociometric score : hhh hhh
//enter 0 - 7
//4
//# private soldier for medal: 3
//enter 0 - 7
//5
//list of no combat commander soldier : ggg ggg
//
//enter 0 - 7
//6
//there is a soldier that takes more than 15 operations
//enter 0 - 7
//7
//private
//ID: 111
//first name : aaa
//last name : aaa
//num operations : 10
//grades : 100 100 90 95 98 100 100 100 98 99
//private
//ID : 222
//first name : bbb
//last name : bbb
//num operations : 5
//grades : 100 100 90 95 98
//commander
//ID : 333
//first name : ccc
//last name : ccc
//num operations : 8
//grades : 100 100 90 95 98 100 100 100
//combat : yes
//officer
//ID : 444
//first name : ddd
//last name : ddd
//num operations : 2
//sociometric score : 94
//private
//ID : 555
//first name : eee
//last name : eee
//num operations : 17
//grades : 100 100 90 95 98 100 100 100 98 99 90 95 100 98 100 98 100
//private
//ID : 666
//first name : fff
//last name : fff
//num operations : 15
//grades : 100 100 90 95 98 100 100 90 95 98 100 100 90 95 98
//commander
//ID : 777
//first name : ggg
//last name : ggg
//num operations : 8
//grades : 100 100 90 95 98 100 100 100
//combat : no
//officer
//ID : 888
//first name : hhh
//last name : hhh
//num operations : 20
//sociometric score : 100
//enter 0 - 7
//0
//
//C : \Users\talro\source\repos\semester_2\Debug\home_task_10.1.exe(process 22872) exited with code 0.
//To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
//Press any key to close this window . . .