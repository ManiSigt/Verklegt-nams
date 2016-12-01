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
    void addPerson();
    void mainMenu();
    void remove();
    void run();
    void save();
    void search();
    void searching();
    void select(string ch);
    void sorting();
    void view(int i);
    void viewAll();
    void yo();



private:
    bool runOn = true;
    ListWorker list;
    string getQuotes();

};

#endif // CLASSUI_H
