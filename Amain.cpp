#include "Date.h"
#include "StringTokenizer.h"
#include "Assignment.h"
#include <fstream>
#include <list>
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

void add(Assignment assignment, list<Assignment>& the_list, list<Assignment>::iterator& iter) // Add assignment to a list
{
<<<<<<< HEAD
	if (assignment.getDueDate() > assignment.getAssignedDate()) // If assignment dates make sense
	{
        for (iter = the_list.begin(); iter != the_list.end(); iter++)
		{
		    if (*iter == assignment) // Same assignment already in list; don't add
			{
			    cout << "Assignment already in list" << endl;
			}
		}
		the_list.push_back(assignment); // Assignment added to assigned list
		// Sort method here?		
	}
	else
	{
	    cout << "Assignment due date before or on assigned date" << endl;
	}
=======
	the_list.push_back(assignment);
	//Sort method here?
		//No, would cause in infinite loop because I call this function in the sort function. -KD
>>>>>>> origin/master
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

Assignment createAssignment(string& assign_str) // Create an Assignment out of a string
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

int main()
{
	ifstream fin; 
	ofstream fout;
	list<Assignment> assigned_list; // List for assigned
	list<Assignment> completed_list; // List for completed
	list<Assignment>::iterator assigned_iter;
	list<Assignment>::iterator completed_iter;
	int choice; // Display options
	int late_count = 0; // Count number of late assignments
	char y_or_n; // For assignment file prompt
	string file_to_read; // File to read in

	cout << "Do you want a file of assignments to be read? (Y/N)" << endl;
	cin >> y_or_n;
	if (toupper(y_or_n) == 'Y')
	{
		cout << "Type in the file name: " << endl;
		cin >> file_to_read;
		fin.open(file_to_read);
		if (fin.fail()) // If file failed to open/does not exist
		{
			exit(1);
		}
		string line;
		while (getline(fin, line)) // While a line is being read in
		{
			Assignment assignment = createAssignment(line);
			if (assignment.getStatus() == Assigned)
			{
				add(assignment, assigned_list, assigned_iter); // Try adding to assigned list
			}
			else if (assignment.getStatus() == Completed || assignment.getStatus() == Late) 
			{
				add(assignment, completed_list, completed_iter); // Try adding to completed list
			}
			else
			{
				add(assignment, assigned_list, assigned_iter); // Add to assigned by default without proper stat info
			}
		}
	}
	
	fin.close();
	fout.open("out_assignment.txt"); // Create a file to be written to

	// Options display
	while (choice != 6) // 6 is choice "quit"
	{
	    cout << "What would you like to do? (Enter a number.)" << endl;
	    cout << "1 Display current assignments" << endl;
	    cout << "2 Add assignment" << endl;
	    cout << "3 Complete assignment" << endl;
	    cout << "4 Edit assignment" << endl;
	    cout << "5 Count late assignments" << endl;
	    cout << "6 Quit" << endl;

		cin >> choice;

		switch (choice) 
		{
		case 1: // Display all assignments
			cout << "Assigned assignments: " << endl;
			for (assigned_iter = assigned_list.begin(); assigned_iter != assigned_list.end(); assigned_iter++)
			{
				cout << *assigned_iter << " "; 
			}
			cout << endl;
			cout << "Completed assignments: " << endl;
			for (completed_iter = completed_list.begin(); completed_iter != completed_list.end(); completed_iter++)
			{
				cout << *completed_iter << " "; 
			}
			cout << endl;
			break;
		case 2: // Add an assignment to either the assigned or completed list
			{
			string str_assign;
			cout << "Type an assignment: " << endl;
			cin >> str_assign;
			Assignment assignment = createAssignment(str_assign);
			if (assignment.getStatus() == Assigned)
			{
				add(assignment, assigned_list, assigned_iter); // Try adding to assigned list
			}
			else if (assignment.getStatus() == Completed || assignment.getStatus() == Late) 
			{
				add(assignment, completed_list, completed_iter); // Try adding to completed list
			}
			else
			{
				add(assignment, assigned_list, assigned_iter); // Add to assigned by default without proper stat info
			}
			break;
			}
		case 3: // Complete an assignment
			{
			try
			{
			    string assigned;
			    cout << "Type in the assigned date: " << endl;
			    cin >> assigned;
			    Date assignedDate(assigned); // Possible exception here
			    for (assigned_iter = assigned_list.begin(); assigned_iter != assigned_list.end(); assigned_iter++)
			    {
				    if (assigned_iter->getAssignedDate() == assigned) // If assignment is found, complete it
				    {
					    string completed;
					    cout << "Type in the completion date: " << endl;
					    cin >> completed;
					    Date completedDate(completed);
					    if (assigned_iter->getDueDate() < completedDate) // If the completed date is after due date...
					    {
						    assigned_iter->setStatus(Late); // ...It is late
							late_count++; 
					    }
						else
						{
							assigned_iter->setStatus(Completed); // Otherwise it is simply completed
						}
						add((*assigned_iter), completed_list, completed_iter); // Add to completed list
						remove((*assigned_iter), assigned_list); // Remove from assigned list
					    break;
				    }
			    }
			}
			catch (exception& e)
			{
				cout << e.what() << endl;
				continue;
			}
			break;
			}
		case 4: // Edit assignment
			{
			try
			{
			    string assigned;
			    cout << "Type in the assigned date: " << endl;
			    cin >> assigned;
			    Date assignedDate(assigned); // Possible exception here
			    for (assigned_iter = assigned_list.begin(); assigned_iter != assigned_list.end(); assigned_iter++)
			    {
				    if (assigned_iter->getAssignedDate() == assigned) // If assignment is found, edit it
				    {
			
						char yes_no; 
					    cout << "Edit the due date? (Y/N)" << endl;
					    cin >> yes_no;

                        if (toupper(yes_no) == 'Y')
						{
							string newDue;
							cout << "Type in the new due date: " << endl;
							cin >> newDue;
							Date newDueDate(newDue);
							assigned_iter->setDueDate(newDueDate); // New due date set
						}

						cout << "Edit the description? (Y/N)" << endl;
						if (toupper(yes_no) == 'Y')
						{
							string describe;
							cout << "Type in the new description: " << endl;
							cin >> describe;
							assigned_iter->setDesc(describe); // New description set
						}
					    break;
				    }
			    }
			}
			catch (exception& e)
			{
				cout << e.what() << endl;
				continue;
			}
			break;
			}
			
		case 5: // Count late assignments
			cout << "There are " << late_count << " late assignments" << endl;
			break;
		case 6: // Quit program
			continue;
		default: 
			continue;
		}
	}
	// Save all assignment data in each list in the write-out file
	fout << "Incomplete Assignments" << endl;
	fout << "----------------------" << endl;
	for (assigned_iter = assigned_list.begin(); assigned_iter != assigned_list.end(); assigned_iter++)
	{
		fout << (*assigned_iter) << endl;
	}
	fout << endl;
	fout << "Completed Assignments" << endl;
	fout << "---------------------" << endl;
	for (completed_iter = completed_list.begin(); completed_iter != completed_list.end(); completed_iter++)
	{
		fout << (*assigned_iter) << endl;
	}

	fin.close();
	fout.close();
	return 0;
}