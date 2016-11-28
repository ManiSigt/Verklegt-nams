#ifndef LISTWORKER_H
#define LISTWORKER_H
#include "datalayer.h"
#include <iostream>

using namespace std;

class ListWorker
{
public:
    ListWorker();
    void addNewPerson();
private:
    DataLayer data;
};

#endif // LISTWORKER_H
