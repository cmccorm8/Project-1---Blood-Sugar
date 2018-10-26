//Chance McCormick
//Cosc 2030
//Project 1-Blood Sugar
//10/11/2018
#ifndef _BLOODSUGAR_H_
#define _BLOODSUGAR_H_

#include<iostream>
#include<cmath>

using std::cout;
using std::cin;
using std::endl;

char input;
float reading;
float max;
float tempCount;




class LList 
{
private:
	struct node
	{
		float value;							// linked list initialization
		node* next;
	};
	node* head;
	node* curr;
	node*  tail;
	int count;
	void init()
	{
		//curr = NULL;
		//tail = NULL;
		//head = NULL;
		curr = tail = head = NULL;				//constructor helper
		count = 0;
	}
		
public:
	
	LList();
	void AddNode(float data);
	void PrintDay();
	void PrintWeek();
	//void UI();
	float Max();
	float listSum();
	
	
	
};

LList::LList()				//constructor
{
	/*head = NULL;
	curr = NULL;
	temp = NULL;*/
	init();
	
}


void LList::AddNode(float data)
{
	node* ptr = new node;		// creating a new node pointer called ptr which points to a new node
	//ptr->next = NULL;			// makes this the last node in the list which points to NULL
	ptr->value = data;			// the data that is passed into this function by the variable data is stored in value
	//ptr->next = NULL;
	ptr->next = NULL;							
	//head = ptr;
	if (head == NULL)
	{
		head = ptr;				// if the list is empty
		tail = head;			// sets head be the first element in the list 
								// and sets tail to be equal to the first element 
	}
	else
	{
		tail->next = ptr;		// points the tail->next to a new node
		tail = ptr;				//sets the tail to the new node which is the last node
		
	}
	count++;					// keeps track of the number of valid inputs
	tempCount = count;
	 
}

float LList::Max()				// a function that determines the highest value input for the current week
{
	curr = head;
	while (curr != NULL)
	{
		if (max < curr->value)
		{
			max = curr->value;
		}
		else
		{
			curr = curr->next;
		}
	}
	return max;
}


void LList::PrintDay()					// prints the current day's summary
{
	//listSum();
	curr = head;
	cout << "The current days summary is: [ " << curr->value;		//Iterates thourgh the list printing out each element in the list
	curr = curr->next;
	while (curr != NULL)
	{
		cout << "," << curr->value;
		curr = curr->next;
		
	}
	cout << " ]" << endl;
	cout << "The number of inputs for the current day is: " << count << endl;
	cout << "The max input for the day is: " << Max() << endl;
	cout << "The sum of all inputs for the current day is: " << listSum() << endl;

}




/*void LList::PrintWeek()
{
	curr = head;
	cout << "The current weeks summary is: [ " << curr->value;		//Iterates thourgh the list printing out each element in the list
	curr = curr->next;
	while (curr != NULL)
	{
		cout << "," << curr->value;
		curr = curr->next;

	}
	cout << " ]" << endl;
	cout << "The number of inputs for the current week is: " << (arraylists[0].count + arraylists[dayCounter].count) << endl;
	
}

void LList::UI()
{
	while (!(finished))																								//Inspired by code written by 
	{																												//Brandon Labuschange
		cout << "\nPlease make a selection." << endl;																		//https://www.youtube.com/watch?v=U-MfAoL6qjM
		
		cout << "\n'1': To input a blood sugar reading for the current day" << endl;
		cout << "\n'D' or 'Day': To see the current days summary" << endl;
		cout << "\n'W' or 'Week': To see the current weeks summary" << endl;
		cout << "\n'N' or 'Next': To move to the next day" << endl;
		cout << "\n'E' or 'Exit': To Quit" << endl;
		cin >> input;
		
		switch (input)
		{ 
		case '1':	cout << "Please enter a blood sugar reading." << endl;
			cin >> reading;
			if (reading > 0)
			{															// controls the input to greater than 0
				AddNode(reading);										// input less than or equal to 0 are silently ignored
				//Print();
			}
			else
			{
				cin.clear();
				cin.ignore();
			}
			
			finished = false;
			break;
			
		case 'D':
		case'd':
		case'Day':
		case'day':

			
			finished = false;
			break;

		case 'N':
		case'n':
		case 'Next':
		case 'next':
			dayCounter++;
			finished = false;
			break;

		case 'E':
		case'e':
		case'Exit':
		case'exit':
			
			cout << "System exit" << endl;
			finished = true;
			break;
		default: 
			finished = true;
		}
	}
}
	*/

#endif
