#include "AssignmentManager.h"
using namespace std;

Assignment Assignment::createAssignment(string& assign_str) // Create an Assignment out of a string
{
    String_Tokenizer parse_assign(assign_str, ", "); // Create tokenizer for splitting assignment data

	string due, descript, assigned, stat_str;
	status the_stat;
    due = parse_assign.next_token();
    descript = parse_assign.next_token();
	assigned = parse_assign.next_token();
	stat_str = parse_assign.next_token();
	statConvert(stat_str); // Convert status to status type 
	
	try // Try block needed to throw exception for any invalid dates
	{
	    Date dueDate(due); // Create Dates out of strings
	    Date assignDate(assigned);

	    Assignment assignment(descript, dueDate, assignDate);
		return assignment;
	}
	catch (const exception& e)
	{
	    cout << e.what() << endl; // Prints "invalid date"
	}
}

void Assignment::add(Assignment assignment, list<Assignment>& the_list) // Add assignment to a list
{
	list<Assignment>::iterator iter;
	if (the_list.size() != 0)
	{
		for (iter = the_list.end(); iter != the_list.begin(); iter--)
		{
			if (assignment.getAssignedDate() > iter->getAssignedDate())
			{
				iter++;
				the_list.insert(iter, assignment);
				break;
			}
		}
	}
}

void Assignment::remove(Assignment& assignment, list<Assignment>& the_list) // Remove assignment from list 
{
	the_list.remove(assignment);
}