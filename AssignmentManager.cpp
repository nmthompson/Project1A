#include "AssignmentManager.h"
#include "StringTokenizer.h"
using namespace std;

Assignment AssignmentManager::createAssignment(string& assign_str){ // Create an Assignment out of a string
    String_Tokenizer parse_assign(assign_str, ", "); // Create tokenizer for splitting assignment data

	string due, descript, assigned, stat_str;
	status the_stat;
    due = parse_assign.next_token();
    descript = parse_assign.next_token();
	assigned = parse_assign.next_token();
	stat_str = parse_assign.next_token();
	Status::statConvert(stat_str); // Convert status to status type 
	
	try{ // Try block needed to throw exception for any invalid dates
	    Date dueDate(due, US); // Create due date out of a string in US format
	    Date assignDate(assigned, US); // Create assigned date out of a string in US format

	    Assignment assignment(descript, dueDate, assignDate);
		return assignment;
	}
	catch (const exception& e)
	{
	    cout << e.what() << endl; // Prints "invalid date"
	}
}

void AssignmentManager::add(Assignment assignment, list<Assignment>& the_list){ // Adds an assignment to a list
	list<Assignment>::iterator iter;
	if (the_list.size() != 0)
	{
		for (iter = the_list.end(); iter != the_list.begin(); iter--)
		{
			if (assignment >= (*iter)){ // If the assignment being added is greater than assignment being pointed to in the list, add it after
				                      // the assignment being pointed to
	            if (!(assignment == (*iter))) // If the assignment being added is not a duplicate, add it
			    {
				    iter++; // Increment the iterator to add the assignment to place after the one it was compared to
				    the_list.insert(iter, assignment); // Insert the assignment at the iterator's position
				    break;
			    }
			}
		}
	}
}

void AssignmentManager::remove(Assignment& assignment, list<Assignment>& the_list) // Removes an assignment from a given list 
{
	the_list.remove(assignment);
}