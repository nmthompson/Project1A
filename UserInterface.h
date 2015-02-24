#include "Date.h"
#include "Assignment.h"
#ifndef USERINTERFACE_H
#define USERINTERFACE_H

using namespace std;

class UserInterface{
public:
	UserInterface(int choice){
	}
	void setChoice(int user_choice){
		choice = user_choice;
	}
	int getChoice(){
		return choice;
	}
	void uiLoop(int choice);

private:
	int choice;
};
#endif
