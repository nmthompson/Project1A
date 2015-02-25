#include "Date.h"
#include "StringTokenizer.h"
#include "Assignment.h"
#include "UserInterface.h"
#include <fstream>
#include <list>
#include <iostream>

using namespace std;

list<Assignment> assigned_list; // List for assigned
list<Assignment> completed_list; // List for completed

list<Assignment>::iterator assigned_iter;
list<Assignment>::iterator completed_iter;

int late_count = 0;

void::fileRead(char y_or_n){

}

void::uiLoop(int choice){
	ifstream fin; 
	ofstream fout;

	fin.open("assingment.txt"); 
	if (fin.fail()) // If file can't be opened
	{
	    exit(1);
	}
	fout.open("out_assignment.txt"); // Create a file to be written to

	while (choice != 7) // 7 is choice "quit"
	{
	    cout << "What would you like to do? (Enter a number.)" << endl;
	    cout << "1 Display current assignments" << endl;
	    cout << "2 Add assignment" << endl;
	    cout << "3 Complete assignment" << endl;
	    cout << "4 Edit assignment" << endl;
	    cout << "5 Count late assignments" << endl;
	    cout << "6 Save and Output" << endl;
		cout << "7 Quit" << endl;

		cin >> choice;

		switch (choice) 
		{
		case 1: // Display all assignments
			cout << "Assigned assignments: " << endl;
			for (assigned_iter = assigned_list.begin(); assigned_iter != assigned_list.end(); assigned_iter++)
			{
				cout << *assigned_iter << " "; 
			}
			cout << "Completed assignments: " << endl;
			for (completed_iter = completed_list.begin(); completed_iter != completed_list.end(); completed_iter++)
			{
				cout << *completed_iter << " "; 
			}
			break;
		case 2: // Add an assignment to either the assigned or completed list
			{
			string str_assign;
			cout << "Type an assignment: " << endl;
			cin >> str_assign;
			String_Tokenizer parse_assign(str_assign, ", "); // Create tokenizer for splitting assignment data

			string due, descript, assigned, stat_str;
			due = parse_assign.next_token();
			descript = parse_assign.next_token();
			assigned = parse_assign.next_token();
			stat_str = parse_assign.next_token();
			// Create Dates out of strings
			try // Try block needed to throw exception for any invalid dates
			{
			    Date dueDate(due); 
			    Date assignDate(assigned);

			    Assignment assignment(descript, dueDate, assignDate);
				if (assignment.getDueDate() > assignment.getAssignedDate()) // If assignment dates make sense
				{

					for (assigned_iter = assigned_list.begin(); assigned_iter != assigned_list.end(); 
					    assigned_iter++)
					{
					    if (*assigned_iter == assignment) // Same assignment already in list; don't add
						{
							cout << "Assignment already in list" << endl;
							continue;
						}
					}
					add(assignment, assigned_list); // Assignment added to assigned list
					
				}
				else
				{
				    cout << "Assignment dates don't make sense" << endl;
					continue;
				}
			}
			catch (const exception& e)
			{
				cout << e.what() << endl; // Prints "invalid date"
				continue; // Will the program continue past this exception handle?
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
						add((*assigned_iter), completed_list); // Add to completed list
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
		case 6: //Save and output the code
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
		case 7: // Quit program
			continue;
		default: 
			continue;
		}
	}

	
}