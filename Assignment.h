#include <string>
#include "Date.h"
class Assignment
{
public:
	string getDesc(){ return desc; }
	Date getDueDate(){ return due; }
	bool getStatus(){ return status; }
	void setDesc(string descr){ desc = descr; }
	void setDueDate(Date dueWhen){ due = dueWhen; }
	void setStatus(bool SetStatus){ status = SetStatus; }
	void MarkLate(){ late = true; }

private:
	bool status; //Complete or Incomplete
	string desc;
	Date due;
	bool late=false; //Switches to true after the due date passes.
};