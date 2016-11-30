#ifndef LISTWORKER_H
#define LISTWORKER_H
#include "datalayer.h"
#include "person.h"
#include <iostream>
#include <string>

using namespace std;

class ListWorker
{
public:
    ListWorker();
    void addNewPerson(string name, char gender, int yearOfBirth, int yearOFDeath);
    void viewAll();


    void sortNames();
    void sortBirth();

    void removePerson();

    vector<Person> getPersons;
private:
    DataLayer data;

};

#endif // LISTWORKER_H
