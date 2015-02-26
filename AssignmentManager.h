#pragma once
#include "Assignment.h"
#include <list>

using namespace std;

class AssignmentManager
{
public:
	Assignment createAssignment(string& assign_str);
	void add(Assignment assignment, list<Assignment>& the_list);
	void remove(Assignment& assignment, list<Assignment>& the_list);


};