#pragma once
#include <string>
#include <iostream>
#include "Date.h"

namespace Status{ // Not sure if we want to put this code in a namespace 

    enum status {Assigned, Completed, Late};
	
    status statConvert(string& str){ // Convert status string to status type
		try{

	        if (str == "assigned"){
                return Assigned;
	        }
	        else if (str == "completed"){
                return Completed;
	        }
	        else if (str == "late"){
	            return Late;
	        }
	        else{
	           throw std::exception("The assignment status is not valid");
	        }
		}
		catch(const exception& e) // Error caught; the status isn't valid
		{
			std::cout << e.what() << endl;
		}
	};
};

class Assignment
{
public:
	Assignment(string desc, Date due, Date assigned, status s = Assigned){}
	string getDesc(){ return desc; }
	Date getAssignedDate() { return assigned; }
	Date getDueDate(){ return due; }
	Date getCompletedDate(){ return completed; }
	status getStatus(){ return s; }
	void setDesc(string descr){ desc = descr; }
	void setDueDate(Date dueWhen){ due = dueWhen; }
	void setCompletedDate(Date done){completed = done; }
	void setStatus(status SetStatus){ s = SetStatus; }

	string dateString(Date date){ // Convert date to a string for printing
		return date.toString();
	}

	bool isCompleted(){ // Checks to see if the assignment has a completed or late status
		if ((s == Completed) || (s == Late)){
			return true;
		}
		else{
			return false;
		}
	}

	bool >(Assignment& other){ // Compare one assignment due date with another for use in sorting an assignment list
		if (this->getDueDate() > other->getDueDate()){
			return true;
		}
		else{
			return false;
		}
	}

	bool operator ==(Assignment& other){ // See if two assignments are equal; if they are, one needs to be discarded
	    return (assigned() == other->getAssignedDate() && desc == other->getDesc() &&
		    due == other->getDueDate() && s == other.getStatus()); // May not need the "this" pointer
    }

	bool operator >=(Assignment& other){ // See if two assignments have a greater than or equal relationship
		return ((*this) > other || (*this) == other))
	}

	ostream operator <<() // Stream out the display data of an Assignment
    {
		if ((!this->isCompleted())) { // If assignment is not completed, don't try to print out the (nonexistent) 
			                          // completion date 
			return << this->dateString(due) << desc << this->dateString(assigned) << s;
		}
	    return << this->dateString(due) << desc << this->dateString(assigned) << dateString(completed) << s;
    }

private:
	status s; 
	string desc;
	Date due;
	Date assigned;
	Date completed;
};