#pragma once
#include <list>
#include <iostream>
#include <fstream>
#include "Date.h"
#include "StringTokenizer.h"
#include <string>

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
        throw exception("The assignment status is not valid");
    }
    } 
    catch(const exception& e){ // Error caught; the status isn't valid
        return Assigned;
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


class Assignment
{
public:
    Assignment(string desc, Date due, Date assigned, status s = Assigned){}
    string getDesc()const{ return desc; }
    Date getAssignedDate()const{ return assigned; }
    Date getDueDate()const{ return due; }
    Date getCompletedDate()const{ return completed; }
    status getStatus()const{ return s; }
    void setDesc(string descr){ desc = descr; }
    void setDueDate(Date dueWhen){ due = dueWhen; }
    void setCompletedDate(Date done){completed = done; }
    void setStatus(status SetStatus){ s = SetStatus; }
    
    string dateString(Date& date){ // Convert date to a string for printing
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

    bool operator >(const Assignment& other) const { // Compare one assignment due date with another for use in sorting an assignment list
        if (getDueDate() > other.getDueDate()){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool operator ==(const Assignment& other) const { // See if two assignments are equal; if they are, one needs to be discarded
        return (assigned == other.getAssignedDate() && desc == other.getDesc() &&
            due == other.getDueDate() && s == other.getStatus()); // May not need the "this" pointer
    }
    
    bool operator >=(const Assignment& other) const { // See if two assignments have a greater than or equal relationship
        return ((*this) > other || (*this) == other);
    }

private:
    status s; 
    string desc;
    Date due;
    Date assigned;
    Date completed;
};