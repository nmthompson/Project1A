#pragma once
#include <string>
#include "Date.h"

struct Node
{
	Node* next;
	Node* prev;
	Assignment Data;
	
};


class Assignment
{
public:
	Assignment(int status, string desc, Date due, Date assigned);
	string getDesc(){ return desc; }
	Date getDueDate(){ return due; }
	int getStatus(){ return status; }
	void setDesc(string descr){ desc = descr; }
	void setDueDate(Date dueWhen){ due = dueWhen; }
	void setStatus(int SetStatus){ status = SetStatus; }

private:
	int status; // 1: assigned 2: completed 3: late
	string desc;
	Date due;
	Date assigned;
};