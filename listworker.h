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

    void sortNames();
    void sortBirth();

    void removePerson(string name);


    friend bool equals (const Person &lhs, const string searchChoice);
    vector<Person> getPersons;
private:
    DataLayer data;

};

#endif // LISTWORKER_H
