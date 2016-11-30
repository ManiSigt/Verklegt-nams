#ifndef CLASSUI_H
#define CLASSUI_H
#include <iostream>
#include <string>
#include "listworker.h"
#include <algorithm>


using namespace std;

class classUI
{
public:
    classUI();
    void run();
    void select(string ch);
    void view();
    void searching();
    void addPerson();


private:
    ListWorker list;

};

#endif // CLASSUI_H
