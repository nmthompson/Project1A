#pragma once
#include <string>
#include "Date.h"

enum status{ Assigned, Completed, Late};

struct Node
{
	Node* next;
	Node* prev;
	Assignment Data;
};

class Assignment
{
public:
	Assignment(string desc, Date due, Date assigned, status s = Assigned);
	string getDesc(){ return desc; }
	Date getDueDate(){ return due; }
	Date getAssignedDate() { return assigned; }
	status getStatus(){ return s; }
	void setDesc(string descr){ desc = descr; }
	void setDueDate(Date dueWhen){ due = dueWhen; }
	void setStatus(status SetStatus){ s = SetStatus; }

private:
	status s;
	string desc;
	Date due;
	Date assigned;
};
