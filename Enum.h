#pragma once
#include <string>
#include <iostream>
using namespace std;

enum status { Assigned, Completed, Late };
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
	catch (const exception& e){ // Error caught; the status isn't valid
		cout << e.what();
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