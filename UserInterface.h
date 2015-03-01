#pragma once
#include "Date.h"
#include "StringTokenizer.h"
#include "Assignment.h"
#include "AssignmentManager.h"
#include <fstream>
#include <string>
#include <list>
#include <iostream>

using namespace std;

class UserInterface{
    //I think my syntax might be off and my logic as a result for these getters and setters
public:
    UserInterface(){}
    //void setChoice(int user_choice){
    //  choice = user_choice;
    //}
    //int getChoice(){
    //  return choice;
    //}
    //void setRead(char yes_or_no){
    //  y_or_n = yes_or_no;
    //}
    //char getRead(){
    //  return y_or_n;
    //}
    void uiLoop();
    void fileRead();
private:
    string file_read_in;
    string file_read_out;
};
