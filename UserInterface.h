#pragma once
#include "AssignmentManager.h"

using namespace std;

class UserInterface{
public:
    UserInterface(){}
 
    void uiLoop();
    void fileRead();
private:
    string file_read_in;
    string file_read_out;
};
