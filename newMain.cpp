#include "Date.h"
#include "StringTokenizer.h"
#include "Assignment.h"
#include "UserInterface.h"
#include <fstream>
#include <list>
#include <iostream>
using namespace std;



int main()
{
	char y_or_n; // For assignment file prompt
	UserInterface userInterface;

	cout << "Do you want a file of assignments to be read? (Y/N)" << endl;
	cin >> y_or_n;
	if (toupper(y_or_n) == 'Y'){
		userInterface.fileRead(); //calls to fileRead class
	}
	cout << "Please select what you would like to do: " << endl;
	//Should just need to execute UI class function from main, all input/out will be handled by the UI class
	userInterface.uiLoop(); //no idea the syntax for C++ for executing an external class with a parameter. 
							//java it's create an object of the class and then pass it a parameter to the desired function.
	return 0;
}
