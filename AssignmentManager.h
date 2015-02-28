#pragma once
#include "Assignment.h"
#include "Date.h"
#include <list>

using namespace std;

class AssignmentManager
{
public:
	Assignment createAssignment(string& assign_str); // Creates an assignment from a string
	void add(Assignment assignment, list<Assignment>& the_list); // Tries to add an assignment to a list
	void remove(Assignment& assignment, list<Assignment>& the_list); // Removes an assignment from a list
};