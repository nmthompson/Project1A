#include "UserInterface.h"
#include <iostream>
using namespace std;

int main()
{
    string y_or_n; // For assignment file prompt
    UserInterface userInterface;

    cout << "Do you want a file of assignments to be read? (Y/N)" << endl;
    getline(cin, y_or_n);
    if (toupper(y_or_n[0]) == 'Y'){
        userInterface.fileRead(); //calls to fileRead class
    }
    cout << "Please select what you would like to do: " << endl;
    userInterface.uiLoop(); //calls to uiloop interface logic
                           

    return 0;
}
