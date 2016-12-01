#ifndef CLASSUI_H
#define CLASSUI_H
#include <iostream>
#include <string>
#include "listworker.h"
#include <algorithm>

using namespace std;

class ClassUI
{
public:
    ClassUI();
    void addPerson();   //add a person to the database
    void mainMenu();    //this is the main menu for the program. It shows all commands to interact.
    void remove();
    void run();
    void save();
    void search();              // checks what option you took in searching and then asks for what keyword you want to search for, and looks it up in the database and prints it out
    void searching();           // prints out the options to search for in search then calls search.
    void select(string ch);
    void sorting();             //?
    void view(int i);           //this prints out a single  scientist from the vector.
    void viewAll();             //This prints out the whole list of scientists, Name, Gender, Birth year, Death year and a comment.
    void yo();                  //Secret phase
private:
    bool runOn = true;
    ListWorker list;
    string getQuotes();

};

#endif // CLASSUI_H
