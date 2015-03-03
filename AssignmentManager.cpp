#include "AssignmentManager.h"

ostream& operator <<(ostream& out, Assignment& rhs) { // Stream out the display data of an Assignment
	status stat = rhs.getStatus();
	if ((!rhs.isCompleted())) { // If assignment is not completed, don't try to print out the (nonexistent) 
		// completion date
		out << rhs.dateString(rhs.getDueDate()) << rhs.getDesc() << rhs.dateString(rhs.getAssignedDate())
			<< strConvert(stat);
		return out;
	}
	out << rhs.dateString(rhs.getDueDate()) << rhs.getDesc() << rhs.dateString(rhs.getAssignedDate())
		<< rhs.dateString(rhs.getCompletedDate()) << strConvert(stat);
	return out;
}

status statConvert(string& str){ // Convert status string to status type
	try{

		if (str == "assigned" || str == "Assigned"){
			return Assigned;
		}
		else if (str == "completed" || str == "Completed"){
			return Completed;
		}
		else if (str == "late" || str == "Late"){
			return Late;
		}
		else{
			throw exception("THE ASSIGNMENT STATUS IS NOT VALID\n");
		}
	}
	catch (const exception& e){ // Error caught; the status isn't valid
		cout << e.what();
	}
}

string strConvert(status& stat){ // Convert a stat back into a string for printing
	if (stat == Assigned){
		return "assigned";
	}
	else if (stat == Completed){
		return "completed";
	}
	else {
		return "late";
	}
}

Assignment AssignmentManager::manualCreate(){ // Create an Assignment out of a string
	string due, descript, assigned, stat_str;
	
	cout << "Enter the assignment's description." << endl;
	getline(cin, descript);
	cout << "Enter the assignment's assigned date. (MM-DD-YEAR)" << endl;
	getline(cin, assigned);
	cout << "Enter the assignment's due date. (MM-DD-YEAR)" << endl;
	getline(cin, due);
	cout << "Enter the assignment's status. (Assigned, Late, Completed)" << endl;
	getline(cin, stat_str);

	statConvert(stat_str); // Convert status to status type 

	try{ // Try block needed to throw exception for any invalid dates
		Date dueDate(due, US); // Create due date out of a string in US format
		Date assignDate(assigned, US); // Create assigned date out of a string in US format

		Assignment assignment(descript, dueDate, assignDate);
		return assignment;
	}
	catch (const exception& e){
		cout << e.what() << endl; // Prints "invalid date"
	}
}

Assignment AssignmentManager::createAssignment(string& str){ // Create an Assignment out of a string
    String_Tokenizer parse_assign(str, ", "); // Create tokenizer for splitting assignment data

    string due, descript, assigned, stat_str;
    due = parse_assign.next_token();
    descript = parse_assign.next_token(); //If there is a space in the desc of an assignment it will take the first word as the desc then the sec will get saved to assigned
    assigned = parse_assign.next_token(); //throwing off all our data.
    stat_str = parse_assign.next_token();
    statConvert(stat_str); // Convert status to status type 
    
    try{ // Try block needed to throw exception for any invalid dates
        Date dueDate(due, US); // Create due date out of a string in US format
        Date assignDate(assigned, US); // Create assigned date out of a string in US format

        Assignment assignment(descript, dueDate, assignDate);
        return assignment;
    }
    catch (const exception& e){
        cout << e.what() << endl; // Prints "invalid date"
    }
}



void AssignmentManager::add(Assignment& assignment, list<Assignment>& the_list, list<Assignment>::iterator& iter){ 
    // Adds an assignment to a list
	list<Assignment>::reverse_iterator r_iter;
    if (the_list.size() != 0)
    {
		for (r_iter = the_list.rbegin(); r_iter != the_list.rend(); ++r_iter)
        {
            if (assignment >= (*r_iter)){ // If the assignment being added is greater than assignment being pointed to in the list, add it after
                                      // the assignment being pointed to
                if (!(assignment == (*r_iter))) // If the assignment being added is not a duplicate, add it
                {
                    r_iter++; // Increment the iterator to add the assignment to place after the one it was compared to
					iter = (r_iter+1).base;
                    the_list.insert(iter, assignment); // Insert the assignment at the iterator's position
                    break;
                }
            }
        }
    }
	else if (the_list.size() == 0)
	{
		the_list.push_back(assignment);
	}
}

void AssignmentManager::remove(Assignment& assignment, list<Assignment>& the_list){ // Removes an assignment from a 
                                                                                    // given list 
    the_list.remove(assignment);
}

// Displays assignments from a list
void AssignmentManager::displayList(list<Assignment>& the_list, list<Assignment>::iterator& iter, string type_assign){
		
    cout << type_assign << " assignments: " << endl;
    for (iter = the_list.begin(); iter != the_list.end(); iter++)
    {
        cout << (*iter) << " "; 
    }
    cout << endl;
}

// Completes an assignment in a list
void AssignmentManager::complete(list<Assignment>& the_list, list<Assignment>& comp_list, 
    list<Assignment>::iterator& iter){
    try{
        string assigned;
        cout << "Type in the assigned date: " << endl;
        cin >> assigned;
        Date assignedDate(assigned); // Possible exception here
        for (iter = the_list.begin(); iter != the_list.end(); iter++)
        {
            if (iter->getAssignedDate() == assigned){ // If assignment is found, complete it
                string completed;
                cout << "Type in the completion date: " << endl;
                cin >> completed;
                Date completedDate(completed);
                if (iter->getDueDate() < completedDate){ // If the completed date is after due date...
                    iter->setStatus(Late); // ...It is late
                    late_count++; 
                }
                else{
                    iter->setStatus(Completed); // Otherwise it is simply completed
                }
                add((*iter), comp_list, iter); // Add to completed list
                remove((*iter), the_list); // Remove from assigned list
                lists_change = true; // A change has been made to one or both lists
                break;
            }
        }
    }
    catch (exception& e){
        cout << e.what() << endl;
    }
}

// Edit an assignment in a list
void AssignmentManager::edit(list<Assignment>& the_list, list<Assignment>::iterator& iter){
    try{
        string assigned;
        cout << "Type in the assigned date: " << endl;
        cin >> assigned;
        Date assignedDate(assigned); // Possible exception here
        for (iter = the_list.begin(); iter != the_list.end(); iter++)
        {
            if (iter->getAssignedDate() == assigned) // If assignment is found, edit it
            {
                char yes_no; 
                cout << "Edit the due date? (Y/N)" << endl;
                cin >> yes_no;

                if (toupper(yes_no) == 'Y'){
                    string newDue;
                    cout << "Type in the new due date: " << endl;
                    cin >> newDue;
                    Date newDueDate(newDue);
                    iter->setDueDate(newDueDate); // New due date set
                }
                cout << "Edit the description? (Y/N)" << endl;
                if (toupper(yes_no) == 'Y'){
                    string describe;
                    cout << "Type in the new description: " << endl;
                    cin >> describe;
                    iter->setDesc(describe); // New description set
                }
                lists_change = true; // A change has been made to the assigned list
                break;
             }
        }
    }
    catch (exception& e){
        cout << e.what() << endl;
    }
}

