#ifndef LISTWORKER_H
#define LISTWORKER_H
#include "datalayer.h"
#include <iostream>
#include <vector>

struct person{
    string _name;
    char _gender;
    int _yearOfBirth;
    int _yearOfDeath;
};

using namespace std;

class ListWorker
{
public:
    ListWorker();
    void addNewPerson();
    void viewAll(vector<person>& per);
private:
    DataLayer data;
    vector<person> persons;
};

#endif // LISTWORKER_H
