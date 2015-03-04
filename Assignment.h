#pragma once
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include "Date.h"

using namespace std;

enum status { Assigned, Completed, Late };

class Assignment
{
public:
	Assignment(string desc, Date due, Date assigned, status status = Assigned)
	{
			description = desc;
			dueDate = due;
			assignedDate = assigned;
			assignmentStatus = status;
	}
	Assignment(string desc, Date due, Date assigned, Date completed, status status = Assigned)
	{
		description = desc;
		dueDate = due;
		assignedDate = assigned;
		assignmentStatus = status;
		completedDate = completed;
	}
    string getDesc()const{ return description; }
    Date getAssignedDate()const{ return assignedDate; }
    Date getDueDate()const{ return dueDate; }
    Date getCompletedDate()const{ return completedDate; }
    status getStatus()const{ return assignmentStatus; }
    void setDesc(string descriptionr){ description = descriptionr; }
    void setDueDate(Date dueDateWhen){ dueDate = dueDateWhen; }
    void setCompletedDate(Date done){completedDate = done; }
    void setStatus(status SetStatus){ assignmentStatus = SetStatus; }
    
    string dateString(Date& date){ // Convert date to a string for printing
        return date.toString();
    }

    bool isCompleted(){ // Checks to see if the assignment has a completed or late status
        if ((assignmentStatus == Completed) || (assignmentStatus == Late)){
            return true;
        }
        else{
            return false;
        }
    }

    bool operator <(const Assignment& other) const { // Compare one assignment dueDate date with another for use in sorting an assignment list
        if (getDueDate() < other.getDueDate()){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool operator ==(const Assignment& other) const { // See if two assignments are equal; if they are, one needs to be discarded
        return (getDueDate() == other.getDueDate() ); //Due date is a uniqe identifier 
    }
    
    bool operator <=(const Assignment& other) const { // See if two assignments have a greater than or equal relationship
        return ((*this) < other || (*this) == other);
    }

private:
    status assignmentStatus; 
    string description;
    Date dueDate;
    Date assignedDate;
    Date completedDate;
};