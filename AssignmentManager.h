#pragma once
#include "Assignment.h"

//Function prototypes
status statConvert(string& str);
string strConvert(status& stat);
ostream& operator <<(ostream& out, Assignment& rhs);

class AssignmentManager
{
public:
    // Initializes the number of late assignments to 0 and changes to assignment lists to false
    AssignmentManager() {late_count = 0, lists_change = false;}
    Assignment createAssignment(string& str); // Creates an assignments from a string

    // Tries to add an assignment to a list
    void add(Assignment& assignment, list<Assignment>& the_list, list<Assignment>::iterator& iter); 
    void remove(Assignment& assignment, list<Assignment>& the_list); // Removes an assignment from a list
    // Manage the display of a list of assignments
    void displayList(list<Assignment>& the_list, list<Assignment>::iterator& iter, string type_assign);
    // Complete an assignment
    void complete(list<Assignment>& the_list, list<Assignment>& comp_list, list<Assignment>::iterator& iter); 
    void edit(list<Assignment>& the_list, list<Assignment>::iterator& iter); // Edit an assignment

    int& getLateCount() {return late_count;} // Gets the current total number of late assignments
    bool& madeChanges() {return lists_change;} // Shows if changes have been made to the lists
    void resetChanges() {lists_change = false;} // After saving the changes, indicates that no new changes have been made yet

private:
    int late_count;
    bool lists_change; // Whenever the add function is called and an assignment is successfully added to a list, a
                       // change has been made to the list and list_change is true
                       // Reset to false when data has been saved to a file
};