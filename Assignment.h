#include <string>
#include "Date.h"
class Assignment
{
public:
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