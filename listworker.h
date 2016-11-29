#ifndef LISTWORKER_H
#define LISTWORKER_H
#include "datalayer.h"
#include "person.h"
#include <iostream>

using namespace std;

class ListWorker
{
public:
    ListWorker();
    void addNewPerson();
    void viewAll();
private:
    DataLayer data;
    vector<Person> getPersons;
};

#endif // LISTWORKER_H
