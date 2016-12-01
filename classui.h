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
    void run();
    void mainMenu();
    void select(string ch);
    void view(int i);
    void viewAll();
    void search();    // checks what option you took in searching and then asks for what keyword you want to search for, and looks it up in the database and prints it out
    void searching(); // prints out the options to search for in search then calls search.
    void remove();
    void addPerson();
    void save();
    void yo();



private:
    ListWorker list;
    string getQuotes();
    bool runOn = true;

};

#endif // CLASSUI_H
