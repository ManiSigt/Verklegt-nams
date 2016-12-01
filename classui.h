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
    void search();
    void searching();
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
