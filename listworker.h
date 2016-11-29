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
    void search();
<<<<<<< HEAD
    void sortNames();
    void sortBirth();
=======
    void removePerson();
>>>>>>> 01eb54e979057cfef67f47eaaf5cc9e0a4cfac3b

private:
    DataLayer data;
    vector<Person> getPersons;
};

#endif // LISTWORKER_H
