#include "UserInterface.h"
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
    userInterface.uiLoop(); //calls to uiloop interface logic
                           

    return 0;
}
