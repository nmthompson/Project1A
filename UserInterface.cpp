#include "UserInterface.h"
#include <fstream>
#include <list>
list<Assignment> assigned_list; // List for assigned assignments
list<Assignment> completed_list; // List for completed assignments
list<Assignment>::iterator assigned_iter; // Iterators for assigned and completed lists moved to global 
list<Assignment>::iterator completed_iter;
AssignmentManager manager; // Manager of the assignments and their lists


void UserInterface::fileRead(){
     // File to read in
	
    std::cout << "Type in the file name: " << endl;
	cin >> file_to_read;
    ifstream fin;
    fin.open(file_to_read, std::ifstream::in);
        if (fin.fail()) // If file failed to open/does not exist
        {
            exit(1);
        }
        string line;
		if (cin.peek() == '\n'){
			cin.ignore();
		}
        while (getline(fin, line)){ // There's a line that can be read in
            Assignment assignment = manager.createAssignment(line);
            if (assignment.getStatus() == Assigned){
                manager.add(assignment, assigned_list); // Try adding to assigned list
            }
            else if (assignment.getStatus() == Completed){
                manager.add(assignment, completed_list); // Try adding to completed list
            }
			else if (assignment.getStatus() == Late){
				manager.add(assignment, completed_list); // Try adding to completed list
				manager.incrementLateCount();
			}
            else{ // Fix this; maybe throw an exception instead of adding the assignment
                manager.add(assignment, assigned_list); // Add to assigned by default without proper stat info
            }
        }
    fin.close();
}

void UserInterface::uiLoop(){
    ofstream fout;
    int choice = 0;

    fout.open("assignment.txt"); // Create a file to be written to - if the same name as the input file,
                                 // overwrite the input file

    while (choice != 7) // 7 is choice "quit"
    {
        cout << "1 Display current assignments" << endl;
        cout << "2 Add assignment" << endl;
        cout << "3 Complete assignment" << endl;
        cout << "4 Edit assignment" << endl;
        cout << "5 Count late assignments" << endl;
        cout << "6 Save" << endl;
        cout << "7 Quit" << endl;

        cin >> choice;

        switch (choice) 
        {
        case 1: // Display all assignments
            manager.displayList(assigned_list, assigned_iter, "Assigned");
            manager.displayList(completed_list, completed_iter, "Completed");
            break;
        case 2: // Add an assignment to either the assigned or completed list
            {
			Assignment assignment = manager.manualCreate(); // Creates an assignment from user input
            manager.add(assignment, assigned_list); // Manager tries to store the assignment in a list
            break;
            }
        case 3: // Complete an assignment
            {
                manager.complete(assigned_list, completed_list, assigned_iter);
            break;
            }
        case 4: // Edit an assignment
            {
                manager.edit(assigned_list, assigned_iter);
            break;
            }
            
        case 5: // Count late assignments
            cout << "There are " << manager.getLateCount() << " late assignments" << endl;
			break;
        case 6: // Save the assignments to a file
            if (manager.madeChanges()){ // If change has been made to either of the lists, save the data
                fout << "Incomplete Assignments" << endl;
                fout << "----------------------" << endl;
                for (assigned_iter = assigned_list.begin(); assigned_iter != assigned_list.end(); assigned_iter++){
                    fout << (*assigned_iter) << endl;
                }
                fout << endl;
                fout << "Completed Assignments" << endl;
                fout << "---------------------" << endl;
                for (completed_iter = completed_list.begin(); completed_iter != completed_list.end(); completed_iter++){
                    fout << (*completed_iter) << endl;
                }
                manager.resetChanges(); // Now more changes have to be made so we can save again
            }
            else{ // If changes have not been made, don't save the data - it's already been saved
                cout << "Changes have not been made since you last saved" << endl;
            }
			break;
        case 7: // Quit program
            fout.close(); // Close the file we're writing out saved data to
            continue;
        default: 
            continue;
        }
    }
}