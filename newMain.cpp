#include "UserInterface.h"
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
 
    userInterface.uiLoop(); //no idea the syntax for C++ for executing an external class with a parameter. 
                            //java it's create an object of the class and then pass it a parameter to the desired function.
    return 0;
}
