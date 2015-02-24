#pragma once
#include <string>
#include <iostream>
#include "Date.h"

enum status {Assigned, Completed, Late};

status statConvert(string& str) // Convert status string to status type
{
	if (str == "assigned")
	{
        return Assigned;
	}
	else if (str == "completed")
	{
        return Completed;
	}
	else if (str == "late")
	{
	    return Late;
	}
	else
	{
	   return Assigned; // Assumes invalid status value is Assigned
	}
}

class Assignment
{
public:
	Assignment(string desc, Date due, Date assigned, status s = Assigned){}
	Assignment(){ s = Assigned; desc = ""; due = NULL; assigned = NULL; completed = NULL; }
	string getDesc(){ return desc; }
	Date getAssignedDate() { return assigned; }
	Date getDueDate(){ return due; }
	Date getCompletedDate(){ return completed; }
	status getStatus(){ return s; }
	void setDesc(string descr){ desc = descr; }
	void setDueDate(Date dueWhen){ due = dueWhen; }
	void setCompletedDate(Date done){completed = done; }
	void setStatus(status SetStatus){ s = SetStatus; }

private:
	status s; 
	string desc;
	Date due;
	Date assigned;
	Date completed;
};