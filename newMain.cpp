#include "Date.h"
#include "StringTokenizer.h"
#include "Assignment.h"
#include "UserInterface.h"
#include <fstream>
#include <list>
#include <iostream>
using namespace std;

// Doubly linked list insertion sort method //
 

void iSort(list<Assignment>& the_list)
{
	list<Assignment>::iterator iter;
	list<Assignment>::iterator _iter;
	Assignment temp;
	Assignment nextTemp;
	for (_iter = the_list.begin(); _iter != the_list.end(); _iter++)
	{
		iter = _iter; //Keeps the inside loop on track and lets us go back to where we left off if
					  //something was out of order and we had to take it back to recorrect it.
		if (iter->getAssignedDate() > iter++->getAssignedDate())
		{
			temp = *iter;
			nextTemp = *iter++;
			remove(*iter, the_list);
			while (temp.getAssignedDate() > iter++->getAssignedDate()) //Something is wrong here
			{
				iter--;
				if (iter == the_list.begin()) //If the assignment is the earliest assigned on we have seen so far.
					break;
			}
			add(temp, the_list);
		}	
	}
}

// Tring out the pre built sort function for the list class
// the_list.sort(compare_date);
bool compare_date(Assignment &A, Assignment &B)
{
	if (A.getAssignedDate() > B.getAssignedDate())
		return false;
	else if (A.getAssignedDate < B.getAssignedDate())
		return true;
}
//////////////////////////////////////////

void add(Assignment assignment, list<Assignment>& the_list) // Add assignment to a list
{
	the_list.push_back(assignment);
	//Sort method here?
		//No, would cause in infinite loop because I call this function in the sort function. -KD
}

void remove(Assignment& assignment, list<Assignment>& the_list) // Remove assignment from list 
{
	the_list.remove(assignment);
	//Don't call sort here, for the same reason ass the add function. -KD
}

bool& operator ==(Assignment& lhs, Assignment& rhs) // Used for determining equality of assignments
{
	bool equal;
	equal = (lhs.getAssignedDate() == rhs.getAssignedDate() && lhs.getDesc() == rhs.getDesc() && 
		lhs.getDueDate() == rhs.getDueDate() && lhs.getStatus() == rhs.getStatus());
	return equal;
}

ostream& operator <<(ostream out, Date& out_date) // Stream out the display data of a Date
{
	out << out_date.getMonth() << "-" << out_date.getDay() << "-" << out_date.getYear();
	return out;
}

ostream& operator <<(ostream& out, Assignment& out_assign) // Stream out the display data of an Assignment
{
	out << out_assign.getDueDate() << out_assign.getDesc() << out_assign.getAssignedDate() << out_assign.getStatus();
    return out;  
}

int main()
{

	int choice;
	cout << "Please select what you would like to do: " << endl;
	cin >> choice;
	UserInterface.uiLoop(choice); //no idea the syntax for C++ for executing an external class with a parameter. 
									//java it's create an object of the class and then pass it a parameter to the desired function.

	
	
	return 0;
}
