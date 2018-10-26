//Chance McCormick
//Cosc 2030
//Project 1- Blood sugar
//10/11/2018

#include "BloodSugar.h"

bool finished = false;
int dayCounter = 0;
LList arraylists[14];
//LList listSum[];
float tempValue = 0;

int overflowCount = 0;



void LList::PrintWeek()							// prints the current week's summary
{
	int diff = 0;
	int diff3 = 0;
	
	curr = head;
	cout << "The current weeks summary is: [ " << curr->value;		//Iterates thourgh the list printing out each element in the list
	
	curr = curr->next;
	if (dayCounter <= 6)										// tests for 1st week 
	{
		
		for (int i = 0; i <= dayCounter; i++)					
		{
			//if (i < 6)
			//{
			
				int c1 = arraylists[i].count;
				int c2 = arraylists[i+1].count;
				int diff1 = abs(c2 - c1);

				if (diff1 > diff)
				{
					diff = diff1;
					c1 = c2;
				}
				

			//}
			while (curr != NULL)
			{

				cout << "," << curr->value;
				curr = curr->next;


			}
			
		}
		cout << " ]" << endl;
		cout << "The max input for the week is: " << Max() << endl;
		cout << "The number of inputs for the current week is: " << count << endl;
		cout << "The sum of all inputs for the current week is: " << listSum() << endl;
		cout << "The biggest day to day delta is: " << diff << endl;
	}
	if (dayCounter > 6)								// tests for second week
	{
		
		for (int i = 7; i <= dayCounter; i++)		// iterates through the arra list data
		{
			
			int c3 = arraylists[i].count;
			int c4 = arraylists[++i].count;
			int diff4 = abs(c4 - c3);
			if (diff4 > diff3)
			{
				diff3 = diff4;
				c3 = c4;
			}



			while (curr != NULL)
			{

				cout << "," << curr->value;
				curr = curr->next;


			}
		}
		cout << " ]" << endl;
		cout << "The max input for the week is: " << Max() << endl;
		cout << "The number of inputs for the current week is: " << count << endl;
		cout << "The sum of all inputs for the current week is: " << listSum() << endl;
		cout << "The biggest day to day delta is: " << diff3 << endl;

	}
	/*cout << " ]" << endl;
	cout << "The max input for the week is: " << Max() << endl;
	cout << "The number of inputs for the current week is: " << count << endl;
	cout << "The sum of all inputs for the current week is: " << listSum() << endl;*/
}

float LList::listSum()
{
	//listSum();
	float listsum = 0;
	
	curr = head;

		for (curr = head; curr != NULL; )
		{
			if (curr->value < (FLT_MAX - listsum))						// tests if adding the next element will cause an overflow
			{
				listsum = curr->value + listsum;						// if not then listsum is the sum of the curr value in the list + listsum
			}
			//  overflowing a float with just summation will be really hard, this is here if by chance it does.
			else
			{
				overflowCount++;										// keeps track of the number of times an overflow occurs
				tempValue = curr->value - (FLT_MAX - listsum);			// sets a tempvalue to the value left over after overflow happens
				listsum = tempValue;									// sets listsum to the tempvalue 
				
			}
			curr = curr->next;											// iterates to the next element
		}

		return listsum;
}

	/*curr = head;
	
	

		while (curr != NULL)
		{
			for (curr = head; curr != NULL; curr = curr->next)		// this block of codes correctly returns a value for sum
			{														// but does not test for overflow
				sum = sum + curr->value;

			}
		}*/


		//return sum;						

	
	
//}


int main()
{
	LList Bloodreading;
	
	
	
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
		case '1':	cout << "\nPlease enter a blood sugar reading." << endl;
			cin >> reading;
			if (reading > 0)
			{															// controls the input to greater than 0
				Bloodreading.AddNode(reading);										// input less than or equal to 0 are silently ignored
				//Print();
				arraylists[dayCounter].AddNode(reading);
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
			arraylists[dayCounter].PrintDay();

			finished = false;
			break;

		case 'N':
		case'n':
		case 'Next':
		case 'next':
			dayCounter++;						// tracks the number of days
			finished = false;
			break;

		case 'W':
		case'w':
		case'Week':
		case'week':
					
			Bloodreading.PrintWeek();
			
			

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

	system("pause");
	return 0;
}



